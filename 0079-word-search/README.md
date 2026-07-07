# 0079 - Word Search

## Problem
Given an `m x n` grid of characters and a word, determine whether the word exists in the grid.

The word can be formed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same cell may not be used more than once.

## Key Insight
This is a depth-first search with backtracking problem.

At each step, try to continue the word from the current cell by moving in the four possible directions.

## Approach
Start a search from every cell that matches the first character of the word.

- Mark the current cell as visited.
- Recursively explore up, down, left, and right for the next character.
- Restore the cell before returning so other paths can use it.

If any path matches the full word, return true.

## Why It Works
The search explores every possible simple path that could spell the word, and the visited marking prevents reusing a cell in the same path.

Because every valid placement must begin at some cell and follow adjacent moves, the backtracking search is complete.

## Complexity
- Time: `O(m * n * 4^L)`
- Space: `O(L)`

Here `L` is the length of the word.

## Python
```python
class Solution:
    def exist(self, board, word):
        rows = len(board)
        cols = len(board[0])

        def backtrack(r, c, index):
            if index == len(word):
                return True
            if r < 0 or r >= rows or c < 0 or c >= cols:
                return False
            if board[r][c] != word[index]:
                return False

            temp = board[r][c]
            board[r][c] = '#'

            found = (
                backtrack(r + 1, c, index + 1)
                or backtrack(r - 1, c, index + 1)
                or backtrack(r, c + 1, index + 1)
                or backtrack(r, c - 1, index + 1)
            )

            board[r][c] = temp
            return found

        for r in range(rows):
            for c in range(cols):
                if backtrack(r, c, 0):
                    return True

        return False
```

## Java
```java
class Solution {
    public boolean exist(char[][] board, String word) {
        int rows = board.length;
        int cols = board[0].length;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (backtrack(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    private boolean backtrack(char[][] board, String word, int r, int c, int index) {
        if (index == word.length()) {
            return true;
        }
        if (r < 0 || r >= board.length || c < 0 || c >= board[0].length) {
            return false;
        }
        if (board[r][c] != word.charAt(index)) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        boolean found = backtrack(board, word, r + 1, c, index + 1)
            || backtrack(board, word, r - 1, c, index + 1)
            || backtrack(board, word, r, c + 1, index + 1)
            || backtrack(board, word, r, c - 1, index + 1);

        board[r][c] = temp;
        return found;
    }
}
```

## C++
```cpp
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = (int)board.size();
        int cols = (int)board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (backtrack(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, const string& word, int r, int c, int index) {
        if (index == (int)word.size()) {
            return true;
        }
        if (r < 0 || r >= (int)board.size() || c < 0 || c >= (int)board[0].size()) {
            return false;
        }
        if (board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = backtrack(board, word, r + 1, c, index + 1)
            || backtrack(board, word, r - 1, c, index + 1)
            || backtrack(board, word, r, c + 1, index + 1)
            || backtrack(board, word, r, c - 1, index + 1);

        board[r][c] = temp;
        return found;
    }
};
```