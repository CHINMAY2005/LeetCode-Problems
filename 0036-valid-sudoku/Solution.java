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
