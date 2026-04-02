class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board){
    //Store seen digits for each row, columns, and 3*3 box
    vector<unordered_set<char>> rows(9), cols(9), boxes(9);

    // Traverse every cell in the 9*9 board
    for(int r = 0; r<9; r++){
        for(int c = 0; c < 9; c++){
            // Current character in the board
            char ch = board[r][c];

            //skip empty cells
            if(ch == '.') continue;

            // Find which 3*3 box this cell belongs to
            int box = (r/3) * 3 + (c/3);

            // if digit already exists in row, column, or box, board is valid
            if (rows[r].count(ch) || cols[c].count(ch) || boxes[box].count(ch)){
                return false;
            }
        // Mark digit as seen in current row, column and box
        rows[r].insert(ch);
        cols[c].insert(ch);
        boxes[box].insert(ch);
         }
    }   
    // No duplicates found, board is valid
    return true;
    }
    
};
