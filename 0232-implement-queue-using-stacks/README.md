# 0232 - Implement Queue using Stacks

## Problem
Implement a first-in, first-out queue using only two stacks.

The queue should support `push`, `pop`, `peek`, and `empty`.

## Key Insight
One stack can store incoming elements, and the other can store elements in queue order when needed.

By moving elements only when necessary, we can simulate a queue efficiently.

## Approach
Use two stacks:

- `input` stores elements in the order they are pushed.
- `output` stores elements in queue order for popping and peeking.

For `push`, add the new element to `input`.

For `pop` and `peek`, if `output` is empty, move every element from `input` to `output`. This reverses the order and places the oldest element on top.

For `empty`, check whether both stacks are empty.

## Why It Works
Elements are moved from `input` to `output` only when `output` needs more elements.

This lazy transfer preserves queue order while ensuring each element moves at most once from one stack to the other.

## Complexity
- Time: `O(1)` amortized for each operation
- Space: `O(n)`

## Python
```python
class MyQueue:

    def __init__(self):
        self.input = []
        self.output = []

    def push(self, x):
        self.input.append(x)

    def pop(self):
        self.peek()
        return self.output.pop()

    def peek(self):
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())
        return self.output[-1]

    def empty(self):
        return not self.input and not self.output
```

## Java
```java
import java.util.Stack;

class MyQueue {
    private Stack<Integer> input;
    private Stack<Integer> output;

    public MyQueue() {
        input = new Stack<>();
        output = new Stack<>();
    }

    public void push(int x) {
        input.push(x);
    }

    public int pop() {
        peek();
        return output.pop();
    }

    public int peek() {
        if (output.isEmpty()) {
            while (!input.isEmpty()) {
                output.push(input.pop());
            }
        }
        return output.peek();
    }

    public boolean empty() {
        return input.isEmpty() && output.isEmpty();
    }
}
```

## C++
```cpp
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        peek();
        int value = output.top();
        output.pop();
        return value;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};
```