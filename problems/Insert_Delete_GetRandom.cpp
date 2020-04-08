/**
 * This problem is actually test what data structure to use to achieve
 * O(1) complexity. Here, we used a unordered_map<data, idx> and a
 * vector. The unordered_map actually records the element and its
 * index, which makes delete O(1) possible, otherwise we need to loop
 * throught the array. In remove method, we need to be careful about
 * where to put the erase method. It needs to be implemented after all
 * other operations. In insert method, we use emplace_back instead of
 * push_back because the former has better efficiency.
 */


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.count(val)) {return false;}
        arr.push_back(val);
        map[val] = arr.size()-1;
        return true;

    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!map.count(val)) {return false;}
        auto idx = map[val];
        auto last_element = arr.back();
        arr[idx] = last_element;
        arr.pop_back();
        map.erase(val);
        map[last_element] = idx;
        return true;

    }

    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand() % arr.size()];

    }
    private:
    vector<int> arr;
    unordered_map<int, int> map;


};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
