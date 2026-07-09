class LRUCache {
public:
    // use hash set to determine if a key is in or not in cache in O(1) time
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = m.find(key);
        // check if in cache
        if (it == m.end()) return -1;

        // update lru ordering
        int value = it->second->second;
        l.erase(it->second);
        l.push_back({key, value});
        m[key] = prev(l.end());

        return value;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        // if key doesnt exist and capacity full
            // delete entry at start of list
            // update lru and map
        // if key doesnt exist and have capacity
            // update lru and map
        // if key does exist
            // update lru and map

        if (it == m.end() && l.size() == capacity) {
            m.erase(l.front().first);
            l.pop_front();
            l.push_back({key, value});
            m[key] = prev(l.end());
        } else {
            if (it != m.end()) {
                l.erase(it->second);
            }
            l.push_back({key, value});
            m[key] = prev(l.end());
        }
        

        // m[key] = prev(l.end());
    }
};
