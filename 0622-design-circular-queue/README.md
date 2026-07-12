# 0622 - Design Circular Queue

## Problem
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can store the next element in those spaces.

You must solve the problem without using the built-in queue library in your programming language.

## Key Insight
Instead of tracking both head and tail pointer indices independently (which leads to complex conditions distinguishing full and empty states when `head == tail`), we can track:
- `headIndex`: The index of the front element.
- `count`: The current size of the queue.
- `capacity`: The maximum size `k`.

With `headIndex` and `count`, we can calculate the tail index dynamically as `(headIndex + count - 1) % capacity`.

## Approach
1. Initialize a fixed-size array/list of size `k`, along with `headIndex = 0` and `count = 0`.
2. `enQueue`: Check if full. If not, insert value at `(headIndex + count) % capacity`, increment `count`, and return `true`.
3. `deQueue`: Check if empty. If not, advance `headIndex` as `(headIndex + 1) % capacity`, decrement `count`, and return `true`.
4. `Front`: If not empty, return the value at `headIndex`.
5. `Rear`: If not empty, return the value at `(headIndex + count - 1) % capacity`.
6. `isEmpty` / `isFull`: Return `count == 0` / `count == capacity` respectively.

## Why It Works
Tracking the size (`count`) separates the "empty" representation (`count == 0`) from the "full" representation (`count == capacity`) cleanly. The modulo arithmetic ensures that we wrap around to index `0` when the indices exceed the array bounds.

## Complexity
- Time: `O(1)` for all operations (`enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, `isFull`).
- Space: `O(k)` where `k` is the pre-allocated capacity of the circular queue.

## Python
```python
class MyCircularQueue:
    def __init__(self, k):
        self.capacity = k
        self.queue = [0] * k
        self.headIndex = 0
        self.count = 0

    def enQueue(self, value):
        if self.isFull():
            return False
        self.queue[(self.headIndex + self.count) % self.capacity] = value
        self.count += 1
        return True

    def deQueue(self):
        if self.isEmpty():
            return False
        self.headIndex = (self.headIndex + 1) % self.capacity
        self.count -= 1
        return True

    def Front(self):
        if self.isEmpty():
            return -1
        return self.queue[self.headIndex]

    def Rear(self):
        if self.isEmpty():
            return -1
        return self.queue[(self.headIndex + self.count - 1) % self.capacity]

    def isEmpty(self):
        return self.count == 0

    def isFull(self):
        return self.count == self.capacity
```

## Java
```java
class MyCircularQueue {
    private int[] queue;
    private int headIndex;
    private int count;
    private int capacity;

    public MyCircularQueue(int k) {
        this.capacity = k;
        this.queue = new int[k];
        this.headIndex = 0;
        this.count = 0;
    }
    
    public boolean enQueue(int value) {
        if (isFull()) {
            return false;
        }
        queue[(headIndex + count) % capacity] = value;
        count++;
        return true;
    }
    
    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        }
        headIndex = (headIndex + 1) % capacity;
        count--;
        return true;
    }
    
    public int Front() {
        if (isEmpty()) {
            return -1;
        }
        return queue[headIndex];
    }
    
    public int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return queue[(headIndex + count - 1) % capacity];
    }
    
    public boolean isEmpty() {
        return count == 0;
    }
    
    public boolean isFull() {
        return count == capacity;
    }
}
```

## C++
```cpp
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
```
