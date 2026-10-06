<h2><a href="https://leetcode.com/problems/minimum-add-to-make-parentheses-valid">921. Minimum Add to Make Parentheses Valid</a></h2>

<p>A parentheses string is valid if and only if:</p>

<ul>
	<li>It is the empty string,</li>
	<li>It can be written as <code>AB</code> (<code>A</code> concatenated with <code>B</code>), where <code>A</code> and <code>B</code> are valid strings, or</li>
	<li>It can be written as <code>(A)</code>, where <code>A</code> is a valid string.</li>
</ul>

<p>You are given a parentheses string <code>s</code>. In one move, you can insert a parenthesis at any position of the string.</p>

<ul>
	<li>For example, if <code>s = "()))"</code>, you can insert an opening parenthesis to be <code>"(<strong>(</strong>)))"</code> or a closing parenthesis to be <code>"())<strong>)</strong>)"</code>.</li>
</ul>

<p>Return <em>the minimum number of moves required to make </em><code>s</code><em> valid</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "())"
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "((("
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'('</code> or <code>')'</code>.</li>
</ul>


---

# 🛍️ Minimum-Add-to-Make-Parentheses-Valid | Explained

## Approach 1: Balance Tracking (Space-Optimized Stack)

### Intuition
Think of parentheses matching like a paired ballroom dance. Every opening parenthesis `(` is a dancer stepping onto the floor waiting for a partner. Every closing parenthesis `)` is a dancer looking to pair up immediately.

- When a `(` enters, they wait in the queue.
- When a `)` enters, if someone is already waiting (`open_needed > 0`), they pair up and the waiting queue decreases by one.
- However, if a `)` enters and the floor is completely empty (`open_needed == 0`), that dancer is stranded. A future `(` cannot travel back in time to pair with them. Therefore, you are permanently forced to supply an extra `(` specifically for them (`close_needed++`).

At the end of the dance, any stranded dancers who arrived without a preceding partner (`close_needed`) plus any dancers still waiting on the floor who never found a partner (`open_needed`) represent the absolute minimum number of additions required to achieve perfect validity.

### Algorithm Visualized

```mermaid
flowchart TD
    Start([Start Loop: For each char c in s]) --> CheckChar{c == '(' ?}
    
    CheckChar -- Yes --> IncOpen[open_needed++]
    
    CheckChar -- No --> CheckAvailable{open_needed > 0 ?}
    CheckAvailable -- Yes --> DecOpen[open_needed--<br/><i>Matched with previous '('</i>]
    CheckAvailable -- No --> IncClose[close_needed++<br/><i>Unmatched ')' needs a '('</i>]
    
    IncOpen --> NextChar[Next Character]
    DecOpen --> NextChar
    IncClose --> NextChar
    
    NextChar --> IsEnd{More characters?}
    IsEnd -- Yes --> CheckChar
    IsEnd -- No --> ReturnResult([Return open_needed + close_needed])
```

### Approach
A standard validation problem often uses an explicit `std::stack<char>`. However, because there is only one type of bracket (`(` and `)`), we do not need to store the actual characters. We only need to track the count of unmatched brackets.

1. **State Tracking**:
   - `open_needed`: Tracks the running count of opening brackets `(` that have not yet been neutralized by a closing bracket. (These currently lack a matching `)`).
   - `close_needed`: Tracks the running count of closing brackets `)` that appeared when no opening bracket was available to match. (These permanently lack a matching `(`).
2. **Linear Scan**:
   - Iterate through the string character by character.
   - If the character is `'('`, increment `open_needed` as it is an unmatched open parenthesis.
   - If the character is `')'`:
     - If `open_needed > 0`, greedily match this `')'` with the most recent unmatched `'('` by decrementing `open_needed`.
     - If `open_needed == 0`, this `')'` has no matching `'('` before it. It can never be matched by future characters, so increment `close_needed`.
3. **Aggregate Result**:
   - The total additions required is the sum of leftover opening brackets that never got closed (`open_needed`) and closing brackets that never got opened (`close_needed`).

### Detailed Code Analysis

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        // Line 4: open_needed tracks unmatched '(' available for future ')'
        int open_needed = 0;
        // Line 5: close_needed tracks unmatched ')' that occurred without any preceding '('
        int close_needed = 0;
        
        // Line 6: Iterate through each character of the string s by value
        for (char c : s){
            // Line 7-9: If an opening bracket is found, increment available opens
            if (c == '('){
                open_needed++;
            } 
            // Line 10: The character must be ')' (per problem constraints)
            else{
                // Line 11-13: Greedily cancel out an existing '(' if available
                if (open_needed > 0){
                    open_needed--;
                } 
                // Line 14-16: No '(' available to balance this ')'. 
                // We must inject an open parenthesis before it.
                else{
                    close_needed++;
                }
            }
        }
        // Line 19: Total insertions = unmatched '(' requiring ')' + unmatched ')' requiring '('
        return open_needed + close_needed;
    }
};
```

- **Lines 4–5 (`int open_needed = 0; int close_needed = 0;`)**: Primitive counters replace an auxiliary stack data structure. `open_needed` represents stack size; `close_needed` represents elements that attempted to pop from an empty stack.
- **Lines 6–9**: Each `'('` adds $+1$ to our open balance.
- **Lines 11–13**: When a `')'` appears, we greedily prioritize matching it with the nearest available `'('`. This decrements our balance by $1$.
- **Lines 14–16**: When `open_needed == 0`, balance cannot go negative without violating prefix validity. Instead of letting balance drop to $-1$, we capture this deficit in `close_needed`.
- **Line 19**: Returns the total deficit.

### Code
```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0;
        int close_needed = 0;
        for (char c : s){
            if (c == '('){
                open_needed++;
            } 
            else{
                if (open_needed > 0){
                    open_needed--;
                } 
                else{
                    close_needed++;
                }
            }
        }
        return open_needed + close_needed;
    }
};
```

### Complexity
- **Time:** $\mathcal{O}(N)$, where $N$ is the length of string `s`. The algorithm executes a single pass over the string with constant $\mathcal{O}(1)$ operations inside the loop.
- **Space:** $\mathcal{O}(1)$ auxiliary space. Only two integer variables (`open_needed` and `close_needed`) are allocated, eliminating the $\mathcal{O}(N)$ memory overhead of a traditional stack.

---

## 🕵️‍♂️ Follow-up Questions

### 1. What if the input string contains multiple bracket types like `()`, `[]`, and `{}`?
If multiple bracket types are introduced (e.g., `([)]`), simple integer counters will **not** work because the relative order and nesting hierarchy matter (`([)]` has equal counts of each type but is structurally invalid). In that scenario, you must revert to an explicit `std::stack<char>` to track the exact identity and order of unmatched opening brackets, resulting in $\mathcal{O}(N)$ time and $\mathcal{O}(N)$ space complexity.

### 2. Can all the necessary additions be made strictly at the start or end of the string?
Yes. Every unmatched closing bracket recorded by `close_needed` can be fixed by prepending `close_needed` opening brackets at index $0$. Every unmatched opening bracket recorded by `open_needed` can be fixed by appending `open_needed` closing brackets at the very end of the string. Thus, the minimum additions do not require complex middle-string insertions; prefixing and suffixing are sufficient.