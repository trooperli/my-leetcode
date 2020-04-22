/**
 * The solution to this problem is special. You start from the top
 * right corner, if the current_val = 1, column--; else row++. Return
 * column+1.
 */



class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size;
        size = binaryMatrix.dimensions();
        int m = size[0]; //row
        int n = size[1]; //column
        int x = 0, y = n-1;
        while (x >=0 and x < m and y >=0 and y < n) {
            if (binaryMatrix.get(x, y) == 1) y--;
            else x++;
        }
        return (y+1 == n)?-1:y+1;


    }
};
