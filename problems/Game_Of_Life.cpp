/**
 * The trick of this problem is to update the board simultaneously. In
 * order not to use extra space, we need to record the state of each
 * cell. E.g., 0 to 1 we use 2, 1 to 0 we use -1. Thus we not only
 * record the state of current timestamp but also the state of
 * previous timestamp.
 */


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (!board.empty() and !board[0].empty()) {
            int rowNum = board.size();
            int colNum = board[0].size();
            for (int i = 0; i < rowNum; ++i) {
                for (int j = 0; j < colNum; ++j) {
                    int num = calNeighbor(i, j, board);
                    int cell = board[i][j];
                    if (cell == 1) {
                        if (num < 2 or num > 3) {board[i][j] = -1;}

                    }
                    else {
                        if (num == 3) {board[i][j] = 2;}
                    }
                }
            }
            for (int i = 0; i < rowNum; ++i) {
                for (int j = 0; j < colNum; ++j) {
                    if (board[i][j] == -1) {board[i][j] = 0;}
                    if (board[i][j] == 2) {board[i][j] = 1;}

                }
            }
        }

    }

    int calNeighbor(int i, int j, vector<vector<int>>& board) {
        vector<int> row {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> col {-1, 0, 1, -1, 1, -1, 0, 1};
        int res {0};
        for (int ii = 0; ii < 8; ++ii) {
            if ((i+row[ii]) >=0 and (i+row[ii]) < board.size() and (j+col[ii]) >= 0 and (j+col[ii]) < board[0].size()) {
                if (board[i+row[ii]][j+col[ii]] == 1 or board[i+row[ii]][j+col[ii]] == -1) {
                    res++;
                }

            }
        }
        return res;

    }
};
