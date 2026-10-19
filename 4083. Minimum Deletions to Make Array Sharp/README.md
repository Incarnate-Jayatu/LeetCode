<h2><a href="https://leetcode.com/problems/minimum-deletions-to-make-array-sharp">4083. Minimum Deletions to Make Array Sharp</a></h2>

<p>You are given an integer array <code>nums</code>.</p>

<p>You may delete any number of elements from <code>nums</code>. The remaining elements keep their original order.</p>

<p>The resulting array <code>a</code> is <strong>sharp</strong> if the <strong>bitwise XOR</strong> of every pair of <strong>adjacent</strong> elements is <strong>non-zero</strong>. That is, <code>a[i] XOR a[i + 1] != 0</code> for every index <code>i</code> such that <code>0 &lt;= i &lt; a.length - 1</code>. An array with <strong>at most</strong> one element is sharp.</p>

<p>Return the <strong>minimum</strong> number of deletions needed to make <code>nums</code> sharp.</p>

<p><strong>Bitwise XOR</strong> compares the corresponding bits of two integers. A bit in the result is 1 if the corresponding bits differ, and 0 otherwise.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,2,2,2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The pairs at indices <code>(0, 1)</code>, <code>(2, 3)</code>, and <code>(3, 4)</code> each have an XOR of 0.</li>
	<li>Deleting one 1 and two 2s leaves <code>[1, 2, 3]</code>, where <code>1 XOR 2 == 3</code> and <code>2 XOR 3 == 1</code> are both non-zero. Therefore, the answer is 3.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,4,9,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The pair at indices <code>(0, 1)</code> has an XOR of 0.</li>
	<li>Deleting either of these two 4s leaves <code>[4, 9, 4]</code>, where <code>4 XOR 9 == 13</code> and <code>9 XOR 4 == 13</code> are both non-zero.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


---

# 🛍️ Minimum-Deletions-to-Make-Array-Sharp | Explained

## Approach 1: Adjacent Deduplication / Consecutive Identical Element Reduction

### Intuition
Imagine walking down a path of stepping stones where some consecutive stones have the exact same height, making the surface flat rather than "sharp" (having contrast between consecutive steps). To create contrast between every single adjacent step, you must eliminate the flat stretches. If you encounter a cluster of three identical stones `[5, 5, 5]`, you only need to keep the first one and discard the remaining two duplicates. 

The core idea is that any contiguous subarray of identical elements can only contribute exactly one element to the final array if adjacent identical elements are forbidden. By counting how many times the value transitions (or by counting the head of each contiguous identical block), we find the maximum number of elements we can retain. Subtracting this retained count from the original array size gives the minimum number of deletions required.

### Algorithm Visualized

```mermaid
flowchart TD
    A[Start: nums = 1, 2, 2, 3, 3, 3] --> B{Is nums empty?}
    B -- Yes --> C[Return 0]
    B -- No --> D[Initialize unique = 1<br/>Pointer i = 1]
    
    D --> E{i < nums.size()?}
    E -- No --> I[Calculate deletions:<br/>nums.size() - unique]
    E -- Yes --> F{nums[i] != nums[i-1]?}
    
    F -- True: New Distinct Segment --> G[unique++<br/>Transition Found]
    F -- False: Duplicate Found --> H[Skip / Mark for deletion]
    
    G --> J[i++]
    H --> J
    J --> E
    
    I --> K[Return Result]
```

### Approach
1. **Edge Case Handling**: If the input array `nums` is empty, no deletions are required, so return `0`.
2. **Track Retained Elements**: Initialize a counter `unique = 1`. The first element `nums[0]` is always kept as the anchor of the first block.
3. **Single Pass Scanning**: Iterate through the array starting from index `1` to `nums.size() - 1`:
   - Compare the current element `nums[i]` with the preceding element `nums[i-1]`.
   - If `nums[i] != nums[i-1]`, it signifies the start of a new distinct block, so increment `unique`.
   - If `nums[i] == nums[i-1]`, this is an unwanted adjacent duplicate that must be deleted; do not increment `unique`.
4. **Compute Deletions**: The maximum number of valid elements preserved is `unique`. Therefore, the minimum deletions needed is `nums.size() - unique`.

### Detailed Code Analysis

```cpp
1class Solution {
2public:
3    int minDeletions(vector<int>& nums) {
```
- **Lines 1–3**: Class and function definition. The function `minDeletions` accepts `nums` by reference to avoid copying the vector overhead.

```cpp
4        if(nums.empty())
5            return 0;
```
- **Lines 4–5**: Guards against undefined behavior when indexing `nums[0]` or when calling `.size()` on an empty container. If there are no elements, 0 deletions are needed.

```cpp
6        int unique = 1;
```
- **Line 6**: Declares and initializes `unique = 1`. Since the array is non-empty, we can always keep at least the very first element `nums[0]`.

```cpp
7        for(int i=1; i<nums.size(); ++i){
8            if(nums[i]!=nums[i-1])
9                unique++;
10       }
```
- **Lines 7–10**: A single linear loop starting at index `1`.
  - Line 8 evaluates `nums[i] != nums[i-1]`. This checks whether the current element changes value relative to its immediate neighbor.
  - Line 9 increments `unique` only when a boundary between two different values is crossed. Any duplicate value adjacent to its predecessor is ignored (implicitly marked for deletion).

```cpp
11        return nums.size()-unique;
12    }
13};
```
- **Lines 11–13**: `nums.size()` is the total count of elements initially present. `unique` represents the maximum number of elements remaining such that no two adjacent elements are equal. The difference `nums.size() - unique` computes the exact number of deletions performed.

### Code
```cpp
class Solution {
public:
    int minDeletions(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int unique = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[i-1])
                unique++;
        }
        return nums.size() - unique;
    }
};
```

### Complexity
- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the number of elements in `nums`. We traverse the array from left to right in a single pass, performing constant-time $\mathcal{O}(1)$ comparisons at each step.
- **Space Complexity:** $\mathcal{O}(1)$. The algorithm uses only a constant amount of extra memory (`unique` and loop counter `i`) without allocating auxiliary containers.

---

## 🕵️‍♂️ Follow-up Questions

1. **What if the problem requires a strict alternating peak-valley pattern ($nums[i-1] < nums[i] > nums[i+1]$ or $nums[i-1] > nums[i] < nums[i+1]$) instead of just non-equal adjacent elements?**
   - In that scenario, checking `nums[i] != nums[i-1]` is insufficient. You would need a state machine or dynamic programming approach (similar to the Wiggle Subsequence problem) to track whether the next transition should be strictly increasing or strictly decreasing, requiring a greedy direction flip check: `(nums[i] > nums[i-1] && prevDiff <= 0)` or `(nums[i] < nums[i-1] && prevDiff >= 0)`.

2. **Can this be implemented in-place using the STL?**
   - Yes. C++ provides `std::unique(nums.begin(), nums.end())`, which moves adjacent duplicates to the end of the range. The number of deletions can be calculated directly as `nums.end() - std::unique(nums.begin(), nums.end())` without manually writing the loop.