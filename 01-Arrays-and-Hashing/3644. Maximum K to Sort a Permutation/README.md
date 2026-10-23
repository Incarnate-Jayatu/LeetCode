<h2><a href="https://leetcode.com/problems/maximum-k-to-sort-a-permutation">3644. Maximum K to Sort a Permutation</a></h2>

<p>You are given an integer array <code>nums</code> of length <code>n</code>, where <code>nums</code> is a <strong><span data-keyword="permutation-array" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_t_" data-state="closed" class="">permutation</button></span></strong> of the numbers in the range <code>[0..n - 1]</code>.</p>

<p>You may swap elements at indices <code>i</code> and <code>j</code> <strong>only if</strong> <code>nums[i] AND nums[j] == k</code>, where <code>AND</code> denotes the bitwise AND operation and <code>k</code> is a <strong>non-negative</strong> integer.</p>

<p>Return the <strong>maximum</strong> value of <code>k</code> such that the array can be sorted in <strong>non-decreasing</strong> order using any number of such swaps. If <code>nums</code> is already sorted, return 0.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [0,3,2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>Choose <code>k = 1</code>. Swapping <code>nums[1] = 3</code> and <code>nums[3] = 1</code> is allowed since <code>nums[1] AND nums[3] == 1</code>, resulting in a sorted permutation: <code>[0, 1, 2, 3]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [0,1,3,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>Choose <code>k = 2</code>. Swapping <code>nums[2] = 3</code> and <code>nums[3] = 2</code> is allowed since <code>nums[2] AND nums[3] == 2</code>, resulting in a sorted permutation: <code>[0, 1, 2, 3]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [3,2,1,0]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>Only <code>k = 0</code> allows sorting since no greater <code>k</code> allows the required swaps where <code>nums[i] AND nums[j] == k</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= n - 1</code></li>
	<li><code>nums</code> is a permutation of integers from <code>0</code> to <code>n - 1</code>.</li>
</ul>


---

# 🛍️ Maximum-K-to-Sort-a-Permutation | Explained

## Approach 1: Bitwise AND of Displaced Elements
### Intuition
Imagine a group of misfiled books on a shelf where each book labeled $v$ belongs at slot $v$. If two books can only be swapped when they share a specific set of master security tags (a bitwise mask $k$), then any book that is currently in the wrong position *must* participate in at least one swap to reach its correct destination. 

Because every valid swap between two values $u$ and $v$ requires that $u \ \& \ v = k$, the bits that are set in $k$ must be present in both $u$ and $v$. In fact, by transitivity across all required swaps in the permutation cycles, every element that is displaced from its target position must have the bits of $k$ set. Thus, the maximum allowable value for $k$ cannot have any bit set to `1` that is `0` in *any* displaced element. Taking the cumulative bitwise AND across all elements currently not at their sorted index ($nums[i] \neq i$) gives the upper bound for $k$, which is also achievable because all elements sharing these bits can form connected components and be arbitrarily permuted. If the permutation is already sorted, no swaps are needed, and the default answer is $0$.

### Algorithm Visualized

```mermaid
flowchart TD
    Start([Start: Input nums]) --> Init[Initialize res = INT_MAX]
    Init --> LoopInit[Loop index i from 0 to n - 1]
    
    LoopInit --> CheckDisplaced{nums[i] == i ?}
    CheckDisplaced -- Yes (In Place) --> Skip[Skip / Continue]
    CheckDisplaced -- No (Displaced) --> BitwiseAnd[res = res & nums[i]]
    
    Skip --> NextIndex{i < n - 1 ?}
    BitwiseAnd --> NextIndex
    
    NextIndex -- Yes --> Inc[i++] --> CheckDisplaced
    NextIndex -- No --> CheckSorted{res == INT_MAX ?}
    
    CheckSorted -- Yes (Already Sorted) --> ReturnZero[Return 0]
    CheckSorted -- No --> ReturnRes[Return res]
```

### Approach
1. **Initialize Bitmask Tracker**: 
   - Set an accumulator `res` to `INT_MAX` (all bits set to `1`) to serve as the identity element for the bitwise AND operation.
2. **Identify Displaced Elements**: 
   - Traverse the permutation array from index `0` to `n - 1`.
   - Check if the current element is in its sorted position: `nums[i] == i`.
   - If it is already in place, no swap is strictly required for this element; continue to the next index.
3. **Accumulate Bit Constraints**: 
   - If `nums[i] != i`, this number must move. Therefore, $k$ must be a submask of `nums[i]`.
   - Update `res` with `res &= nums[i]`.
4. **Handle Edge Case & Final Return**:
   - If the array was already sorted, `res` remains untouched (`INT_MAX`). According to the problem constraints, no operations are needed, so return `0`.
   - Otherwise, return `res`.

### Detailed Code Analysis
- **Line 4: `int n = nums.size();`**
  - Captures the length of the input permutation to control loop bounds.
- **Line 5: `int res = INT_MAX;`**
  - Uses `INT_MAX` (binary representation consisting entirely of ones for signed 32-bit integers, `0x7FFFFFFF`) as the base identity value for the cumulative bitwise AND.
- **Line 6: `for (int i = 0; i < n; i++)`**
  - Iterates sequentially through each index of the permutation in $O(n)$ time.
- **Lines 7–9: `if (nums[i] == i) { continue; }`**
  - Checks if the element is already at its target position. Elements that are already correctly positioned do not constrain $k$, as they do not need to be moved. Skipping them ensures we do not needlessly strip bits from `res`.
- **Line 10: `res &= nums[i];`**
  - Performs a bitwise AND between the current accumulator `res` and the displaced value `nums[i]`. Any bit that is `0` in `nums[i]` is cleared to `0` in `res`.
- **Line 12: `return res == INT_MAX ? 0 : res;`**
  - Ternary check: If no elements were displaced, `res` is never modified and remains `INT_MAX`. In this scenario, zero swaps are required, so the function outputs `0`. Otherwise, it returns the maximized bitmask `res`.

### Code
```cpp
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] == i) {
                continue;
            }
            res &= nums[i];
        }
        return res == INT_MAX ? 0 : res;
    }
};
```

### Complexity
- **Time:** $\mathcal{O}(n)$, where $n$ is the length of `nums`. The algorithm scans the array in a single linear pass and performs constant-time $\mathcal{O}(1)$ bitwise operations per element.
- **Space:** $\mathcal{O}(1)$. The algorithm requires only a few auxiliary integer variables (`n`, `res`, `i`), maintaining strictly constant additional memory.

## 🕵️‍♂️ Follow-up Questions (Optional)

1. **What if the array is an arbitrary array with duplicates instead of a permutation of $[0, n-1]$?**
   - If duplicates or non-consecutive values are present, the condition `nums[i] == i` no longer accurately determines if an element is in its sorted position. We would first need to compute the target sorted array, identify indices where `nums[i] != target[i]`, and perform the bitwise AND over those displaced values.

2. **Why does considering only the elements with `nums[i] != i` guarantee that a valid sequence of swaps exists?**
   - Any permutation can be decomposed into disjoint cycles. If every element in a cycle has the bits of $k$ set, then for any two elements $u, v$ in the cycle, $u \ \& \ v \ \& \ k = k$. Thus, every element in the cycle can be swapped to its correct position using valid swaps without involving elements that are already in place.