<h2><a href="https://leetcode.com/problems/two-sum">1. Two Sum</a></h2>

<p>You are given an array of integers <code>nums</code>&nbsp;and an integer <code>target</code>, return <em>indices of the two numbers such that they add up to <code>target</code></em>.</p>

<p>You may assume that each input would have <strong><em>exactly</em> one solution</strong>, and you may not use the <em>same</em> element twice.</p>

<p>You can return the answer in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,7,11,15], target = 9
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> Because nums[0] + nums[1] == 9, we return [0, 1].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,4], target = 6
<strong>Output:</strong> [1,2]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,3], target = 6
<strong>Output:</strong> [0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><strong>Only one valid answer exists.</strong></li>
</ul>

<p>&nbsp;</p>
<strong>Follow-up:&nbsp;</strong>Can you come up with an algorithm that is less than <code>O(n<sup>2</sup>)</code><font face="monospace">&nbsp;</font>time complexity?

---

# 🛍️ Two-Sum | Explained

## Approach 1: Two-Pass Hash Map (Look-Up Table)

### Intuition
Imagine you are at a coat check at an event where every coat has a number written on its tag. You need to find two coats whose tag numbers add up to a target number, say $10$. 

Instead of randomly pairing up coats one by one (a brute-force search), you first create an index notebook where you write down the coat number as the key and its locker rack position (index) as the value. 

Once your directory is fully populated, you walk through the coats a second time. For each coat labeled $x$, you compute its exact needed pair $y = 10 - x$. You then immediately flip open your notebook and check: *"Is $y$ in the directory, and is it not the exact same coat I am currently holding?"* If it is, you retrieve both locker numbers on the spot.

### Algorithm Visualized

```mermaid
flowchart TD
    Start([Start: nums, target]) --> Phase1[Phase 1: Build Hash Map]
    
    subgraph Pass1 [Pass 1: Population]
        Phase1 --> Loop1{i < nums.size?}
        Loop1 -- Yes --> Insert["h[nums[i]] = i"]
        Insert --> Next1[i++] --> Loop1
        Loop1 -- No --> Phase2[Phase 2: Complement Search]
    end

    subgraph Pass2 [Pass 2: Lookup]
        Phase2 --> Loop2{i < nums.size?}
        Loop2 -- Yes --> Calc["y = target - nums[i]"]
        Calc --> Check{"h.find(y) != h.end() && h[y] != i"}
        Check -- True --> Found([Return {i, h[y]}])
        Check -- False --> Next2[i++] --> Loop2
        Loop2 -- No --> Throw([Throw invalid_argument])
    end
```

### Approach
The algorithm solves the problem in two distinct passes:

1. **Pass 1 (Build the Map):** Iterate through the array `nums` from start to finish. Store each element's value as a key in an `std::unordered_map` and its index `i` as the mapped value. If duplicate numbers exist, subsequent indices overwrite earlier ones, which is acceptable because we only need one valid pairing index.
2. **Pass 2 (Find the Complement):** Iterate through the array a second time. For each element `nums[i]`:
   - Calculate the required complement: `y = target - nums[i]`.
   - Query the hash map for `y`.
   - Ensure the complement found is **not** the current element itself (`h[y] != i`).
   - If both conditions hold, return the pair of indices `{i, h[y]}` immediately.
3. **Fallback:** If no two elements sum up to the target, throw an exception indicating no solution exists.

### Detailed Code Analysis

- **Header Inclusions & Setup:**
  ```cpp
  #include <vector>
  #include <unordered_map>
  using namespace std;
  ```
  The solution relies on `std::unordered_map` (implemented as a hash table) to achieve average $O(1)$ lookups, and `std::vector` for dynamic array storage and returning results.

- **Phase 1 — Building the Index Map:**
  ```cpp
  unordered_map<int, int> h;
  for (int i = 0; i < nums.size(); ++i) {
      h[nums[i]] = i;
  }
  ```
  Here, we declare a hash table `h`. The loop iterates through each element of `nums`. By executing `h[nums[i]] = i`, we map the number to its index. If a duplicate element is encountered, the index is simply updated to the most recent one.

- **Phase 2 — Searching for the Complement:**
  ```cpp
  for (int i = 0; i < nums.size(); ++i) {
      int y = target - nums[i];
      if (h.find(y) != h.end() && h[y] != i) {
          return {i, h[y]};
      }
  }
  ```
  We traverse the array again. For index `i`:
  - `int y = target - nums[i];` computes the required counterpart.
  - `h.find(y) != h.end()` checks if `y` was recorded in the hash table.
  - `h[y] != i` is a critical guard condition preventing an element from pairing with itself (e.g., if `target = 6`, `nums[i] = 3`, and only one `3` exists, `h[3]` would equal `i`, which is invalid).
  - If both conditions evaluate to true, `{i, h[y]}` is returned as an initializer list constructing a `std::vector<int>`.

- **Exception Handling:**
  ```cpp
  throw invalid_argument("No two sum solution");
  ```
  *(Note: String quotes added for valid compilation).* If the loop terminates without finding a pair, the code throws a standard `std::invalid_argument` exception rather than returning an invalid/empty vector.

### Code
```cpp
#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h;
        
        // Pass 1: Populate hash map with value -> index mapping
        for (int i = 0; i < nums.size(); ++i) {
            h[nums[i]] = i;
        }
        
        // Pass 2: Find complement
        for (int i = 0; i < nums.size(); ++i) {
            int y = target - nums[i];
            if (h.find(y) != h.end() && h[y] != i) {
                return {i, h[y]};
            }
        }
        
        throw invalid_argument("No two sum solution");
    }
};
```

### Complexity
- **Time:** $O(N)$ on average, where $N$ is the number of elements in `nums`. We perform two linear passes over the array of size $N$. Inside each pass, hash map insertions and lookups take $O(1)$ average time. In the worst-case scenario (severe hash collisions), hash map operations degrade to $O(N)$, resulting in an overall worst-case time complexity of $O(N^2)$.
- **Space:** $O(N)$ auxiliary space. In the worst case, where all elements in `nums` are distinct, the `unordered_map` will store $N$ key-value pairs.

---

## 🕵️‍♂️ Follow-up Questions

1. **Can we optimize this to a One-Pass Hash Map?**
   - **Answer:** Yes. Instead of pre-populating the entire hash map in advance, we can look up the complement $y = \text{target} - \text{nums}[i]$ in the map *before* inserting `nums[i]`. This not only reduces the number of iterations by up to 50% on average, but also inherently eliminates the need to check `h[y] != i` since the current element has not been inserted yet.

2. **What if the array is already sorted?**
   - **Answer:** If the input array is sorted, we can use the **Two-Pointer Approach** (one pointer at the beginning, one at the end) to achieve $O(N)$ time complexity with $O(1)$ auxiliary space, eliminating the hash map overhead entirely.