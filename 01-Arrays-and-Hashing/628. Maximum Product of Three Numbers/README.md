<h2><a href="https://leetcode.com/problems/maximum-product-of-three-numbers">628. Maximum Product of Three Numbers</a></h2>

<p>You are given an integer array <code>nums</code>.</p>

<p>Find three numbers whose product is <strong>maximum</strong> and return the <strong>maximum</strong> product.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>The only three numbers are 1, 2, and 3, so the maximum product is <code>1 * 2 * 3 = 6</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">24</span></p>

<p><strong>Explanation:</strong></p>

<p>The largest product comes from the three greatest numbers: <code>2 * 3 * 4 = 24</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [-1,-2,-3]</span></p>

<p><strong>Output:</strong> <span class="example-io">-6</span></p>

<p><strong>Explanation:</strong></p>

<p>The only three numbers are -1, -2, and -3, so the maximum product is <code>(-1) * (-2) * (-3) = -6</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;=&nbsp;10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


---

# 🛍️ Maximum-Product-of-Three-Numbers | Explained

## Approach 1: Sorting & Boundary Product Comparison

### Intuition
Think of choosing candidates to maximize a score where two negative traits cancel each other out to create a massive positive. In mathematics, multiplying two negative numbers yields a positive result. Therefore, the maximum product of three numbers can arise from only two scenarios:
1. **Three largest positive numbers**: Multiplying the top three largest numbers in the collection.
2. **Two smallest negative numbers and the largest positive number**: If the two smallest numbers are deeply negative (e.g., $-100 \times -100 = 10,000$), multiplying them together creates a large positive number. Multiplying that product by the largest overall number in the array might yield a result far greater than multiplying the three largest numbers.

By sorting the array, these candidates naturally align at the absolute boundaries (the extreme ends) of the collection.

### Algorithm Visualized

```mermaid
flowchart TD
    A[Input: nums array] --> B[Sort nums in Ascending Order]
    B --> C["Identify Candidates:
    Smallest: nums[0], nums[1]
    Largest: nums[n-3], nums[n-2], nums[n-1]"]
    C --> D["Compute Candidate 1:
    m1 = nums[n-1] * nums[n-2] * nums[n-3]"]
    C --> E["Compute Candidate 2:
    m2 = nums[0] * nums[1] * nums[n-1]"]
    D --> F[Compare max(m1, m2)]
    E --> F
    F --> G[Return Maximum Product]
```

---

### Approach
1. **Sort the Array**: Arrange the array in non-decreasing order. This groups the most negative numbers at index `0` and `1`, and the largest numbers at indices `n-3`, `n-2`, and `n-1`.
2. **Calculate Candidate 1 (`m1`)**: Compute the product of the three largest numbers located at the end of the array:
   $$\text{m1} = \text{nums}[n - 1] \times \text{nums}[n - 2] \times \text{nums}[n - 3]$$
3. **Calculate Candidate 2 (`m2`)**: Compute the product of the two most negative numbers (at the start) and the single largest positive number (at the end):
   $$\text{m2} = \text{nums}[0] \times \text{nums}[1] \times \text{nums}[n - 1]$$
4. **Return the Optimal Result**: Use `std::max(m1, m2)` to return whichever combination yielded the larger value.

---

### Detailed Code Analysis

```cpp
int n = nums.size();
```
- Retrieves and stores the number of elements in `nums` to easily access boundary indices from the end of the vector.

```cpp
sort(nums.begin(), nums.end());
```
- Applies `std::sort`, which in C++ uses Introsort (a hybrid of QuickSort, HeapSort, and InsertionSort).
- After sorting, `nums[0]` is the smallest element and `nums[n - 1]` is the largest element.

```cpp
int m1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
```
- Evaluates the product of the three highest values (`nums[n - 1]`, `nums[n - 2]`, `nums[n - 3]`).
- This handles the case where all numbers are positive, all are negative, or the highest three positive numbers produce the optimal product.

```cpp
int m2 = nums[0] * nums[1] * nums[n - 1];
```
- Evaluates the product of the two lowest values (`nums[0]` and `nums[1]`) with the single highest value (`nums[n - 1]`).
- If `nums[0]` and `nums[1]` are negative, their product becomes positive. Multiplying this by `nums[n - 1]` can potentially exceed `m1`.

```cpp
return max(m1, m2);
```
- Compares the two candidate values and returns the maximum product.

---

### Code

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int m1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int m2 = nums[0] * nums[1] * nums[n - 1];
        return max(m1, m2);
    }
};
```

---

### Complexity

- **Time Complexity:** $\mathcal{O}(N \log N)$
  Sorting the vector of size $N$ dominates the runtime via `std::sort`. Indexing and multiplying the values take $\mathcal{O}(1)$ time.
- **Space Complexity:** $\mathcal{O}(\log N)$
  The auxiliary space is determined by the internal recursion stack of the `std::sort` algorithm (Introsort), which requires logarithmic space in the worst case.

---

## 🕵️‍♂️ Follow-up Questions (Optional)

### 1. Can we optimize this solution to $\mathcal{O}(N)$ time and $\mathcal{O}(1)$ space?
**Answer:** Yes. Instead of sorting the entire array, we only need to track 5 specific values during a single pass:
- The top 3 maximum values: `max1`, `max2`, `max3`.
- The top 2 minimum values: `min1`, `min2`.

By iterating through the array once and updating these 5 variables, we can compute `max(max1 * max2 * max3, min1 * min2 * max1)` in $\mathcal{O}(N)$ time and $\mathcal{O}(1)$ auxiliary memory.

### 2. Can integer overflow occur during intermediate multiplications?
**Answer:** In LeetCode's constraints for this specific problem, values typically range from $-1000$ to $1000$. The maximum product is $1000^3 = 10^9$, which fits comfortably within a standard 32-bit signed integer (`int` can hold up to $\approx 2.14 \times 10^9$). However, if values exceed $\pm 1290$, standard 32-bit integers would overflow, requiring calculations to be cast to a 64-bit integer type like `long long` in C++.