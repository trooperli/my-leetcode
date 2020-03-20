/*
 * The key to solve this problem is to use a priority queue, with the
 * smallest value in the front of the queue. This priority queue is to
 * store the end time of meetings. First it stores the end time of the
 * first meeting which has the earilest start time. When a new meeting
 * has start time later than the first meeting, we pop the end time of
 * the first meeting and push in the end time of the new meeting,
 * which means the new meeting occupies the room of the first meeting;;
 * otherwise we only push in the end time of the new meeting, which
 * means we need to take a new room. The priority queue always
 * maintain the first element to be the smallest.
 */

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() < 1) {return 0;}
        priority_queue<int, std::vector<int>, std::greater<int>> rooms;
        sort(intervals.begin(), intervals.end(), compareFunc);
        rooms.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); ++i) {
            if (rooms.top() <= intervals[i][0]) {
                rooms.pop();
            }
            rooms.push(intervals[i][1]);
        }
        return rooms.size();


    }

    static bool compareFunc(vector<int> a, vector<int> b) {
        return (a[0] < b[0]);
    }
};
