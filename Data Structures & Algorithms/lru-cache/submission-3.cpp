class LRUCache {
public:

    list<int> lruKeys;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> lruMap;
    int capacity;
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        // check if it exists
        auto it = cache.find(key);
        // if it does, update lru
        if (it != cache.end()) {
            // do stuff
            auto it2 = lruMap[key];
            lruKeys.erase(it2);
            lruKeys.push_front(key);
            lruMap[key] = lruKeys.begin();

            return it->second;
        } else return -1;

        // if it doesnt, return -1
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            if (cache.size() == capacity) {
                cache.erase(lruKeys.back());
                lruMap.erase(lruKeys.back());
                lruKeys.pop_back();
            }

            cache[key] = value;
                
            lruKeys.push_front(key);
            lruMap[key] = lruKeys.begin();
        } else {
            cache[key] = value;
            auto it = lruMap[key];
            lruKeys.erase(it);
            lruKeys.push_front(key);
            lruMap[key] = lruKeys.begin();
        }
        // if key not in cache
            // if size == capacity
                // evict lru
                // add new key
                // update lru
            // add to cache and update lru
        // else
            // update element
            // update lru
    }
};
