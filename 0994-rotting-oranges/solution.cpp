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
