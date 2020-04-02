/**
 * It is similiar to meeting room II. First we sort the vectors by the
 * first element. Then, if the first element of next vector is larger
 * than the second element of current vector, we push back the next
 * vector; otherwise we change the second element of current vector to the
 * maximum of the second element of current vector and second element
 * of next vector.
 */


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() <= 1) {return intervals;}
        sort(intervals.begin(), intervals.end(), compareFunc);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > res.back()[1]) {res.push_back(intervals[i]);}
            else {res.back()[1] = max(res.back()[1], intervals[i][1]);}

        }
        return res;
    }

    static bool compareFunc(vector<int> a, vector<int> b) {
        return (a[0] < b[0]);
    }

};
