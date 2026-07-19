# 0036 - Valid Sudoku

## Problem
Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.

Note:
- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

## Key Insight
Instead of keeping a set of values for rows, columns, and sub-boxes, we can utilize bit manipulation to represent the digits seen in each row, column, and box. This avoids the overhead of object creation or hash set operations, enabling extremely fast validation.

## Approach
1. Initialize three arrays of integers of size 9 to represent bitmasks for the rows, columns, and $3 \times 3$ sub-boxes: `rows`, `cols`, and `boxes`.
2. Iterate through each cell `(r, c)` of the board:
   - If the cell value is `'.'`, skip it.
   - Convert the cell character value to an integer digit offset: `digit = val - '1'` (value in range `0` to `8`).
   - Create a bitmask representing this digit: `mask = 1 << digit`.
   - Calculate the index of the corresponding $3 \times 3$ box: `boxIdx = (r / 3) * 3 + (c / 3)`.
   - **Check for duplicate**: Check if the bit `digit` is already set in `rows[r]`, `cols[c]`, or `boxes[boxIdx]`. If any check evaluates to true, return `false`.
   - **Mark as seen**: Set the bit `digit` in `rows[r]`, `cols[c]`, and `boxes[boxIdx]` using the bitwise OR operator (`|=`).
3. If no conflicts are detected after inspecting the entire board, return `true`.

## Why It Works
Using the $i$-th bit of an integer as a flag to record whether digit $i+1$ has been seen allows us to perform validation checks in constant $O(1)$ time. The expression `(r / 3) * 3 + (c / 3)` maps the 2D matrix coordinate `(r, c)` to a flat 1D index representing one of the nine $3 \times 3$ boxes.

## Complexity
- Time: `O(1)` as the board is always `9 x 9` in size, meaning we always perform exactly 81 steps.
- Space: `O(1)` since we only store three static arrays of size 9.

## Python
```python
class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9
        
        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == '.':
                    continue
                    
                digit = int(val) - 1
                mask = 1 << digit
                box_idx = (r // 3) * 3 + (c // 3)
                
                # Check duplication
                if (rows[r] & mask) or (cols[c] & mask) or (boxes[box_idx] & mask):
                    return False
                    
                # Mark as seen
                rows[r] |= mask
                cols[c] |= mask
                boxes[box_idx] |= mask
                
        return True
```

## Java
```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[] rows = new int[9];
        int[] cols = new int[9];
        int[] boxes = new int[9];
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') {
                    continue;
                }
                
                int digit = val - '1';
                int mask = 1 << digit;
                int boxIdx = (r / 3) * 3 + (c / 3);
                
                // Check duplication
                if ((rows[r] & mask) != 0 || (cols[c] & mask) != 0 || (boxes[boxIdx] & mask) != 0) {
                    return false;
                }
                
                // Mark as seen
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIdx] |= mask;
            }
        }
        
        return true;
    }
}
```

## C++
```cpp
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') {
                    continue;
                }
                
                int digit = val - '1';
                int mask = 1 << digit;
                int boxIdx = (r / 3) * 3 + (c / 3);
                
                // Check duplication
                if ((rows[r] & mask) != 0 || (cols[c] & mask) != 0 || (boxes[boxIdx] & mask) != 0) {
                    return false;
                }
                
                // Mark as seen
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIdx] |= mask;
            }
        }
        
        return true;
    }
};
```
