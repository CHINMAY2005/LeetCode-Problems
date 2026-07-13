# 0994 - Rotting Oranges

## Problem
You are given an `m x n` `grid` where each cell can have one of three values:
- `0` representing an empty cell,
- `1` representing a fresh orange, or
- `2` representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return `-1`.

## Key Insight
Since the rotting process occurs simultaneously for all rotten oranges, we should use Breadth-First Search (BFS). In BFS, we process the queue layer by layer, where each layer represents the oranges that rot at the same minute.

## Approach
1. Scan the grid to count total fresh oranges and enqueue the coordinates of all initially rotten oranges.
2. Initialize `minutes = 0`.
3. Perform BFS layer by layer:
   - For each rotten orange at the current minute, rot its 4-directional fresh neighbors.
   - For each newly rotted neighbor, decrement the fresh orange count and enqueue its coordinates.
   - Increment `minutes` after processing a layer, provided that at least one fresh orange was rotted in this step.
4. After BFS completes, if there are still fresh oranges remaining, return `-1`. Otherwise, return `minutes`.

## Why It Works
BFS naturally models unit-time progression in a grid structure, guaranteeing that the shortest time path to rot each fresh orange is found. 

## Complexity
- Time: `O(m * n)` where `m` is the number of rows and `n` is the number of columns. Every cell is scanned once initially and visited at most a constant number of times during BFS.
- Space: `O(m * n)` to store the queue of rotten oranges in the worst-case scenario.

## Python
```python
from collections import deque

class Solution:
    def orangesRotting(self, grid):
        if not grid:
            return -1
        
        m, n = len(grid), len(grid[0])
        queue = deque()
        fresh_count = 0
        
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 2:
                    queue.append((r, c))
                elif grid[r][c] == 1:
                    fresh_count += 1
                    
        minutes = 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        while queue and fresh_count > 0:
            minutes += 1
            for _ in range(len(queue)):
                r, c = queue.popleft()
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                        grid[nr][nc] = 2
                        fresh_count -= 1
                        queue.append((nr, nc))
                        
        return minutes if fresh_count == 0 else -1
```

## Java
```java
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int orangesRotting(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return -1;
        }
        
        int m = grid.length;
        int n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int freshCount = 0;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    queue.offer(new int[]{r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }
        
        int minutes = 0;
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!queue.isEmpty() && freshCount > 0) {
            minutes++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] curr = queue.poll();
                int r = curr[0];
                int c = curr[1];
                for (int[] dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshCount--;
                        queue.offer(new int[]{nr, nc});
                    }
                }
            }
        }
        
        return freshCount == 0 ? minutes : -1;
    }
}
```

## C++
```cpp
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return -1;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty() && freshCount > 0) {
            minutes++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshCount--;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return freshCount == 0 ? minutes : -1;
    }
};
```
