<h2><a href="https://leetcode.com/problems/minimum-sum-of-squared-difference">2333. Minimum Sum of Squared Difference</a></h2>

<p>You are given two positive <strong>0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code>, both of length <code>n</code>.</p>

<p>The <strong>sum of squared difference</strong> of arrays <code>nums1</code> and <code>nums2</code> is defined as the <strong>sum</strong> of <code>(nums1[i] - nums2[i])<sup>2</sup></code> for each <code>0 &lt;= i &lt; n</code>.</p>

<p>You are also given two positive integers <code>k1</code> and <code>k2</code>. You can modify any of the elements of <code>nums1</code> by <code>+1</code> or <code>-1</code> at most <code>k1</code> times. Similarly, you can modify any of the elements of <code>nums2</code> by <code>+1</code> or <code>-1</code> at most <code>k2</code> times.</p>

<p>Return <em>the minimum <strong>sum of squared difference</strong> after modifying array </em><code>nums1</code><em> at most </em><code>k1</code><em> times and modifying array </em><code>nums2</code><em> at most </em><code>k2</code><em> times</em>.</p>

<p><strong>Note</strong>: You are allowed to modify the array elements to become <strong>negative</strong> integers.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
<strong>Output:</strong> 579
<strong>Explanation:</strong> The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0. 
The sum of square difference will be: (1 - 2)<sup>2 </sup>+ (2 - 10)<sup>2 </sup>+ (3 - 20)<sup>2 </sup>+ (4 - 19)<sup>2</sup>&nbsp;= 579.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
<strong>Output:</strong> 43
<strong>Explanation:</strong> One way to obtain the minimum sum of square difference is: 
- Increase nums1[0] once.
- Increase nums2[2] once.
The minimum of the sum of square difference will be: 
(2 - 5)<sup>2 </sup>+ (4 - 8)<sup>2 </sup>+ (10 - 7)<sup>2 </sup>+ (12 - 9)<sup>2</sup>&nbsp;= 43.
Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k1, k2 &lt;= 10<sup>9</sup></code></li>
</ul>


---

# 🛍️ Minimum-Sum-of-Squared-Difference | Explained

## Approach 1: Bucket-Sorted Greedy Reduction (Frequency Array)

### Intuition

Imagine you have a row of uneven sand piles, and your goal is to minimize the total "height cost" measured as the sum of squared heights ($h^2$). Because the squaring function penalizes larger numbers much more harshly than smaller ones (reducing $10 \to 9$ saves $10^2 - 9^2 = 19$, whereas reducing $3 \to 2$ saves $3^2 - 2^2 = 5$), the most optimal strategy is always to shave sand off the tallest piles first. 

In this problem, the difference between $nums1[i]$ and $nums2[i]$ can be modified by either increasing or decreasing values using $k_1 + k_2$ total operations. Because shifting $nums1[i]$ towards $nums2[i]$ is interchangeable with shifting $nums2[i]$ towards $nums1[i]$, we can pool both operation pools into a single budget: $mods = k_1 + k_2$. The target then becomes minimizing $\sum |nums1[i] - nums2[i]|^2$.

Since the maximum possible difference between any two values given the problem constraints is $100,000$, we do not need an $O(N \log N)$ heap or sorting algorithm. Instead, we can use a **counting sort / bucket array** where index $d$ stores how many pairs currently have a difference of $d$. We then sweep downward from the maximum difference to $1$, shifting frequencies down by $1$ unit at each step until the modification budget $mods$ is exhausted.

### Algorithm Visualized

```mermaid
flowchart TD
    A[Calculate absolute differences delta = |nums1[i] - nums2[i]|] --> B[Populate freq bucket array and sum total deltas]
    B --> C{mods >= total?}
    C -- Yes --> D[Return 0: All differences can be reduced to 0]
    C -- No --> E[Iterate delta from max_delta down to 1]
    
    subgraph Bucket Shift & Summation
        E --> F{freq[delta] > 0?}
        F -- No --> G[Continue to next delta]
        F -- Yes --> H{mods > 0?}
        H -- Yes --> I[move = min of mods and freq[delta]]
        I --> J[freq[delta] -= move<br>freq[delta - 1] += move<br>mods -= move]
        H -- No --> K[No ops left to shift this delta]
        J --> L[Accumulate remaining freq[delta] * delta^2 to sum]
        K --> L
        L --> M[delta = delta - 1]
        M --> E
    end

    E -- delta reached 0 --> N[Return final sum]
```

### Approach

1. **Calculate Differences & Total Operations:**
   - Define a fixed-size frequency array `freq` up to `MAX_DELTA = 100000`.
   - Iterate through the inputs to compute $\Delta_i = |nums1[i] - nums2[i]|$.
   - Record the frequency of each difference, track the global `max_delta`, and sum the total absolute difference `total`.

2. **Early Exit Optimization:**
   - If the combined operation budget `mods = k1 + k2` is greater than or equal to `total`, we can completely nullify every single difference to $0$. Return $0$ immediately.

3. **Greedy Level-by-Level Shifting:**
   - Sweep backwards from `max_delta` down to $1$.
   - For each difference `delta`, if `freq[delta] > 0` and we have remaining operations (`mods > 0`):
     - Take `move = min(mods, freq[delta])` items of size `delta` and reduce them by $1$ to size `delta - 1`.
     - Decrement `freq[delta]` by `move`, increment `freq[delta - 1]` by `move`, and subtract `move` from `mods`.
   - Any elements that could not be shifted remain at size `delta`. Add their squared contribution (`freq[delta] * delta * delta`) to the running total `sum`.
   - Items shifted to `delta - 1` will be processed in the immediate next iteration of the loop.

4. **Termination:**
   - When `delta` reaches $0$, all elements have either been counted at their final values or shifted to $0$ (which contributes $0^2 = 0$). Return `sum`.

### Detailed Code Analysis

```cpp
long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
    const int n = nums1.size();
```
- Retrieves the array size $n$. Both input vectors are guaranteed to have equal size.

```cpp
    // Track deltas between nums1 and nums2 with counting sort buckets
    const int MAX_DELTA = 100000;
    std::vector<int> freq(MAX_DELTA + 1, 0);
    int max_delta = 0;
    int64_t total = 0;
    for (int i = 0; i < n; ++i) {
        int delta = std::abs(nums1[i] - nums2[i]);
        ++freq[delta];
        max_delta = std::max(max_delta, delta);
        total += delta;
    }
```
- `MAX_DELTA` is bounded at $100,000$ because $1 \le nums1[i], nums2[i] \le 10^5$.
- `freq` acts as a direct-address bucket array where `freq[d]` indicates the count of indices $i$ where $|nums1[i] - nums2[i]| = d$.
- `total` uses a 64-bit signed integer (`int64_t`) to prevent integer overflow since $N \times \max(\Delta) = 10^5 \times 10^5 = 10^{10}$, which exceeds a 32-bit signed integer capacity ($2 \times 10^9$).

```cpp
    int64_t mods = static_cast<int64_t>(k1) + k2;
    if (mods >= total) {
        return 0;
    }
```
- `mods` aggregates $k1 + k2$. Since $k1, k2 \le 10^9$, their sum can reach $2 \times 10^9$, safe in standard 32-bit signed, but casting to `int64_t` protects against boundary overflows and matches the type of `total`.
- If `mods >= total`, we have enough operations to reduce every difference to $0$, yielding an optimal answer of $0$ in $O(1)$ time.

```cpp
    // Reduce larger deltas first and calculate sum of squares in the same pass
    int64_t sum = 0;
    for (int delta = max_delta; delta > 0; --delta) {
        if (freq[delta] == 0) {
            continue;
        }

        if (mods > 0) {
            // If we have mods left to spend, subtract from highest delta count
            int move = static_cast<int>(std::min<int64_t>(mods, freq[delta]));
            freq[delta] -= move;
            freq[delta - 1] += move;
            mods -= move;
        }

        // Add squared sum for any remaining instances of this delta
        sum += static_cast<int64_t>(freq[delta]) * delta * delta;
    }

    return sum;
}
```
- The loop runs from `max_delta` down to $1$. It intentionally stops before `delta = 0` because differences of $0$ do not contribute to the sum of squares ($0^2 = 0$).
- When `mods > 0`, it computes `move = min(mods, freq[delta])`.
  - `freq[delta] -= move`: removes these elements from level `delta`.
  - `freq[delta - 1] += move`: pushes them to level `delta - 1`. In the subsequent loop cycle (`delta - 1`), these items will be considered for further reduction if `mods` is still positive.
  - `mods -= move`: deducts the operations used.
- `sum += static_cast<int64_t>(freq[delta]) * delta * delta`: Any elements remaining at `delta` can never be reduced further (either because `mods` hit 0 or only a portion of the elements were shifted). Their final squared contribution is added to `sum`.
- Casting `freq[delta]` to `int64_t` before multiplying by `delta * delta` prevents 32-bit overflow before accumulation into `sum`.

### Code

```cpp
long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
    const int n = nums1.size();

    // Track deltas between nums1 and nums2 with counting sort buckets
    const int MAX_DELTA = 100000;
    std::vector<int> freq(MAX_DELTA + 1, 0);
    int max_delta = 0;
    int64_t total = 0;
    for (int i = 0; i < n; ++i) {
        int delta = std::abs(nums1[i] - nums2[i]);
        ++freq[delta];
        max_delta = std::max(max_delta, delta);
        total += delta;
    }

    int64_t mods = static_cast<int64_t>(k1) + k2;
    if (mods >= total) {
        return 0;
    }

    // Reduce larger deltas first and calculate sum of squares in the same pass
    int64_t sum = 0;
    for (int delta = max_delta; delta > 0; --delta) {
        if (freq[delta] == 0) {
            continue;
        }

        if (mods > 0) {
            // If we have mods left to spend, subtract from highest delta count
            int move = static_cast<int>(std::min<int64_t>(mods, freq[delta]));
            freq[delta] -= move;
            freq[delta - 1] += move;
            mods -= move;
        }

        // Add squared sum for any remaining instances of this delta
        sum += static_cast<int64_t>(freq[delta]) * delta * delta;
    }

    return sum;
}
```

### Complexity

- **Time:** $O(N + M)$, where $N$ is the number of elements in `nums1` and $M$ is $\max(|nums1[i] - nums2[i]|) \le 100,000$.
  - First pass: $O(N)$ to compute differences and populate the frequency buckets.
  - Second pass: At most $M$ iterations in the backward loop from `max_delta` down to $1$. Each iteration performs constant $O(1)$ arithmetic.
  - Total time complexity is strictly linear, easily outperforming $O(N \log N)$ sorting and priority queue solutions.

- **Space:** $O(M)$ auxiliary space, where $M = 100,000$.
  - A single static-sized buffer of size $100,001$ integers is allocated for `freq`, requiring roughly $400 \text{ KB}$ of memory regardless of the input size $N$.

---

## 🕵️‍♂️ Follow-up Questions

### 1. What if the values of `nums1[i]` and `nums2[i]` were up to $10^9$ instead of $10^5$?
If the maximum difference can be up to $10^9$, allocating a frequency array of size $10^9$ will result in a Memory Limit Exceeded (MLE) or Out-Of-Memory (OOM) error, and an $O(M)$ loop would Time Out.

**Alternative Approach:**
Use **Binary Search on the Answer (Water-level / Threshold method)**:
- Binary search for the maximum threshold difference $T \in [0, \max(\Delta)]$.
- A threshold $T$ is feasible if $\sum \max(0, \Delta_i - T) \le k_1 + k_2$.
- After finding the optimal target ceiling $T$, compute how many spare operations remain, distribute them to decrement values from $T$ to $T - 1$, and compute the squared sum.
- **Complexity:** $O(N \log(\max(\Delta)))$ time and $O(1)$ extra space.

### 2. Why does a standard Max-Heap / Priority Queue approach result in Time Limit Exceeded (TLE) here?
A naive greedy approach pushes all differences into a max-heap and decrements the top element by $1$ per operation:
- With $k_1 + k_2 \le 2 \times 10^9$, performing one operation at a time takes $O((k_1 + k_2) \log N)$ time, which will time out by several orders of magnitude.
- Even if grouping duplicate values in a heap as pairs `(delta, count)`, maintaining and rebuilding the heap takes $O(N \log N)$ time, which has a significantly higher constant factor compared to the direct bucket sweep $O(N + M)$.