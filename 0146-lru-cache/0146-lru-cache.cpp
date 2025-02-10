class LRUCache {
public:
    queue<pair<int, int>> record;
    int capacity;
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        queue<pair<int, int>> tempQueue;
        int value = -1;
        pair<int, int> selectedPair = {};
        while (!record.empty()) {
            if (record.front().first == key) {
                selectedPair = record.front();
                value = record.front().second;
            } else {
                tempQueue.push(record.front());
            }
            record.pop();
        }
        if (value != -1)
            tempQueue.push(selectedPair);
        record = tempQueue;
        return value;
    }

    void put(int key, int newValue) {
        queue<pair<int, int>> tempQueue;
        int value = -1;
        pair<int, int> selectedPair = {};
        while (!record.empty()) {
            if (record.front().first == key) {
                selectedPair = record.front();
                value = newValue;
                selectedPair.second = newValue;
            } else {
                tempQueue.push(record.front());
            }
            record.pop();
        }
        if (value != -1) {
            tempQueue.push(selectedPair);
            record = tempQueue;
        } else {
            if (tempQueue.size() == capacity) {
                tempQueue.pop();
                tempQueue.push({key, newValue});
            } else {
                tempQueue.push({key, newValue});
            }
            record = tempQueue;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */