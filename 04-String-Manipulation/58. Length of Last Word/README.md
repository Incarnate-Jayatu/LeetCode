<h2><a href="https://leetcode.com/problems/length-of-last-word">58. Length of Last Word</a></h2>

<p>Given a string <code>s</code> consisting of words and spaces, return <em>the length of the <strong>last</strong> word in the string.</em></p>

<p>A <strong>word</strong> is a maximal <span data-keyword="substring-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_s_" data-state="closed" class="">substring</button></span> consisting of non-space characters only.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "Hello World"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The last word is "World" with length 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "   fly me   to   the moon  "
<strong>Output:</strong> 4
<strong>Explanation:</strong> The last word is "moon" with length 4.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "luffy is still joyboy"
<strong>Output:</strong> 6
<strong>Explanation:</strong> The last word is "joyboy" with length 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of only English letters and spaces <code>' '</code>.</li>
	<li>There will be at least one word in <code>s</code>.</li>
</ul>


---

# 🛍️ Length-of-Last-Word | Explained

## Approach 1: Reverse Traversal with State Counting

### Intuition
Imagine reading a book from the very last page backward to find the length of the final chapter. Before you reach the actual words of the final chapter, you might encounter some empty trailing blank pages. You ignore those blank pages until you hit text. Once you start counting the characters of that final chapter, the very first blank page you encounter afterward signals that the chapter has ended, and you can immediately stop reading.



### Approach
1. **Initialize a counter**: Start with `count = 0` to track the number of characters in the last word.
2. **Traverse backwards**: Iterate from the last index (`s.length() - 1`) down to index `0`.
3. **Handle non-space characters**: When encountering a non-space character (`s[i] != ' '`), increment `count`.
4. **Handle space characters**:
   - If `s[i] == ' '` and `count > 0`, it means we have already processed the last word and have now encountered the whitespace separating it from preceding words. Return `count` immediately (early exit).
   - If `s[i] == ' '` and `count == 0`, it means we are still skipping trailing spaces at the end of the string. Continue iterating.
5. **Handle boundary termination**: If the loop finishes without hitting an early exit (e.g., the string consists of a single word with no leading spaces), return `count`.

### Detailed Code Analysis
- **Lines 6 (`int count = 0;`)**: Allocates an integer accumulator to store the character count of the last word.
- **Lines 7 (`for (int i = s.length() - 1; i >= 0; i--)`)**: Initiates a reverse `for` loop. Traversing from right to left ensures we hit the target word first, eliminating the need to process the entire string.
- **Lines 9–12 (`if (s[i] != ' ') { count++; }`)**: Checks if the current character is part of a word. If true, increments `count`.
- **Lines 13–16 (`else if (s[i] == ' ' && count > 0) { return count; }`)**: Identifies the delimiter immediately preceding the last word. The condition `count > 0` prevents premature termination while scanning through trailing whitespaces.
- **Line 18 (`return count;`)**: Serves as the fallback return statement when the string begins with the last word (e.g., `"Hello"` or `"   Hello"` where the loop reaches `i = -1` while counting).

### Code
```cpp
class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        int count = 0;
        for (int i = s.length() - 1; i >= 0; i--) 
        {
            if (s[i] != ' ') 
            {
                count++;
            }
            else if (s[i] == ' ' && count > 0) 
            {
                return count;
            }
        }
        return count;
    }
};
```

### Complexity
- **Time:** $\mathcal{O}(N)$ in the worst case (where $N$ is the length of string $s$), when the entire string must be traversed (e.g., a single word or all spaces). In best/average cases with trailing words, it terminates early in $\mathcal{O}(K)$ time, where $K$ is the length of the trailing spaces plus the last word.
- **Space:** $\mathcal{O}(1)$ auxiliary space. The algorithm operates in-place using two primitive integer variables (`count` and `i`).

## 🕵️‍♂️ Follow-up Questions (Optional)

1. **How would you solve this using standard library two-pointer/iterator utilities in C++?**
   - You can use reverse iterators with `std::find_if` to find the first non-space character from the end, and then find the next space character from that position, calculating the distance between the two iterators.

2. **What happens if the input string contains only whitespace characters (e.g., `"     "`)?**
   - The condition `s[i] != ' '` is never met, `count` remains `0`, the loop terminates, and line 18 correctly returns `0`.
