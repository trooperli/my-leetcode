/**
 * In order to solve this problem with O(1) complexity, we need to use
 * linked list. When we get or put a key, we use push_front to push
 * the key to the front of the linked list. When the size is going to
 * exceed the capacity, we pop_back the key from linked
 * list. Basically, we used 3 variables, kv, unordered_map, to store key-value pair,
 * mp, unordered_map, to map the key to the iterator of linked list,
 * and lru, list, to maintain the least recently used key to the front
 * of the linked list.
 */



class LRUCache {
public:
    int size_;
    LRUCache(int capacity) {
        size_ = capacity;

    }

    int get(int key) {
        if (!kv.count(key)) {return -1;}
        updateLRU(key); /*!< when we get the key, make sure to put the
        key to the front of the linked list, which means it is the
        least recently used */
        return kv[key];

    }

    void put(int key, int value) {
        if (kv.size() == size_ && !kv.count(key)) {evict();}
        updateLRU(key);
        kv[key] = value;

    }


private:
    list<int> lru;
    unordered_map<int, list<int>::iterator> mp;
    unordered_map<int, int> kv;

    void updateLRU(int key) {
        if (kv.count(key)) {
            lru.erase(mp[key]);
        } /*!< make sure to delete the key in the linked list if it
        already existed, because we would like to put it to the front
        of the linked list. */
        lru.push_front(key);
        mp[key] = lru.begin();
    }

    void evict() {
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();

    }

};
