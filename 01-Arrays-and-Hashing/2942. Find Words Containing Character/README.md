<h2><a href="https://leetcode.com/problems/find-words-containing-character">2942. Find Words Containing Character</a></h2>

<p>You are given a <strong>0-indexed</strong> array of strings <code>words</code> and a character <code>x</code>.</p>

<p>Return <em>an <strong>array of indices</strong> representing the words that contain the character </em><code>x</code>.</p>

<p><strong>Note</strong> that the returned array may be in <strong>any</strong> order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["leet","code"], x = "e"
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> "e" occurs in both words: "l<strong><u>ee</u></strong>t", and "cod<u><strong>e</strong></u>". Hence, we return indices 0 and 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["abc","bcd","aaaa","cbc"], x = "a"
<strong>Output:</strong> [0,2]
<strong>Explanation:</strong> "a" occurs in "<strong><u>a</u></strong>bc", and "<u><strong>aaaa</strong></u>". Hence, we return indices 0 and 2.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["abc","bcd","aaaa","cbc"], x = "z"
<strong>Output:</strong> []
<strong>Explanation:</strong> "z" does not occur in any of the words. Hence, we return an empty array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>x</code> is a lowercase English letter.</li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>


---

# 🛍️ Find-Words-Containing-Character | Explained

## Approach 1: Linear Scan with Early Termination
### Intuition
Imagine you have a stack of labeled envelopes, and you are asked to write down the index numbers of all envelopes that contain a specific letter stamp (character `x`). You do not need to count how many times the stamp appears inside an envelope; the moment you open an envelope and see even one matching stamp, you immediately record its index, set the envelope aside, and move to the next one. 

This approach mirrors that real-world process: we iterate through the list of words sequentially, and for each word, we inspect its characters one by one. The key optimization is the **early break**—as soon as a match is detected, there is no need to scan the remainder of that word.

### Algorithm Visualized
```mermaid
flowchart TD
    Start([Start]) --> Init[Initialize empty vector ans<br/>n = words.size]
    Init --> LoopWords{i < n?}
    
    LoopWords -- Yes --> WordLoop[Select word words[i]]
    LoopWords -- No --> Return[Return ans]
    
    WordLoop --> LoopChars{More characters<br/>in words[i]?}
    
    LoopChars -- Yes --> CheckChar{char == x?}
    CheckChar -- Yes --> Record[ans.push_back i]
    Record --> Break[Break inner loop]
    Break --> NextWord[i++]
    NextWord --> LoopWords
    
    CheckChar -- No --> LoopChars
    LoopChars -- No --> NextWord
    Return --> End([End])
```

### Approach
1. **Initialize Result Storage:** Create an empty dynamic array `ans` to store the 0-based indices of words that contain the character `x`.
2. **Iterate Through Words:** Traverse the input array `words` from index `0` up to `n - 1` using an indexed `for` loop so the index `i` is readily available.
3. **Scan Each Word:** For each word `words[i]`, iterate through its individual characters using a range-based `for` loop.
4. **Conditional Match & Early Exit:** 
   - Compare the current character against target `x`.
   - If a match is found: append `i` to `ans`, then immediately issue a `break` statement to terminate the character-level loop. This prevents redundant checks and guarantees that each word index `i` is added at most once.
5. **Return Result:** Once all words have been examined, return the `ans` vector.

### Detailed Code Analysis
- `vector<int> ans;`: Initializes an empty standard `std::vector<int>` to store the indices of words matching the criterion.
- `int n = words.size();`: Caches the number of elements in `words` to avoid repeated calls to `.size()` inside the loop termination condition.
- `for (int i = 0; i < n; i++)`: Outer loop iterating over the collection. Index `i` serves double duty: locating the current word `words[i]` and serving as the actual value to push into `ans`.
- `for (auto it : words[i])`: Inner range-based loop. Copies each character of `words[i]` into the variable `it` one at a time. While `auto it` creates a copy of a `char` (which is trivial since `sizeof(char) == 1`), `char it` or `const char it` would be functionally identical.
- `if (it == x)`: Evaluates whether the current character matches the search target `x`.
- `ans.push_back(i);`: Appends the current word index to the end of `ans`. Because of the subsequent `break`, duplicate additions of index `i` for words containing multiple occurrences of `x` are prevented.
- `break;`: Halts execution of the inner loop immediately after finding the first occurrence of `x`, skipping the evaluation of any remaining characters in `words[i]` and advancing the outer loop to index `i + 1`.
- `return ans;`: Returns the populated vector containing the matching indices in ascending order.

### Code
```cpp
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (auto it : words[i]) {
                if (it == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};
```

### Complexity
- **Time:** $\mathcal{O}(N \times L)$, where $N$ is the number of words in `words` (`words.size()`) and $L$ is the maximum length of a string in `words`. In the worst-case scenario (where a word does not contain `x`, or `x` is the very last character), the inner loop visits every character in the string. With early termination, the average runtime is strictly better than the worst case when `x` appears early within the strings.
- **Space:** $\mathcal{O}(1)$ auxiliary space (excluding the output vector). The space required to store the answer is $\mathcal{O}(N)$ in the worst case (when every word contains `x`), but this is output space dictated by the problem statement.

## 🕵️‍♂️ Follow-up Questions

### 1. How does this compare to using `std::string::find` in C++?
Instead of an explicit nested loop, you can write:
```cpp
if (words[i].find(x) != string::npos) {
    ans.push_back(i);
}
```
Under the hood, `std::string::find` performs an optimized linear scan (often utilizing SIMD or `memchr` via assembly optimizations depending on the standard library implementation). It shares the same asymptotic time complexity $\mathcal{O}(N \times L)$, but typically executes with a lower constant factor.

### 2. What if the character query `x` changes frequently, but the list `words` is immutable?
If the word list is static and queried many times with different characters, precomputing a bitmask for each word (where bit `c - 'a'` is set if the character exists in the word) allows answering each query in $\mathcal{O}(N)$ bitwise checks, entirely eliminating the string length factor $L$ during query time.