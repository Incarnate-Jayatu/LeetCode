<h2><a href="https://leetcode.com/problems/island-perimeter">463. Island Perimeter</a></h2>

<p>You are given <code>row x col</code> <code>grid</code> representing a map where <code>grid[i][j] = 1</code> represents&nbsp;land and <code>grid[i][j] = 0</code> represents water.</p>

<p>Grid cells are connected <strong>horizontally/vertically</strong> (not diagonally). The <code>grid</code> is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).</p>

<p>The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/island.png" style="width: 221px; height: 213px;">
<pre><strong>Input:</strong> grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
<strong>Output:</strong> 16
<strong>Explanation:</strong> The perimeter is the 16 yellow stripes in the image above.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1]]
<strong>Output:</strong> 4
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0]]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>row == grid.length</code></li>
	<li><code>col == grid[i].length</code></li>
	<li><code>1 &lt;= row, col &lt;= 100</code></li>
	<li><code>grid[i][j]</code> is <code>0</code> or <code>1</code>.</li>
	<li>There is exactly one island in <code>grid</code>.</li>
</ul>


---

# 🛍️ Island-Perimeter | Explained

## Approach 1: Counting Cells and Shared Internal Edges

### Intuition
Think of each land cell as a square modular building block (like a Lego brick). Standing completely alone, a single block has $4$ exposed walls contributing to the outer perimeter. 

When you snap two square blocks together, their touching interface is sealed off inside the structure. This single connection eliminates **two** exposed wall segments from the total perimeter—one from each block. 

Instead of checking all four directions for every land cell to count which boundaries touch water, we can count:
1. The total number of land blocks (`islands`).
2. The total number of shared interfaces between adjacent land blocks (`neighbors`).

Since checking every direction would count each shared edge twice, we only check in two directions (e.g., **Up** and **Left**). Each detected connection corresponds to exactly one shared edge, subtracting $2$ from the total theoretical perimeter:
$$\text{Perimeter} = (\text{islands} \times 4) - (\text{neighbors} \times 2)$$


### Approach
1. **Initialize Counters**:
   - `islands` keeps track of the total number of land cells (`1`s).
   - `neighbors` tracks the number of shared borders between two land cells.
2. **Scan the Matrix**:
   - Loop through every cell `(i, j)` in the grid from top-to-bottom, left-to-right.
3. **Handle Land Cells**:
   - If `grid[i][j] == 1`:
     - Increment `islands` by $1$.
     - Check the **Top** neighbor `(i - 1, j)`. If it is also land (`1`), increment `neighbors` by $1$.
     - Check the **Left** neighbor `(i, j - 1)`. If it is also land (`1`), increment `neighbors` by $1$.
   - *(Note: We deliberately ignore Down and Right neighbors because future iterations will naturally inspect those edges as Up and Left, preventing double-counting.)*
4. **Compute Final Answer**:
   - Compute and return `(islands * 4) - (neighbors * 2)`.

### Detailed Code Analysis

- **Lines 4–7:**
  ```cpp
  int islands = 0;
  int neighbors = 0;
  int rows = grid.size();
  int cols = grid[0].size();
  ```
  We initialize our tracking variables and extract the grid dimensions. Primitive integers are used for counters, requiring $O(1)$ memory.

- **Lines 8–10:**
  ```cpp
  for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
          if (grid[i][j] == 1) {
              islands++;
  ```
  We execute a standard row-major nested traversal. Whenever `grid[i][j] == 1`, we have discovered a piece of land, so we immediately increment `islands`. Every land cell inherently begins with $4$ potential perimeter segments.

- **Lines 12–14:**
  ```cpp
  if (i > 0 && grid[i - 1][j] == 1) {
      neighbors++;
  }
  ```
  We guard against an out-of-bounds read (`i > 0`) before inspecting the cell directly above (`grid[i - 1][j]`). If the top cell is also land, an internal border exists.

- **Lines 15–17:**
  ```cpp
  if (j > 0 && grid[i][j - 1] == 1) {
      neighbors++;
  }
  ```
  Similarly, we check bounds (`j > 0`) before inspecting the cell directly to the left (`grid[i][j - 1]`). If it is land, we record another shared interface.

- **Line 21:**
  ```cpp
  return (islands * 4) - (neighbors * 2);
  ```
  Each shared interface strips $1$ edge from each of the two adjacent cells, meaning $2$ perimeter edges disappear per neighbor relationship. We return the remaining exposed edges.

### Code
```cpp
class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int islands = 0;
        int neighbors = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    islands++;
                    if (i > 0 && grid[i - 1][j] == 1) {
                        neighbors++;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        neighbors++;
                    }
                }
            }
        }
        return (islands * 4) - (neighbors * 2);
    }
};
```

### Complexity
- **Time:** $O(R \times C)$, where $R$ is the number of rows and $C$ is the number of columns. Every cell in the grid is visited exactly once, and neighbor checks take $O(1)$ constant time.
- **Space:** $O(1)$ auxiliary space. We only use a few integer variables (`islands`, `neighbors`, `rows`, `cols`, `i`, `j`) without allocating any extra data structures or recursive call stacks.

---

## 🕵️‍♂️ Follow-up Questions (Optional)

1. **Does this mathematical formulation still hold if the island has internal lakes (holes)?**
   - **Answer:** Yes, it works automatically. A lake inside an island consists of water cells (`0`). Any land cell bordering an internal lake will not detect a land neighbor in that direction, leaving that edge un-subtracted. Therefore, the internal perimeter surrounding the lake is naturally included in the total count.

2. **How would you adapt this solution if the grid contained multiple disconnected islands and you needed the perimeter of the largest island?**
   - **Answer:** Rather than a simple full-grid pass with global counters, you would use Breadth-First Search (BFS), Depth-First Search (DFS), or a Disjoint Set Union (DSU / Union-Find). When finding an unvisited `1`, run a traversal to accumulate `islands` and `neighbors` strictly within that connected component, calculate that component's perimeter, and update a running maximum.
