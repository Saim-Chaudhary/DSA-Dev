class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check all rows for duplicates
        for(int row = 0; row < 9; row++){
            // Create set to track seen numbers in current row
            unordered_set<char> seen;
            // Loop through all columns in current row
            for(int j = 0; j < 9; j++){
                // Skip empty cells
                if(board[row][j] == '.') continue;
                // If number already seen in this row, sudoku is invalid
                if(seen.count(board[row][j])) return false;
                // Add number to seen set
                seen.insert(board[row][j]);
            }
        }
        // Check all columns for duplicates
        for(int col = 0; col < 9; col++){
            // Create set to track seen numbers in current column
            unordered_set<char> seen;
            // Loop through all rows in current column
            for(int j = 0; j < 9; j++){
                // Skip empty cells
                if(board[j][col] == '.') continue;
                // If number already seen in this column, sudoku is invalid
                if(seen.count(board[j][col])) return false;
                // Add number to seen set
                seen.insert(board[j][col]);
            }
        }
        // Check all 3x3 sub-boxes for duplicates
        for(int square = 0; square < 9; square++){
            // Create set to track seen numbers in current 3x3 sub-box
            unordered_set<char> seen;
            // Loop through 3 rows of current sub-box
            for(int i = 0; i < 3; i++){
                // Loop through 3 columns of current sub-box
                for(int j = 0; j < 3; j++){
                    // Calculate actual row position in board
                    int row = (square / 3) * 3 + i;
                    // Calculate actual column position in board
                    int col = (square % 3) * 3 + j;
                    // Skip empty cells
                    if(board[row][col] == '.') continue;
                    // If number already seen in this sub-box, sudoku is invalid
                    if(seen.count(board[row][col])) return false;
                    // Add number to seen set
                    seen.insert(board[row][col]);
                }
            }
        }
        // All checks passed, sudoku is valid
        return true;
    }
};