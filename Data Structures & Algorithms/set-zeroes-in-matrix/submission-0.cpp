class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        bool firstRowZero = false;

        // Step 1: Mark zeros on the first row and first column
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (matrix[r][c] == 0) {
                    // Mark the corresponding column
                    matrix[0][c] = 0; 
                    
                    // Mark the corresponding row
                    if (r > 0) {
                        matrix[r][0] = 0; 
                    } else {
                        firstRowZero = true; 
                    }
                }
            }
        }

        // Step 2: Use the marks to set matrix elements to zero
        // (Skip the first row and first column for now)
        for (int r = 1; r < ROWS; r++) {
            for (int c = 1; c < COLS; c++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Step 3: Zero out the first column if needed
        if (matrix[0][0] == 0) {
            for (int r = 0; r < ROWS; r++) {
                matrix[r][0] = 0;
            }
        }

        // Step 4: Zero out the first row if needed
        if (firstRowZero) {
            for (int c = 0; c < COLS; c++) {
                matrix[0][c] = 0;
            }
        }
    }
};