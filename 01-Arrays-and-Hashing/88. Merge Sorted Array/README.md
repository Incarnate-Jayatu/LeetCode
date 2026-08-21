<h2><a href="https://leetcode.com/problems/merge-sorted-array">88. Merge Sorted Array</a></h2>

<p>You are given two integer arrays <code>nums1</code> and <code>nums2</code>, sorted in <strong>non-decreasing order</strong>, and two integers <code>m</code> and <code>n</code>, representing the number of elements in <code>nums1</code> and <code>nums2</code> respectively.</p>

<p><strong>Merge</strong> <code>nums1</code> and <code>nums2</code> into a single array sorted in <strong>non-decreasing order</strong>.</p>

<p>The final sorted array should not be returned by the function, but instead be <em>stored inside the array </em><code>nums1</code>. To accommodate this, <code>nums1</code> has a length of <code>m + n</code>, where the first <code>m</code> elements denote the elements that should be merged, and the last <code>n</code> elements are set to <code>0</code> and should be ignored. <code>nums2</code> has a length of <code>n</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
<strong>Output:</strong> [1,2,2,3,5,6]
<strong>Explanation:</strong> The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [<u>1</u>,<u>2</u>,2,<u>3</u>,5,6] with the underlined elements coming from nums1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [1], m = 1, nums2 = [], n = 0
<strong>Output:</strong> [1]
<strong>Explanation:</strong> The arrays we are merging are [1] and [].
The result of the merge is [1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums1 = [0], m = 0, nums2 = [1], n = 1
<strong>Output:</strong> [1]
<strong>Explanation:</strong> The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums1.length == m + n</code></li>
	<li><code>nums2.length == n</code></li>
	<li><code>0 &lt;= m, n &lt;= 200</code></li>
	<li><code>1 &lt;= m + n &lt;= 200</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums1[i], nums2[j] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up: </strong>Can you come up with an algorithm that runs in <code>O(m + n)</code> time?</p>


---

# 🛍️ Merge-Sorted-Array | Explained

## Approach 1: Reverse Three-Pointer (In-Place Merge)

### Intuition
When merging two sorted arrays into one, the primary challenge is avoiding the overwrite of unprocessed elements in the destination array (`nums1`). If you start merging from the front (index `0`), placing a smaller element from `nums2` into `nums1` would overwrite the existing element in `nums1`, requiring you to shift elements or allocate an auxiliary array.

A real-world analogy is packing a moving truck. If you have essential boxes already stacked in the front half of the truck and another batch waiting on the curb, trying to organize them starting from the front forces you to keep moving boxes out of the way. Instead, you start stacking the largest boxes into the empty space at the very back of the truck. 

Because `nums1` has an allocated capacity of `m + n` with empty buffer space (zeros) at the tail, we can work backward. By placing the largest elements at the end of `nums1` first, we guarantee that we never overwrite an element in `nums1` before we have read and processed it.



### Approach
1. **Initialize Three Pointers:**
   - `p1`: Points to the last valid (non-zero) element in `nums1` (`m - 1`).
   - `p2`: Points to the last element in `nums2` (`n - 1`).
   - `p`: Points to the very last index of the combined buffer in `nums1` (`m + n - 1`).
2. **Backwards Comparison Loop:**
   - Compare `nums1[p1]` and `nums2[p2]`.
   - Write the larger value to `nums1[p]`.
   - Decrement the pointer of whichever array contributed the value (`p1` or `p2`), and decrement the write pointer `p`.
   - Repeat until either `p1` or `p2` falls below index `0`.
3. **Flush Remaining Elements:**
   - If `nums2` still has elements remaining (`p2 >= 0`), copy them directly into `nums1` from index `p` down to `0`.
   - If `nums1` still has elements remaining (`p1 >= 0`), no action is needed because they are already in their correct sorted positions at the front of `nums1`.

### Detailed Code Analysis

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Line 4-6: Pointers initialization
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
```
- `p1` tracks the active read position in the original data portion of `nums1`.
- `p2` tracks the active read position in `nums2`.
- `p` tracks the active write position at the end of the destination vector `nums1`.

```cpp
        // Line 8: Main merge loop
        while (p1 >= 0 && p2 >= 0) {
            // Lines 9-15: Choose the largest remaining element
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            // Line 16: Move the write pointer leftward
            p--;
        }
```
- The `while` loop runs as long as both vectors have elements left to compare.
- If `nums1[p1] > nums2[p2]`, we place `nums1[p1]` at `nums1[p]` and decrement `p1`.
- If `nums2[p2] >= nums1[p1]`, we place `nums2[p2]` at `nums1[p]` and decrement `p2`.
- `p--` advances the write pointer toward the beginning of the array after every assignment.

```cpp
        // Lines 19-23: Handle residual elements in nums2
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};
```
- If `p2 >= 0` after the first loop terminates, it means all elements originally in `nums1` were larger and have already been shifted to the right. The remaining elements in `nums2` are smaller than all elements placed so far and are copied directly into the remaining slots.
- **Why is there no `while (p1 >= 0)` loop?** If `p2 < 0` first, all elements of `nums2` have been integrated. The remaining elements in `nums1` from index `0` to `p1` are already in their correct sorted locations within `nums1`.

### Code
```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};
```

### Complexity
- **Time:** $\mathcal{O}(m + n)$
  In the worst-case scenario, each iteration of the loops decrements either `p1` or `p2` (along with `p`). Every element from `nums1` ($m$ elements) and `nums2` ($n$ elements) is inspected and placed exactly once.
- **Space:** $\mathcal{O}(1)$
  No auxiliary arrays, dynamic allocations, or recursive call stacks are utilized. All modifications occur in-place using a constant number of scalar pointer variables (`p1`, `p2`, `p`).

---

## 🕵️‍♂️ Follow-up Questions

1. **Why do we not need a second cleanup loop for `p1 >= 0`?**
   - If `nums2` is exhausted first (`p2 < 0`), any remaining elements in `nums1` are already in their correct, relative, sorted positions at indices `0` through `p1`. Writing them back into `nums1[p]` would be assigning `nums1[i] = nums1[i]`, which is redundant.

2. **Can `p1` and `p` ever collide such that an unread value in `nums1` is overwritten?**
   - No. At any point in time, the number of empty slots created at the back is equal to the number of elements written from `nums2`. Mathematically, `p - p1 = (m + n - 1 - k) - (m - 1 - k_1) = n - k_2`, where $k_2 \le n$ is the count of items taken from `nums2`. Since $n - k_2 \ge 0$, `p` is always strictly greater than or equal to `p1`, preventing any unread element from being prematurely overwritten.
