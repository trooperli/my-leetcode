/**
 * This problem is similar to the LRU cache. We use a linked list and
 * unordered_map to solve it. linked list is to store the unique
 * numbers and the front of the list is the first unique number. The
 * unordered_map is to store the values and its corresponding iterator
 * in the list. When the number is not unique, we erase it from the
 * list and set its iterator to the end of the list.
 */



class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            updateList(nums[i]);
        }

    }

    int showFirstUnique() {
        if (unique_nums.empty()) {return -1;}
        else {return unique_nums.front();}

    }

    void add(int value) {
        updateList(value);

    }
private:
    list<int> unique_nums;
    unordered_map<int, list<int>::iterator> mp;
    void updateList(int value) {
        if (mp.count(value)) {
            auto it = mp[value];
            if (it != unique_nums.end()) {
                unique_nums.erase(mp[value]);
                mp[value] = unique_nums.end();
            }

        }
        else {unique_nums.push_back(value);
            auto it = unique_nums.end();
            it--;
            mp[value] = it;}
    }
};
