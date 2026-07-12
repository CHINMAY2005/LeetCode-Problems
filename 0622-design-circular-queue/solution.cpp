#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> queue;
    int headIndex;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        queue.resize(k);
        headIndex = 0;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        queue[(headIndex + count) % capacity] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        headIndex = (headIndex + 1) % capacity;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return queue[headIndex];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[(headIndex + count - 1) % capacity];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};
