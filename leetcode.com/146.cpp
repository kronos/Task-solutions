class LRUCache {
    int _capacity;
    int current_capacity;
    unordered_map<int, pair<int, list<int>::iterator> > data;
    list<int> access_order;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        current_capacity = 0;
    }

    int get(int key) {
        auto it = data.find(key);
        if (it != data.end()) {
            access_order.splice(access_order.begin(), access_order, it->second.second);
            return it->second.first;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto it = data.find(key);
        if (it != data.end()) {
            access_order.splice(access_order.begin(), access_order, it->second.second);
            data[key] = {value, access_order.begin()};
        } else {
            if (current_capacity == _capacity) {
                data.erase(*access_order.rbegin());
                access_order.pop_back();
            } else {
                current_capacity++;
            }
            access_order.push_front(key);
            data[key] = {value, access_order.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
