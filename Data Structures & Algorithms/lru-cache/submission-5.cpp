class LRUCache {
public:

    list<int> lruKeys;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    int capacity;
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        // check if it exists
        auto it = cache.find(key);
        // if it does, update lru
        if (it != cache.end()) {
            // do stuff
            lruKeys.erase(it->second.second);
            lruKeys.push_front(key);
            cache[key].second = lruKeys.begin();

            return it->second.first;
        } else return -1;

        // if it doesnt, return -1
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            if (cache.size() == capacity) {
                cache.erase(lruKeys.back());
                lruKeys.pop_back();
            }

            cache[key].first = value;
                
            lruKeys.push_front(key);
            cache[key].second = lruKeys.begin();
        } else {
            cache[key].first = value;
            lruKeys.erase(cache[key].second);
            lruKeys.push_front(key);
            cache[key].second = lruKeys.begin();
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
