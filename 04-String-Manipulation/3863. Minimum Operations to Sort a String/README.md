<h2><a href="https://leetcode.com/problems/minimum-operations-to-sort-a-string">3863. Minimum Operations to Sort a String</a></h2>

<p data-end="244" data-start="156">You are given a string <code>s</code> consisting of lowercase English letters.</p>

<p>In one operation, you can select any <strong><span data-keyword="substring-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_t_" data-state="closed" class="">substring</button></span></strong> of <code>s</code> that is <strong>not</strong> the entire string and <strong>sort</strong> it in <strong>non-descending alphabetical</strong> order.</p>

<p>Return the <strong>minimum</strong> number of operations required to make <code>s</code> sorted in <strong>non-descending</strong> order. If it is not possible, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "dog"</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<ul>
	<li>Sort substring <code>"og"</code> to <code>"go"</code>.</li>
	<li>Now, <code>s = "dgo"</code>, which is sorted in ascending order. Thus, the answer is 1.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "card"</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Sort substring <code>"car"</code> to <code>"acr"</code>, so <code>s = "acrd"</code>.</li>
	<li>Sort substring <code>"rd"</code> to <code>"dr"</code>, making <code>s = "acdr"</code>, which is sorted in ascending order. Thus, the answer is 2.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "gf"</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>It is impossible to sort <code>s</code> under the given constraints. Thus, the answer is -1.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>


---

# 🛍️ Minimum-Operations-to-Sort-a-String | Explained

## Approach 1: Greedy Extremes Positioning (Boundary Analysis)

### Intuition
Imagine you have a row of books on a narrow shelf, but your hands are only wide enough to pull out and reorder at most $n - 1$ books at a time (either from the leftmost end or the rightmost end). Because you can never pick up all $n$ books simultaneously, the only way to get the entire shelf sorted is by shifting the absolute smallest book to the front or the absolute largest book to the back.

- If the books are already sorted, you do nothing (**0 operations**).
- If there are only 2 books and they are inverted, you can only pick up subarrays of size at most $2 - 1 = 1$. Sorting 1 book does nothing, making it impossible (**-1**).
- If the smallest element is already at index `0`, sorting the remaining suffix of length $n - 1$ completely sorts the entire string (**1 operation**). The same logic applies if the largest element is already at index `n - 1`.
- If either the minimum or maximum element is somewhere in the middle, you can pull it to its target boundary in one operation, and then sort the rest in the second operation (**2 operations**).
- In the worst-case scenario where the maximum element is trapped at index `0` and the minimum element is trapped at index `n - 1`, neither boundary element can reach its proper place in a single move. You need one intermediate move to dislodge one of them into the middle, a second move to put it on its correct boundary, and a third move to sort the rest (**3 operations**).

---

### Algorithm Visualized

```mermaid
flowchart TD
    A[Start: String s of length n] --> B{Is s already sorted?}
    B -- Yes --> R0[Return 0]
    B -- No --> C{Is n == 2?}
    C -- Yes --> RNeg[Return -1]
    C -- No --> D{s[0] == min OR s[n-1] == max?}
    D -- Yes --> R1[Return 1]
    D -- No --> E{Is min or max in s[1 ... n-2]?}
    E -- Yes --> R2[Return 2]
    E -- No --> R3[Return 3: s[0]==max AND s[n-1]==min]
```

---

### Approach

1. **Find Extremes**: Traverse the string to find the global minimum character (`mn`) and global maximum character (`mx`).
2. **Check Base Case (Already Sorted)**: If the string is already non-decreasing, no operations are required; return `0`.
3. **Check Impossibility ($n = 2$)**: An operation can sort any proper prefix or suffix of length up to $n - 1$. For $n = 2$, $n - 1 = 1$. Sorting a substring of length 1 cannot reorder two unsorted characters; return `-1`.
4. **Check 1-Operation Case**:
   - If `s[0] == mn`, sort the suffix `s[1 ... n-1]`.
   - If `s[n - 1] == mx`, sort the prefix `s[0 ... n-2]`.
   - Either scenario sorts the whole string in `1` operation.
5. **Check 2-Operation Case**:
   - If either `mn` or `mx` lies strictly inside the middle region (`1 <= i <= n - 2`), we can pull `mn` to index `0` (or `mx` to index `n - 1`) in the first operation, reducing the problem to the 1-operation case. Hence, return `2`.
6. **Fallback to 3-Operation Case**:
   - If neither condition holds, `s[0]` must be the maximum character and `s[n - 1]` must be the minimum character. It takes 1 move to get an extreme into the middle, 1 move to get it to its destination end, and 1 final move to sort the opposite end. Return `3`.

---

### Detailed Code Analysis

- **Lines 4–9**:
  ```cpp
  char mx = 'a', mn = 'z';
  int n = s.length();
  for (int i = 0; i < n; i++){
      mx = max(mx, s[i]);
      mn = min(mn, s[i]);
  }
  ```
  Initializes `mx` to `'a'` and `mn` to `'z'`. A single linear pass updates both variables to find the smallest and largest characters present in `s`.

- **Lines 10–12**:
  ```cpp
  if (ranges::is_sorted(s)){
      return 0;
  }
  ```
  Uses C++20 `std::ranges::is_sorted` to inspect the string. If the string is already sorted, no operations are needed.

- **Lines 13–15**:
  ```cpp
  if (n == 2){
      return -1;
  }
  ```
  Since the string is not sorted and has length 2, the only permissible proper subsegments have length $\le 1$. Reordering a length-1 substring cannot change the relative order of the two characters. Therefore, sorting is impossible.

- **Lines 16–18**:
  ```cpp
  if (s[0] == mn || s[n - 1] == mx){
      return 1;
  }
  ```
  If the minimum character is already at the first index, applying the operation to the suffix `s[1 ... n-1]` sorts the entire string. Similarly, if the maximum character is at the last index, applying the operation to the prefix `s[0 ... n-2]` sorts the entire string.

- **Lines 19–23**:
  ```cpp
  for (int i = 1; i < n - 1; i++){
      if (s[i] == mn || s[i] == mx){
          return 2;
      }
  }
  ```
  Iterates strictly across the interior indices `[1, n - 2]`. If a global minimum exists here, sorting a proper prefix containing it moves `mn` to index `0`, after which a second operation on the suffix `s[1 ... n-1]` completes the sort. Symmetrically, if `mx` is here, sorting a suffix containing it moves `mx` to index `n - 1`, after which a second operation on prefix `s[0 ... n-2]` completes the sort.

- **Line 24**:
  ```cpp
  return 3;
  ```
  If all checks fail, the string has `s[0] == mx` and `s[n - 1] == mn`. Moving `mn` directly to index `0` or `mx` directly to index `n - 1` is impossible in one step because any proper prefix excludes `s[n - 1]` and any proper suffix excludes `s[0]`. Thus, 3 operations are strictly necessary and sufficient.

---

### Code

```cpp
class Solution {
public:
    int minOperations(string s){
        char mx = 'a', mn = 'z';
        int n = s.length();
        for (int i = 0; i < n; i++){
            mx = max(mx, s[i]);
            mn = min(mn, s[i]);
        }
        if (ranges::is_sorted(s)){
            return 0;
        }
        if (n == 2){
            return -1;
        }
        if (s[0] == mn || s[n - 1] == mx){
            return 1;
        }
        for (int i = 1; i < n - 1; i++){
            if (s[i] == mn || s[i] == mx){
                return 2;
            }
        }
        return 3;
    }
};
```

---

### Complexity

- **Time Complexity:** $\mathcal{O}(n)$
  - Finding `mn` and `mx` takes $\mathcal{O}(n)$ time.
  - Checking `ranges::is_sorted(s)` takes $\mathcal{O}(n)$ time.
  - The loop scanning `s[1 ... n-2]` takes $\mathcal{O}(n)$ time.
  - Total time complexity is strictly linear, $\mathcal{O}(n)$.

- **Space Complexity:** $\mathcal{O}(1)$
  - The algorithm uses only primitive variables (`mx`, `mn`, `n`, `i`) and performs in-place inspections without allocating any additional memory.

---

## 🕵️‍♂️ Follow-up Questions (Optional)

1. **What if the allowed operation can sort any subarray of fixed length $k < n$, rather than any proper prefix/suffix of length $n-1$?**
   - If operations are restricted to windows of fixed length $k$, this transforms into a permutation cycle and graph reachability problem. Elements can only swap positions if their index difference modulo $\gcd(k-1, \dots)$ allows it, and parity constraints may prevent reaching a sorted state altogether.

2. **Can the upper bound of operations ever exceed 3 for any string length $n \ge 3$?**
   - No. For $n \ge 3$, the maximum number of operations is strictly capped at 3. In the worst case where $s[0] = \text{max}$ and $s[n-1] = \text{min}$:
     1. Sort suffix $s[1 \dots n-1]$: moves $\text{min}$ to index $1$.
     2. Sort prefix $s[0 \dots n-2]$: moves $\text{min}$ to index $0$ and $\text{max}$ to index $n-2$.
     3. Sort suffix $s[1 \dots n-1]$: moves $\text{max}$ to index $n-1$ and sorts everything in between.
   - Therefore, the answer is always bounded within $\{0, 1, 2, 3\}$ for $n \ge 3$.