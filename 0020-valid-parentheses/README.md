# 0020 - Valid Parentheses

## Problem
Given a string `s` containing only the characters `(`, `)`, `{`, `}`, `[` and `]`, determine whether the input string is valid.

A string is valid if every opening bracket has a matching closing bracket of the same type, and the pairs are closed in the correct order.

## Key Insight
A stack naturally tracks the most recent unmatched opening bracket.

When we see a closing bracket, it must match the top of the stack.

## Approach
Scan the string from left to right.

- Push opening brackets onto a stack.
- For a closing bracket, check that the stack is not empty and that its top matches the required opening bracket.
- If it does, pop the stack; otherwise return false.

At the end, the stack must be empty for the string to be valid.

## Why It Works
The last unmatched opening bracket must be the first one closed.

The stack always stores openings in the exact order they need to be closed, so matching against the top enforces the required nesting structure.

## Complexity
- Time: `O(n)`
- Space: `O(n)`

## Python
```python
class Solution:
    def isValid(self, s):
        stack = []
        pairs = {')': '(', ']': '[', '}': '{'}

        for char in s:
            if char in pairs.values():
                stack.append(char)
            else:
                if not stack or stack.pop() != pairs[char]:
                    return False

        return not stack
```

## Java
```java
import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }

                char top = stack.pop();
                if ((c == ')' && top != '(')
                    || (c == ']' && top != '[')
                    || (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }
}
```

## C++
```cpp
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(')
                    || (c == ']' && top != '[')
                    || (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
```