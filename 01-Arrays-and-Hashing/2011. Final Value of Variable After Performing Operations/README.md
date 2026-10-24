<h2><a href="https://leetcode.com/problems/final-value-of-variable-after-performing-operations">2011. Final Value of Variable After Performing Operations</a></h2>

<p>There is a programming language with only <strong>four</strong> operations and <strong>one</strong> variable <code>X</code>:</p>

<ul>
	<li><code>++X</code> and <code>X++</code> <strong>increments</strong> the value of the variable <code>X</code> by <code>1</code>.</li>
	<li><code>--X</code> and <code>X--</code> <strong>decrements</strong> the value of the variable <code>X</code> by <code>1</code>.</li>
</ul>

<p>Initially, the value of <code>X</code> is <code>0</code>.</p>

<p>Given an array of strings <code>operations</code> containing a list of operations, return <em>the <strong>final </strong>value of </em><code>X</code> <em>after performing all the operations</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> operations = ["--X","X++","X++"]
<strong>Output:</strong> 1
<strong>Explanation:</strong>&nbsp;The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> operations = ["++X","++X","X++"]
<strong>Output:</strong> 3
<strong>Explanation: </strong>The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> operations = ["X++","++X","--X","X--"]
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= operations.length &lt;= 100</code></li>
	<li><code>operations[i]</code> will be either <code>"++X"</code>, <code>"X++"</code>, <code>"--X"</code>, or <code>"X--"</code>.</li>
</ul>


---

# 🛍️ Final-Value-of-Variable-After-Performing-Operations | Explained

## Approach 1: Linear Simulation via String Literal Matching
### Intuition
Think of this problem like keeping score on a tally counter or adjusting an elevator's floor. You start at baseline zero. You are handed a sequence of cards, where each card gives a specific command: either increment the counter by one or decrement it by one. 

Because prefix and postfix operators (`++X` vs `X++`, `--X` vs `X--`) both produce the exact same net effect on the variable by the time the next statement executes, their distinction does not matter for the final tally. We simply iterate through the instructions, evaluate the intent of each command, and adjust our counter accordingly.

### Algorithm Visualized

```mermaid
flowchart TD
    Start([Start: x = 0]) --> LoopInit[Iterate i from 0 to operations.size - 1]
    LoopInit --> CheckOp{Check operations[i]}
    
    CheckOp -- "++X" or "X++" --> Inc[x = x + 1]
    CheckOp -- "--X" or "X--" --> Dec[x = x - 1]
    
    Inc --> NextIter{More operations?}
    Dec --> NextIter
    
    NextIter -- Yes --> LoopInit
    NextIter -- No --> ReturnVal([Return x])
```

### Approach
1. **Initialize Accumulator:** Declare an integer variable `x = 0` to store the cumulative value.
2. **Iterate Across Commands:** Loop from index `0` up to `operations.size() - 1` to inspect each operation sequentially.
3. **Branching Condition:**
   - Check if the current operation matches either `"++X"` or `"X++"`. If true, increase `x` by `1`.
   - Otherwise, check if it matches `"--X"` or `"X--"`. If true, decrease `x` by `1`.
4. **Return Result:** After the loop finishes evaluating all commands, return the final value stored in `x`.

### Detailed Code Analysis
- **Line 4 (`int x=0;`):** Initializes the state variable to zero as required by the problem constraints.
- **Line 5 (`for(int i=0; i<operations.size(); i++)`):** Standard indexed traversal over the `std::vector<string>`. This visits every string element from index `0` through `N - 1`.
- **Lines 6–7 (`if(operations[i] == "++X" || operations[i] == "X++") x+=1;`):**
  - *Compiler Note:* In the submitted snippet, unquoted identifiers (`++X` and `X++`) were written, which triggers a compilation error because `X` is undefined and cannot be compared to a `std::string`. The algorithmic intention is to perform equality checks against the string literals `"++X"` and `"X++"`.
  - In C++, the `==` operator on `std::string` performs a character-by-character comparison. If either increment pattern is matched, `x` is incremented by 1.
- **Lines 8–9 (`else if(operations[i] == "--X" || operations[i] == "X--") x-=1;`):** Evaluates whether the operation represents a decrement command (`"--X"` or `"X--"`). If so, it reduces `x` by 1.
- **Line 11 (`return x;`):** Returns the final calculated integer after consuming all commands.

### Code
```cpp
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "++X" || operations[i] == "X++") {
                x += 1;
            } else if (operations[i] == "--X" || operations[i] == "X--") {
                x -= 1;
            }
        }
        return x;
    }
};
```

### Complexity
- **Time Complexity:** $\mathcal{O}(N)$ where $N$ is the number of elements in `operations`. Each string has a fixed length of 3 characters (`L = 3`), making each string comparison an $\mathcal{O}(1)$ operation. Thus, the total time across $N$ elements is $\mathcal{O}(N \times 3) = \mathcal{O}(N)$.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space. The calculation is done in-place using a single primitive integer variable `x`, requiring no extra heap or dynamic memory allocations.

---

## 🕵️‍♂️ Follow-up Questions (Optional)

1. **Can we optimize string comparisons to run faster at the CPU level?**
   - **Answer:** Yes. Notice that every valid operation (`"++X"`, `"X++"`, `"--X"`, `"--X"`) has its unique operator character at index `1`:
     - `"++X"[1] == '+'`
     - `"X++"[1] == '+'`
     - `"--X"[1] == '-'`
     - `"X--"[1] == '-'`
   - Instead of running full string comparisons, inspecting just `operations[i][1]` avoids multi-byte string comparisons:
     ```cpp
     x += (operations[i][1] == '+') ? 1 : -1;
     ```
   - This eliminates branching penalties and string comparison overhead completely.

2. **Can this problem be solved using standard library algorithms in modern C++?**
   - **Answer:** Yes, via `std::accumulate`:
     ```cpp
     return std::accumulate(operations.begin(), operations.end(), 0,
         [](int acc, const string& op) {
             return acc + (op[1] == '+' ? 1 : -1);
         });
     ```
   - This produces cleaner, more idiomatic functional code while maintaining $\mathcal{O}(N)$ time and $\mathcal{O}(1)$ auxiliary space.