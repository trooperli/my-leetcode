/**
 * First we find the total shifts by applying -1 to left shift and 1
 * to right shift. Then we use the string method substr to rotate the
 * string. The time complexity is O(m+n) while m is the length of
 * shifts and n is the length of string s.
 */



class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sum = 0;
        for (int i =  0; i < shift.size(); ++i) {
            if (shift[i][0] == 0) {sum += -1*shift[i][1];}
            else {sum += 1*shift[i][1];}
        }
        int sz = s.size();
        int shi = sum % sz;
        if (shi < 0) {//left shift
            shi = -shi;
            return s.substr(shi, sz-shi)+s.substr(0,shi);
        }
        else if (shi > 0) {//right shift
            return s.substr(s.size()-shi, shi)+s.substr(0, sz-shi);
        }
        else return s;



    }
};
