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
