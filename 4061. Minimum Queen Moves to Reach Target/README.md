<h2><a href="https://leetcode.com/problems/minimum-queen-moves-to-reach-target">4061. Minimum Queen Moves to Reach Target</a></h2>

<p>There is an <code>8 x 8</code> empty chessboard with <strong>1-indexed</strong> rows and columns.</p>

<p>You are given an array <code>source = [sr, sc]</code> representing the starting position of a <strong>queen</strong>, and an array <code>target = [tr, tc]</code> representing the target position.</p>

<p>In one move, the queen travels one or more squares along a single <strong>row</strong>, <strong>column</strong>, or <strong>diagonal</strong>, staying within the board.</p>

<p>Return the <strong>minimum</strong> number of moves for the queen to land <strong>exactly</strong> on <code>target</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">source = [8,1], target = [1,8]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p><strong>​​​​​​​<img alt="" src="https://assets.leetcode.com/uploads/2026/08/31/111.png" style="width: 300px; height: 303px;">​​​​​​​</strong></p>

<p>A single diagonal move takes the queen straight from <code>(8, 1)</code> to <code>(1, 8)</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">source = [4,2], target = [1,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2026/09/14/1e602ed4-c525-4be4-a6a9-6804cb7d2a55.png" style="width: 300px; height: 305px;">​​​​​​​</p>

<p>The queen moves from <code>(4, 2)</code> to <code>(4, 3)</code>, then from <code>(4, 3)</code> to <code>(1, 3)</code>, reaching the target in 2 moves.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">source = [1,1], target = [1,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>The queen is already at the target position, so no moves are needed.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong>​​​​​​​</p>

<ul>
	<li><code>source == [sr, sc]</code></li>
	<li><code>target == [tr, tc]</code></li>
	<li><code>1 &lt;= sr, sc, tr, tc &lt;= 8</code></li>
</ul>


---

# 🛍️ Minimum-Queen-Moves-to-Reach-Target | Explained

## Approach 1: Constant-Time Geometric Classification

### Intuition
In the game of chess, a queen is the most versatile piece: it can move any number of unoccupied squares horizontally, vertically, or diagonally. 

Think of the queen as having eight distinct laser sights pointing outward along the cardinal directions ($N, S, E, W$) and intercardinal directions ($NE, NW, SE, SW$). 
- If the target is already at your current location, you do not need to move at all ($0$ moves).
- If the target intersects any of those eight laser lines, the queen can reach it in a single strike ($1$ move).
- If the target is not on any of these lines, the queen can simply pick an intermediate square where one of its attack lines intersects one of the target's attack lines (for example, moving horizontally to match the target's column, then moving vertically to the target). On an unobstructed board, this intersection always exists, guaranteeing reachability in at most $2$ moves.

### Algorithm Visualized


### Approach
1. **Coordinate Extraction**: Unpack the `source` and `target` 2D coordinates into distinct integer variables `(rowOne, colOne)` and `(rowTwo, colTwo)`.
2. **Identical Position Check (0 Moves)**:
   - Check if `rowOne == rowTwo` and `colOne == colTwo`.
   - If both conditions are satisfied, the queen is already on the target square. Return `0`.
3. **Single Move Colinearity Check (1 Move)**:
   - **Horizontal Alignment**: `rowOne == rowTwo` (same rank).
   - **Vertical Alignment**: `colOne == colTwo` (same file).
   - **Diagonal Alignment**: The slope between the two points must be $\pm 1$. This can be checked by verifying if the absolute difference in rows equals the absolute difference in columns: `Math.abs(rowOne - rowTwo) == Math.abs(colOne - colTwo)`.
   - If any of these three conditions hold, return `1`.
4. **Default Multi-Move Path
