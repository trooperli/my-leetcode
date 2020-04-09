/**
 * The code says all. The trick is to start from the right top
 * corner. If target is larger, row++; if target is smaller, col--;
 * otherwise return true.
 */



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {return false;}
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0; int j = col-1;
        while (i >= 0 and i < row and j >=0 and j < col) {
            int comp = matrix[i][j];
            if (target == comp) {return true;}
            else if (target > comp) {i++;}
            else {j--;}
        }
        return false;


    }
};
