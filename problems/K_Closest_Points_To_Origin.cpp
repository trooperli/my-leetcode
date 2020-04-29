/**
 * In this problem we used the mini heap and hash to solve. Map is to
 * store the distance with its corresponding coordinate. There could
 * be cases 1 corresponds to [1,0] and [0,1]. When these 2 points
 * exist, the second one will overwrite the first one. But that's OK
 * because the second one will always be the reverse of the first
 * one considering the coorinates are integers. Thus, from one we can
 * infer the other. The priority queue is to store the K smallest
 * distances. Another way is to switch the key val pair in the map to
 * allow the coorinates to be the key which avoids the overwrite
 * problem mentioned before.
 */



class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        unordered_map<int, vector<int>> mp;
        priority_queue<int> q;
        for (int i = 0; i < points.size(); ++i) {
            int tmp = pow(points[i][0], 2)+pow(points[i][1], 2);
            mp[tmp] = points[i];
            q.push(tmp);
            if (q.size() > K) {q.pop();}
        }

        vector<vector<int>> res;
        for (int i = 0; i < K; ++i) {
            auto tmp = q.top();
            res.push_back(mp[tmp]);
            reverse(mp[tmp].begin(), mp[tmp].end());
            q.pop();
        }
        return res;
    }
};
