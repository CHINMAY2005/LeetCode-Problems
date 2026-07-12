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
