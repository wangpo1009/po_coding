bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int rows[9][10] = {0};
    int cols[9][10] = {0};
    int boxes[9][10] = {0};

    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            if(board[i][j] != '.'){
                int val = (int)board[i][j] - (int)'0';
                int box_ind = (i/3)*3 + j/3;
                
                if(rows[i][val] == 1) return FALSE;
                if(cols[j][val] == 1) return FALSE;
                if(boxes[box_ind][val] == 1) return FALSE;

                rows[i][val] = 1;
                cols[j][val] = 1;
                boxes[box_ind][val] = 1;
            }
        }
    }
    return TRUE;
}
