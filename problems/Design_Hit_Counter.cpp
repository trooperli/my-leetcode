/**
 * The data structure for this problem is queue, thus the old
 * timestamp will be popped from front. Considering each timestamp
 * will corresponding to only 1 hit, we only need to maintain the
 * queue of timestamps. The getHits method will return the size of the
 * queue.
 */



class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);

    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!q.empty() and (timestamp-q.front() >=300)) {q.pop();}
        return q.size();

    }
private:
    queue<int> q;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
