class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            touch(it->second);
            it->second->second = value;
            return;
        }
        if (cache.size() == cap) {
            int lru = order.back().first;
            order.pop_back();
            cache.erase(lru);
        }
        order.emplace_front(key, value);
        cache[key] = order.begin();
    }
    
private:
    int cap;
    list<pair<int, int>> order;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    
    void touch(list<pair<int, int>>::iterator it) {
        int key = it->first, val = it->second;
        order.erase(it);
        order.emplace_front(key, val);
        cache[key] = order.begin();
    }
};