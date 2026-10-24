<h2><a href="https://leetcode.com/problems/left-and-right-sum-differences">2574. Left and Right Sum Differences</a></h2>

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of size <code>n</code>.</p>

<p>Define two arrays <code>leftSum</code> and <code>rightSum</code> where:</p>

<ul>
	<li><code>leftSum[i]</code> is the sum of elements to the left of the index <code>i</code> in the array <code>nums</code>. If there is no such element, <code>leftSum[i] = 0</code>.</li>
	<li><code>rightSum[i]</code> is the sum of elements to the right of the index <code>i</code> in the array <code>nums</code>. If there is no such element, <code>rightSum[i] = 0</code>.</li>
</ul>

<p>Return an integer array <code>answer</code> of size <code>n</code> where <code>answer[i] = |leftSum[i] - rightSum[i]|</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [10,4,8,3]
<strong>Output:</strong> [15,1,11,22]
<strong>Explanation:</strong> The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


---

# 🛍️ Left-and-Right-Sum-Differences | Explained

## Approach 1: Two-Pass Running Prefix & Suffix Accumulation
### Intuition
Imagine walking down a one-way street lined with numbered houses, holding a notebook. On your way forward, before you step in front of each house, you jot down the total sum of all house numbers you have already passed (`leftSum`). 

Once you reach the end, you turn around and walk backwards. This time, you keep a mental tally of the houses you are passing on the way back (`rightSum`). At each house, you compare the number already written in your notebook with your mental tally, calculate the absolute difference, and overwrite the notebook entry with this final value. 

By reusing the result array `ans` to first store the prefix sums and then overwrite them with the absolute differences in the reverse pass, we avoid allocating extra intermediate arrays for `leftSum` and `rightSum`.

### Algorithm Visualized

```mermaid
flowchart TD
    subgraph Pass1 [Pass 1: Left-to-Right (Accumulate leftSum)]
        direction LR
        A["Start: leftSum = 0"] --> B["ans[i] = leftSum"]
        B --> C["leftSum += nums[i]"]
        C --> D{"i < n?"}
        D -- Yes --> B
        D -- No --> E["ans contains prefix sums"]
    end

    subgraph Pass2 [Pass 2: Right-to-Left (Compute Absolute Difference)]
        direction LR
        F["Start: rightSum = 0"] --> G["ans[i] = |ans[i] - rightSum|"]
        G --> H["rightSum += nums[i]"]
        H --> I{"i >= 0?"}
        I -- Yes --> G
        I -- No --> J["ans contains final differences"]
    end

    Pass1 --> Pass2
```

### Approach
1. **Array Initialization**: Create an output vector `ans` of the same size `n` as `nums`.
2. **First Pass (Prefix Accumulation)**:
   - Initialize a running accumulator `leftSum = 0`.
   - Iterate through `nums` from index `0` to `n - 1`.
   - For each index `i`, store the current `leftSum` into `ans[i]`. This represents the sum of all elements strictly to the left of `i`.
   - Add the current element `nums[i]` to `leftSum` for subsequent positions.
3. **Second Pass (Suffix Accumulation & Result Computation)**:
   - Initialize a running accumulator `rightSum = 0`.
   - Iterate backward through `nums` from index `n - 1` down to `0`.
   - For each index `i`, `ans[i]` currently holds `leftSum[i]`. Update `ans[i]` in-place to `abs(ans[i] - rightSum)`.
   - Add the current element `nums[i]` to `rightSum` so that elements to the left will include `nums[i]` as part of their right sum.
4. **Return**: Return the mutated `ans` vector.

### Detailed Code Analysis

```cpp
int n = nums.size();
vector<int> ans(n);
```
- We extract the size of `nums` into variable `n`.
- We initialize the output vector `ans` of size `n` with default values `0`. This pre-allocation prevents dynamic resizing overhead during assignment.

```cpp
int leftSum = 0;
for (int i = 0; i < n; ++i) {
    ans[i] = leftSum;
    leftSum += nums[i];
}
```
- `leftSum` tracks the cumulative sum of elements to the left of index `i`.
- At `i = 0`, there are no elements to the left, so `ans[0]` receives `0`.
- After assigning `ans[i] = leftSum`, we update `leftSum += nums[i]` so that index `i + 1` receives the sum including `nums[i]`.
- At the end of this loop, `ans[i]` holds the strictly left prefix sum for each index `i`.

```cpp
int rightSum = 0;
for (int i = n - 1; i >= 0; --i) {
    ans[i] = abs(ans[i] - rightSum);
    rightSum += nums[i];
}
```
- `rightSum` tracks the cumulative sum of elements to the right of index `i`.
- At `i = n - 1`, there are no elements to the right, so `rightSum` is `0`.
- `ans[i]` currently holds `leftSum[i]`. We compute `abs(ans[i] - rightSum)`, which translates directly to $|leftSum[i] - rightSum[i]|$, and write the result back into `ans[i]`.
- We then update `rightSum += nums[i]`, preparing the accumulator for index `i - 1`.

```cpp
return ans;
```
- Returns the completely calculated result vector.

### Code
```cpp
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = leftSum;
            leftSum += nums[i];
        }
        int rightSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] = abs(ans[i] - rightSum);
            rightSum += nums[i];
        }
        return ans;
    }
};
```

### Complexity
- **Time:** $O(n)$
  - The first loop runs $n$ times from left to right.
  - The second loop runs $n$ times from right to left.
  - Total operations: $2n \implies O(n)$, where $n$ is the number of elements in `nums`.
- **Space:** $O(1)$ Auxiliary Space
  - Beyond the output array `ans` of size $n$ (required to return the result), only two scalar integer variables (`leftSum` and `rightSum`) are used. No additional auxiliary arrays or buffers are allocated.

---

## 🕵️‍♂️ Follow-up Questions (Optional)

1. **Can this be solved using a single pass after computing the total sum?**
   - **Answer:** Yes. If we first compute `totalSum = accumulate(nums.begin(), nums.end(), 0)`, then for any index `i`, `rightSum = totalSum - leftSum - nums[i]`. In one loop, we can compute `ans[i] = abs(leftSum - (totalSum - leftSum - nums[i]))` and then update `leftSum += nums[i]`. This still runs in $O(n)$ time, but replaces the reverse iteration with an initial sum pass.

2. **What if the values in `nums` were large enough that their cumulative sum could overflow a standard 32-bit signed integer?**
   - **Answer:** If $\sum nums[i] > 2^{31} - 1$, `leftSum` and `rightSum` would overflow, leading to undefined behavior in C++. We would need to change accumulator variables to `long long` (or `int64_t`), compute the absolute difference in 64-bit precision, and cast back to the expected return type if guaranteed by problem bounds.