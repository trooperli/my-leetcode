/**
 * We need the whole row to match.Therefore, if one tile does not
 * match, we cannot have a matching row. We could arbitrarily pick any
 * tile, but we pick te 0th tile since it aways exists. In other
 * words, one side of the first tile MUST match at least one side of
 * every single one other tiles, or we cannot have an equal row.
 */



class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int rotations = check(A[0], A, B, n);
        if (rotations != -1 || A[0] == B[0]) {return rotations;}
        else {return check(B[0], A, B, n);}
    }


    int check(int x, vector<int>& A, vector<int>& B, int n) {
        int rotation_a = 0, rotation_b = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != x && B[i] != x) {return -1;}
            else if (A[i] != x) {rotation_a++;}
            else if (B[i] != x) {rotation_b++;}
        }
        return min(rotation_a, rotation_b);
    }
};
