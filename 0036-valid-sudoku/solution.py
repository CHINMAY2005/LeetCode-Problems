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
