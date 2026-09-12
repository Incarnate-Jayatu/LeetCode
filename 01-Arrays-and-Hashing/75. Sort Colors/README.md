<h2><a href="https://leetcode.com/problems/sort-colors">75. Sort Colors</a></h2>

<p>You are given an array <code>nums</code> with <code>n</code> objects colored red, white, or blue, sort them <strong><a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a> </strong>so that objects of the same color are adjacent, with the colors in the order red, white, and blue.</p>

<p>We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.</p>

<p>You must solve this problem without using the library's sort function.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,0,2,1,1,0]</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,0,1,1,2,2]</span></p>

<p><strong>Explanation:</strong></p>

<p>The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,0,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,1,2]</span></p>

<p><strong>Explanation:</strong></p>

<p>The array has one each of 0, 1, and 2, arranged in-place in the order 0, 1, 2.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>nums[i]</code> is either 0, 1, or 2.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong>&nbsp;Could you come up with a one-pass algorithm using only&nbsp;constant extra space?</p>


---

# 🛍️ Sort-Colors | Explained

## Approach 1: Optimized Bubble Sort
### Intuition
Imagine you have a row of colored billiard balls labeled 0 (red), 1 (white), and 2 (blue) mixed up on a table. If you walk down the line from left to right, comparing each ball with its immediate neighbor and swapping them whenever the left ball has a higher value than the right ball, the largest values will gradually "bubble" to the far right. 

Repeating this pass ensures that after the first iteration, the largest number (2) reaches its final resting position at the end. In each subsequent pass, the next largest number settles into place. If you ever complete an entire pass without performing a single swap, you know the entire array is already sorted, and you can stop early.

### Algorithm Visualized

```mermaid
flowchart TD
    Start([Start sortColors]) --> InitOuter[Outer Loop: i = 0 to n-1]
    InitOuter --> CheckOuter{i < n?}
    CheckOuter -- No --> End([Array Sorted])
    CheckOuter -- Yes --> ResetFlag[Set swapped = false]
    
    ResetFlag --> InitInner[Inner Loop: j = 0 to n - i - 2]
    InitInner --> CheckInner{j < n - i - 1?}
    
    CheckInner -- Yes --> Compare{arr[j] > arr[j+1]?}
    Compare -- Yes --> Swap[Swap arr[j] and arr[j+1]<br/>Set swapped = true]
    Swap --> IncInner[j++]
    Compare -- No --> IncInner
    IncInner --> CheckInner
    
    CheckInner -- No --> CheckSwapped{swapped == false?}
    CheckSwapped -- Yes --> End
    CheckSwapped -- No --> IncOuter[i++]
    IncOuter --> CheckOuter
```

### Approach
1. **Initialize Problem Bounds:** Compute the total number of elements $n = \text{arr.size()}$.
2. **Outer Pass Loop:** Run an outer loop indexed by `i` from `0` to `n - 1`. Each iteration corresponds to placing the next largest element into its correct final position at the end of the unsorted segment.
3. **Early-Exit Tracking:** Initialize a boolean flag `swapped = false` at the start of each outer pass.
4. **Inner Comparison Loop:** Traverse the unsorted portion of the array from `j = 0` to `n - i - 2`:
   - Compare adjacent elements `arr[j]` and `arr[j + 1]`.
   - If `arr[j] > arr[j + 1]`, swap them and set `swapped = true`.
5. **Early Termination Check:** If `swapped` remains `false` after traversing the inner loop, no elements were out of order. The array is fully sorted, and we can immediately `break`.
6. **Output Elements:** Traverse and print the sorted array.

### Detailed Code Analysis
- **Lines 3–4 (`void sortColors(vector<int>& arr)`, `int n = arr.size();`):**
  The function receives a reference to `vector<int>` named `arr`, allowing in-place modifications without allocating extra storage for a new container. `n` captures the size of the array to control loop limits.
- **Line 5 (`for(int i = 0; i < n; i++)`):**
  Drives the number of bubbling passes. In the worst case, $n$ passes are needed to sort $n$ elements.
- **Line 6 (`bool swapped = false;`):**
  A local optimization flag. If a full pass occurs without triggering a swap, the array is already sorted, allowing the algorithm to drop from an $O(n^2)$ worst-case to an $O(n)$ best-case runtime.
- **Line 7 (`for(int j = 0; j < n-i-1; j++)`):**
  Bounds the inner comparisons. Because each outer iteration $i$ guarantees that the largest $i$ elements have bubbled to indices $[n-i, n-1]$, the inner loop only needs to inspect elements up to $n - i - 1$.
- **Lines 8–9 (`if(arr[j] > arr[j+1]){ swap(arr[j], arr[j+1]); swapped = true; }`):**
  Performs adjacent comparison. The standard library function `std::swap` exchanges values in place using move semantics. Setting `swapped = true` records that the array was not yet fully sorted during this pass.
- **Line 10 (`if(!swapped) break;`):**
  Evaluates whether any inversions were resolved. If `swapped` is still `false`, it triggers an early exit out of the outer loop.
- **Lines 12–13 (`for(int i=0; i<n; i++) cout<<arr[i]<< ;`):**
  Attempts to print each element of the sorted vector to standard output. 
  *(Note on compilation: Line 13 contains a syntax error `cout<<arr[i]<< ;` where a stream argument is missing before the semicolon. In standard LeetCode submissions, printing is unnecessary as the platform evaluates the modified in-place vector directly).*

### Code
```cpp
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) { 
                    swap(arr[j], arr[j + 1]); 
                    swapped = true; 
                }
            }
            if (!swapped) break;
        }
    }
};
```

### Complexity
- **Time:**
  - **Worst-Case:** $\mathcal{O}(n^2)$ — Occurs when the array is in reverse order (e.g., `[2, 2, 1, 1, 0, 0]`). The algorithm performs $\frac{n(n-1)}{2}$ comparisons and swaps.
  - **Average-Case:** $\mathcal{O}(n^2)$ — Random distributions of `0`, `1`, and `2` require quadratic comparisons on average.
  - **Best-Case:** $\mathcal{O}(n)$ — If the array is already sorted (e.g., `[0, 0, 1, 1, 2, 2]`), the inner loop runs once, finds zero out-of-order pairs, leaves `swapped == false`, and terminates immediately.
- **Space:** $\mathcal{O}(1)$ Auxiliary Space — The sort is performed entirely in place using a few primitive scalar variables (`n`, `i`, `j`, `swapped`).

---

## 🕵️‍♂️ Follow-up Questions

### 1. How can we solve this problem in a single pass with $\mathcal{O}(n)$ time complexity?
Bubble Sort is a general-purpose comparison sort that ignores the specific constraint that elements are exclusively `0`, `1`, and `2`. We can solve this in a single pass using Dijkstra's **Dutch National Flag algorithm**:
- Maintain three pointers: `low = 0`, `mid = 0`, and `high = n - 1`.
- While `mid <= high`:
  - If `arr[mid] == 0`: Swap `arr[low]` and `arr[mid]`, then increment both `low++` and `mid++`.
  - If `arr[mid] == 1`: Increment `mid++`.
  - If `arr[mid] == 2`: Swap `arr[mid]` and `arr[high]`, then decrement `high--` (do not increment `mid`, as the swapped element from `high` has not yet been processed).
- This achieves an optimal single-pass $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ space.

### 2. What is the Counting Sort approach, and why is the Dutch National Flag algorithm generally preferred over it?
Counting Sort makes two passes over the array:
1. Count the frequencies of `0`s, `1`s, and `2`s using three scalar counters (or a size-3 array).
2. Overwrite the original array according to the counts.

While Counting Sort also runs in $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ space, it requires **two passes** (one read pass, one write pass). The Dutch National Flag algorithm requires only **one pass** and performs fewer total memory write operations, making it more cache-friendly and performant in practice.