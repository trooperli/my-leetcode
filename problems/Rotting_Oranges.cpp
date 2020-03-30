/**
 * This is a BFS problem with some innovations. We need to count the
 * fresh oranges because this is an ending condition. It only makes
 * sense when fresh oranges are equal to zero at the end otherwise it
 * means not all oranges are infected.
 */



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() or grid[0].empty()) {return 0;}
        vector<int> inc_r {0, 1, 0 , -1};
        vector<int> inc_c {1, 0, -1, 0};
        queue<pair<int, int>> q;
        int cnt_fresh = 0;
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
                if (grid[i][j] == 1) {
                    cnt_fresh++;
                }
            }
        }
        if (cnt_fresh == 0) {return 0;}
        while(!q.empty()) {
            cnt++;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) { /*!< this for loop is very
                important, this is in the essence a level dividing
                problem. We only count all the rotten apples at a
                given time stamp */
                auto tmp = q.front();
                q.pop();
                auto row = tmp.first;
                auto col = tmp.second;
                for (int j = 0; j < 4; ++j) {
                    if ((row+inc_r[j] >=0) and (row+inc_r[j] < grid.size()) and (col+inc_c[j] >=0) and (col+inc_c[j] < grid[0].size()) and (grid[row+inc_r[j]][col+inc_c[j]] == 1)) {
                        q.push(make_pair(row+inc_r[j], col+inc_c[j]));
                        grid[row+inc_r[j]][col+inc_c[j]] = 2;
                        cnt_fresh--;
                    }
                }

            }
        }
        return cnt_fresh == 0 ? cnt-1:-1;

    }
};
