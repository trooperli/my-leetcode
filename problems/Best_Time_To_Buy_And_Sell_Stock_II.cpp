/**
 * The key to solve this problem is to capture every valley to peak
 *   period. Thus, first we find the valley price, then the peak price,
 *   there difference is put into the profit, and we move forward in
 *   the prices vector. Another simpler approach (Solution 2) is to
 *   find all the moments when the next day price is higher than the
 *   current day and add them altogether.
 */


// Solution 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {return 0;}
        auto sz = prices.size();
        int i = 0;
        int res = 0;
        while (i < sz-1) {
            while (i < sz-1 and prices[i] >= prices[i+1]) {
                i++;
            }
            auto valley = prices[i];
            while (i < sz-1 and prices[i] <= prices[i+1]) {
                i++;
            }
            auto peak = prices[i];
            res += peak-valley;
        }
        return res;

    }
};

// Solution 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {return 0;}
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) {res += prices[i]-prices[i-1];}
        }
        return res;
    }
};
