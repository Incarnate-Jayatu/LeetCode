<h2><a href="https://leetcode.com/problems/number-of-good-pairs">1512. Number of Good Pairs</a></h2>

<p>Given an array of integers <code>nums</code>, return <em>the number of <strong>good pairs</strong></em>.</p>

<p>A pair <code>(i, j)</code> is called <em>good</em> if <code>nums[i] == nums[j]</code> and <code>i</code> &lt; <code>j</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,1,1,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Each pair in the array are <em>good</em>.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


---

# 🛍️ Number-of-Good-Pairs | Explained

## Approach 1: Brute Force (Nested Loops / Pairwise Comparison)

### Intuition
Imagine you are a teacher grading a group of students wearing numbered jerseys. You want to find every unique pair of students who are wearing the exact same jersey number. A natural and direct way to do this is to stand the students in a single-file line. Starting with the first student in line, you have them turn around and look at every student behind them, one by one. Whenever they spot someone with a matching jersey number, they count it as a "good pair." Once that student is done checking everyone behind them, the next student does the exact same thing with whoever is left behind them. 

Because each student only compares themselves against students standing *after* them in line, you guarantee two things: you never compare a student to themselves, and you never count the exact same pair twice.

### Algorithm Visualized
```mermaid
flowchart TD
    Start([Start numIdenticalPairs]) --> Init[Initialize pair = 0]
    Init --> OuterLoop{i < nums.size() - 1?}
    OuterLoop -- Yes --> InnerLoopInit[Set j = i + 1]
    InnerLoopInit --> InnerLoop{j < nums.size()?}
    InnerLoop -- Yes --> CheckMatch{nums[i] == nums[j]?}
    CheckMatch -- Yes --> Increment[pair++]
    CheckMatch -- No --> NextJ[j++]
    Increment --> NextJ
    NextJ --> InnerLoop
    InnerLoop -- No --> NextI[i++]
    NextI --> OuterLoop
    OuterLoop -- No --> Return[Return pair]
    Return --> End([End])
```

### Approach
1. **Initialize a Counter:** Create an integer variable `pair` initialized to `0` to keep track of the total number of valid pairs $(i, j)$ where $i < j$ and `nums[i] == nums[j]`.
2. **Outer Loop (`i`):** Iterate through the vector using index `i` from `0` up to `nums.size() - 2`. The element `nums[i]` represents the first element of our potential pair. We stop at `nums.size() - 2` because the last element has no subsequent elements to pair with.
3. **Inner Loop (`j`):** For every `i`, iterate through the vector using index `j` starting strictly from `i + 1` up to `nums.size() - 1`. This naturally enforces the constraint $i < j$.
4. **Compare and Count:** Inside the inner loop, evaluate whether `nums[i] == nums[j]`. If true, increment the `pair` counter.
5. **Return Result:** After all possible pairs have been evaluated, return `pair`.

### Detailed Code Analysis

```cpp
int pair=0;
```
- A local 32-bit signed integer variable `pair` is allocated on the stack and initialized to `0`. This acts as an accumulator for the total number of matching pairs discovered.

```cpp
for(int i=0; i<nums.size()-1; i++){
```
- The outer loop variable `i` starts at index `0`.
- **Subtle C++ Detail:** `nums.size()` returns an unsigned integer type (`std::size_t`). When comparing `int i` to `nums.size() - 1`, signed-to-unsigned conversion can occur. If `nums` were ever empty, `nums.size() - 1` would underflow to `SIZE_MAX`, causing unintended behavior. However, per LeetCode constraints ($1 \le \text{nums.length} \le 100$), this does not crash, but using `std::size_t` or casting avoids signed/unsigned mismatch warnings.
- The boundary `i < nums.size() - 1` ensures that the outer loop stops before the last element, as index `nums.size() - 1` cannot form a forward-looking pair.

```cpp
    for(int j=i+1; j<nums.size(); j++){
```
- The inner loop variable `j` is initialized to `i + 1`. This structural invariant directly satisfies the problem requirement that $i < j$.
- It scans every index to the right of `i` through the end of the vector (`nums.size() - 1`).

```cpp
        if(nums[i] == nums[j])
            pair++;
```
- For the pair of indices $(i, j)$, direct random access into the `std::vector` is performed via `nums[i]` and `nums[j]`, which runs in $O(1)$ time.
- If the values are identical, `pair` is post-incremented by `1`.

```cpp
return pair;
```
- Once both loops complete their iterations, the final accumulated count is returned to the caller.

### Code
```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pair = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j])
                    pair++;
            }
        }
        return pair;
    }
};
```

### Complexity
- **Time: $O(N^2)$** — Where $N$ is the number of elements in `nums`. The outer loop runs $N - 1$ times, and for each iteration $i$, the inner loop executes $(N - 1 - i)$ times. The total number of comparisons is $(N - 1) + (N - 2) + \dots + 1 = \frac{N(N - 1)}{2}$, resulting in quadratic time complexity.
- **Space: $O(1)$** — The algorithm uses a fixed number of auxiliary variables (`pair`, `i`, `j`), requiring no dynamic memory allocation or auxiliary data structures. Memory consumption remains strictly constant regardless of the input size.

---

## 🕵️‍♂️ Follow-up Questions (Optional)

### 1. How would you optimize this solution from $O(N^2)$ to $O(N)$ time?
Instead of comparing all pairs, use a frequency array or hash map (`unordered_map<int, int>` in C++). As you iterate through the array, if a number has already been seen $k$ times, seeing it again allows it to pair with all $k$ previously seen instances. Thus, you can add the current count to `pair` and then increment the count:

```cpp
int numIdenticalPairs(vector<int>& nums) {
    int count[101] = {0}; // Since 1 <= nums[i] <= 100
    int pairs = 0;
    for (int x : nums) {
        pairs += count[x];
        count[x]++;
    }
    return pairs;
}
```
This runs in $O(N)$ time and $O(1)$ auxiliary space (since the value range is bounded up to 100).

### 2. What edge cases should be considered with the nested loop condition `i < nums.size() - 1`?
If `nums` has a length of `0`, calling `.size() - 1` on an unsigned `std::size_t` causes an integer underflow, wrapping around to `18446744073709551615` (on 64-bit systems). In that scenario, `i < nums.size() - 1` evaluates to `true`, causing an out-of-bounds access. While LeetCode guarantees $N \ge 1$, production-grade code should either check `if (nums.empty()) return 0;` or use `for (size_t i = 0; i + 1 < nums.size(); ++i)` to prevent underflow.