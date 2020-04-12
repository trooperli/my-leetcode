/**
 * This is an array manipulation problem. We need to be careful about
 * the else statement when the two stones are equal. We need to guard
 * the case when the array is empty.
 */



class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() >= 1) {
            if (stones.size() == 1) {break;}
            sort(stones.begin(), stones.end());
            if (stones[stones.size()-1] != stones[stones.size()-2]) {
                int dif = stones[stones.size()-1]-stones[stones.size()-2];
                stones.pop_back();
                stones.pop_back();
                stones.push_back(dif);
            }
            else {
                stones.pop_back();
                stones.pop_back();
                if (stones.empty()) {return 0;}
            }
        }
        return stones[0];

    }
};
