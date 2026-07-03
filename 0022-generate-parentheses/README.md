# 0022 - Generate Parentheses

## Problem
Given `n` pairs of parentheses, generate all combinations of well-formed parentheses.

Return the answer in any order.

## Key Insight
At any point, the number of closing parentheses used cannot exceed the number of opening parentheses used.

That constraint makes backtracking a natural fit.

## Approach
Build strings one character at a time while tracking how many opening and closing parentheses have been used.

- Add `(` when we still have openings left.
- Add `)` when the number of closings used is less than the number of openings used.
- When the string reaches length `2 * n`, record it as a valid answer.

This explores only valid partial states, so it never generates invalid combinations.

## Why It Works
Every valid parentheses string can be built by choosing `(` or `)` while preserving the rule that prefixes never contain more closing than opening parentheses.

The recursion enumerates exactly those legal prefixes, so it finds every valid result and excludes every invalid one.

## Complexity
- Time: `O(4^n / sqrt(n))`
- Space: `O(n)`

## Python
```python
class Solution:
    def generateParenthesis(self, n):
        result = []

        def backtrack(current, open_count, close_count):
            if len(current) == 2 * n:
                result.append(current)
                return

            if open_count < n:
                backtrack(current + '(', open_count + 1, close_count)

            if close_count < open_count:
                backtrack(current + ')', open_count, close_count + 1)

        backtrack('', 0, 0)
        return result
```

## Java
```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        backtrack(result, new StringBuilder(), 0, 0, n);
        return result;
    }

    private void backtrack(List<String> result, StringBuilder current, int openCount, int closeCount, int n) {
        if (current.length() == 2 * n) {
            result.add(current.toString());
            return;
        }

        if (openCount < n) {
            current.append('(');
            backtrack(result, current, openCount + 1, closeCount, n);
            current.deleteCharAt(current.length() - 1);
        }

        if (closeCount < openCount) {
            current.append(')');
            backtrack(result, current, openCount, closeCount + 1, n);
            current.deleteCharAt(current.length() - 1);
        }
    }
}
```

## C++
```cpp
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int openCount, int closeCount, int n) {
        if ((int)current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (openCount < n) {
            current.push_back('(');
            backtrack(result, current, openCount + 1, closeCount, n);
            current.pop_back();
        }

        if (closeCount < openCount) {
            current.push_back(')');
            backtrack(result, current, openCount, closeCount + 1, n);
            current.pop_back();
        }
    }
};
```