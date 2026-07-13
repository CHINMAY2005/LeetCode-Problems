# 0695 - Max Area of Island

## Problem
You are given an `m x n` binary matrix `grid`. An island is a group of `1`s (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value `1` in the island.

Return the maximum area of an island in `grid`. If there is no island, return `0`.

## Key Insight
We can traverse the grid and start a Depth-First Search (DFS) or Breadth-First Search (BFS) whenever we encounter land (`1`). By changing traversed land cells from `1` to `0` (sinking the island), we avoid visiting the same land cell multiple times and do not require additional memory for a "visited" set.

## Approach
1. Loop through each cell in the grid.
2. If the cell contains a `1`, initiate a DFS:
   - Mark the current cell as visited by setting `grid[r][c] = 0`.
   - Calculate the area as `1` plus the sum of DFS results from all 4 adjacent directions.
3. Keep track of the maximum area encountered.
4. Return the maximum area.

## Why It Works
Using recursive DFS allows us to explore the complete connected component of land starting from any cell. Sinking cells in-place ensures each cell is processed exactly once, resulting in a clean and efficient traversal.

## Complexity
- Time: `O(m * n)` where `m` is the number of rows and `n` is the number of columns. Each cell is visited at most a constant number of times.
- Space: `O(m * n)` in the worst case for the recursive call stack (if the entire grid is one island).

## Python
```python
class Solution:
    def maxAreaOfIsland(self, grid):
        if not grid:
            return 0
        
        m, n = len(grid), len(grid[0])
        max_area = 0
        
        def dfs(r, c):
            if r < 0 or r >= m or c < 0 or c >= n or grid[r][c] == 0:
                return 0
            grid[r][c] = 0
            area = 1
            area += dfs(r + 1, c)
            area += dfs(r - 1, c)
            area += dfs(r, c + 1)
            area += dfs(r, c - 1)
            return area

        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1:
                    max_area = max(max_area, dfs(r, c))
                    
        return max_area
```

## Java
```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        
        int m = grid.length;
        int n = grid[0].length;
        int maxArea = 0;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    maxArea = Math.max(maxArea, dfs(grid, r, c));
                }
            }
        }
        
        return maxArea;
    }
    
    private int dfs(int[][] grid, int r, int c) {
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = 0;
        int area = 1;
        area += dfs(grid, r + 1, c);
        area += dfs(grid, r - 1, c);
        area += dfs(grid, r, c + 1);
        area += dfs(grid, r, c - 1);
        return area;
    }
}
```

## C++
```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, dfs(grid, r, c));
                }
            }
        }
        
        return maxArea;
    }

private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= (int)grid.size() || c < 0 || c >= (int)grid[0].size() || grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = 0;
        return 1 + dfs(grid, r + 1, c) 
                 + dfs(grid, r - 1, c) 
                 + dfs(grid, r, c + 1) 
                 + dfs(grid, r, c - 1);
    }
};
```
