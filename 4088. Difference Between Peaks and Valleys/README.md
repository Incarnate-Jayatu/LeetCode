<h2><a href="https://leetcode.com/problems/difference-between-peaks-and-valleys">4088. Difference Between Peaks and Valleys</a></h2>

<p>You are given an integer array <code>nums</code> of length <code>n</code>.</p>

<p>An index <code>i</code> is called a <strong>peak</strong> if <strong>all</strong> of the following conditions hold:</p>

<ul>
	<li><code>0 &lt; i &lt; n - 1</code></li>
	<li><code>nums[i] &gt; nums[i - 1]</code></li>
	<li><code>nums[i] &gt; nums[i + 1]</code></li>
</ul>

<p>An index <code>i</code> is called a <strong>valley</strong> if <strong>all</strong> of the following conditions hold:</p>

<ul>
	<li><code>0 &lt; i &lt; n - 1</code></li>
	<li><code>nums[i] &lt; nums[i - 1]</code></li>
	<li><code>nums[i] &lt; nums[i + 1]</code></li>
</ul>

<p>Return an integer denoting the <strong>difference</strong> between the sum of all peak values and the sum of all valley values.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,5,2,4,1,3,0]</span></p>

<p><strong>Output:</strong> <span class="example-io">9</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The peak values are <code>nums[1] = 5</code>, <code>nums[3] = 4</code>, and <code>nums[5] = 3</code>.</li>
	<li>The valley values are <code>nums[2] = 2</code> and <code>nums[4] = 1</code>.</li>
	<li>The difference between the sum of the peak values and the sum of the valley values is <code>(5 + 4 + 3) - (2 + 1) = 9</code>. Hence, the answer is 9.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [-5,-6,-1,-2,5,3,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">12</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The peak values are <code>nums[2] = -1</code> and <code>nums[4] = 5</code>.</li>
	<li>The valley values are <code>nums[1] = -6</code> and <code>nums[3] = -2</code>.</li>
	<li>The difference between the sum of the peak values and the sum of the valley values is <code>(-1 + 5) - (-6 + (-2)) = 12</code>. Hence, the answer is 12.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [6,5,2,5,5,3,6]</span></p>

<p><strong>Output:</strong> <span class="example-io">-5</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>There are no peak values in the array.</li>
	<li>The valley values are <code>nums[2] = 2</code> and <code>nums[5] = 3</code>.</li>
	<li>The difference between the sum of the peak values and the sum of the valley values is <code>(0) - (2 + 3) = -5</code>. Hence, the answer is -5.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= n == nums.length &lt;= 100</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


---

# 🛍️ Difference-Between-Peaks-and-Valleys | Explained

## Approach 1: Single-Pass Local Extrema Detection (Sliding Triplet Evaluation)

### Intuition
Imagine walking through an undulating mountain ridge. At every single step, you pause and look directly behind you and directly in front of you. 

- If both the ground behind you and the ground ahead are lower than where you are standing, you have reached a **peak** (a local maximum). You add your current elevation to your running balance.
- If both the ground behind you and the ground ahead are higher than where you are standing, you have reached a **valley** (a local minimum). You deduct your current elevation from your running balance.
- If you are on an incline, a decline, or a flat path, you are neither at a peak nor a valley, so you ignore that point and keep walking.

Because identifying a local extremum relies strictly on immediate neighbors, you only need to inspect a 3-element sliding window centered at each index from `1` to `n - 2`.

---

### Algorithm Visualized

```mermaid
flowchart TD
    Start([Start Loop at index i = 1]) --> Condition{i < n - 1?}
    Condition -- No --> End([Return ans])
    Condition -- Yes --> CheckPeak{nums[i] > nums[i-1]<br/>AND<br/>nums[i] > nums[i+1]?}
    
    CheckPeak -- Yes (Peak) --> AddPeak[ans += nums[i]]
    CheckPeak -- No --> CheckValley{nums[i] < nums[i-1]<br/>AND<br/>nums[i] < nums[i+1]?}
    
    CheckValley -- Yes (Valley) --> SubValley[ans -= nums[i]]
    CheckValley -- No (Neither) --> Increment[i++]
    
    AddPeak --> Increment
    SubValley --> Increment
    Increment --> Condition
```

---

### Approach
1. **Initialize State**: Maintain an accumulator variable `ans = 0` to store the net difference between the sum of peaks and the sum of valleys.
2. **Determine Valid Boundaries**: A peak or valley requires both a left and a right neighbor. Therefore, boundary indices `0` and `n - 1` can never be peaks or valleys. The traversal range is strictly restricted to `[1, n - 2]`.
3. **Neighbor Comparison**:
   - Check if `nums[i]` is strictly greater than both `nums[i - 1]` and `nums[i + 1]`. If true, `nums[i]` is a peak: add `nums[i]` to `ans`.
   - Otherwise, check if `nums[i]` is strictly smaller than both `nums[i - 1]` and `nums[i + 1]`. If true, `nums[i]` is a valley: subtract `nums[i]` from `ans`.
4. **Return Result**: Once the loop terminates, return `ans`. If `nums.size() < 3`, the loop condition `i < n - 1` evaluates to false immediately on initialization (`1 < <3 - 1` is false), gracefully returning `0`.

---

### Detailed Code Analysis

```cpp
class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
```
- Defines the member function `peakValleyDifference` taking `vector<int>& nums` by reference to avoid copying overhead ($O(1)$ memory overhead on invocation).

```cpp
        int n = nums.size();
        int ans = 0;
```
- `int n = nums.size();`: Caches the total number of elements in the vector. 
- `int ans = 0;`: Acts as the accumulator for tracking the total difference: $\sum \text{Peaks} - \sum \text{Valleys}$.

```cpp
        for(int i = 1; i < n-1; i++) {
```
- Sets the iterator `i` to begin at index `1` and continue while `i < n - 1` (equivalent to `i <= n - 2`).
- This safeguards against out-of-bounds reads when referencing `nums[i - 1]` and `nums[i + 1]`.
- If `n < 3` (e.g., $n = 0, 1, 2$), `1 < n - 1` is false, and the loop is skipped entirely without throwing an out-of-range exception.

```cpp
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                ans += nums[i];
            }
```
- Tests the strict peak condition: the current element must be strictly greater than both its predecessor and its successor.
- If true, `nums[i]` is added to `ans`.

```cpp
            else if(nums[i] < nums[i-1] && nums[i] < nums[i+1]) {
                ans -= nums[i];
            }
```
- Uses `else if` because an element cannot be both a peak and a valley simultaneously.
- Tests the strict valley condition: the current element must be strictly smaller than both its predecessor and its successor.
- If true, `nums[i]` is subtracted from `ans`.
- If neither condition holds (e.g., ascending sequence, descending sequence, or part of a flat plateau), the element is ignored.

```cpp
        }
        return ans;
    }
};
```
- Returns the computed net difference after a single pass.

---

### Code

```cpp
class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i < n-1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                ans += nums[i];
            }
            else if(nums[i] < nums[i-1] && nums[i] < nums[i+1]) {
                ans -= nums[i];
            }
        }
        return ans;
    }
};
```

---

### Complexity
- **Time Complexity:** $\mathcal{O}(N)$ where $N$ is the number of elements in `nums`. The loop visits each index from `1` to `N - 2` exactly once, performing $\mathcal{O}(1)$ constant-time comparisons and arithmetic operations per index.
- **Space Complexity:** $\mathcal{O}(1)$. The algorithm runs in-place, relying exclusively on two primitive integer variables (`n` and `ans`) without allocating dynamic memory or auxiliary data structures.

---

## 🕵️‍♂️ Follow-up Questions (Optional)

1. **How would you handle plateaus (equal adjacent values like `[1, 3, 3, 1]`)?**
   * *Answer:* The current strict conditions (`>` and `<`) treat adjacent duplicates as neither peaks nor valleys. To handle plateaus, compress consecutive duplicate numbers into single representative values (or track the start and end of a plateau using two pointers) before applying the local extrema check to the flattened sequence.

2. **Could `ans` experience integer overflow?**
   * *Answer:* If `nums[i]` can be up to $10^9$ and $N$ is up to $10^5$, summing multiple large peaks could exceed the standard 32-bit signed integer maximum ($2^{31} - 1 \approx 2.14 \times 10^9$). To make the solution robust against large inputs, `ans` should be declared as a 64-bit integer (`long long`).