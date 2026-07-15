# 0006 - Zigzag Conversion

## Problem
The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this:
```
P   A   H   N
A P L S I I G
Y   I   R
```
And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows.

## Key Insight
Instead of building a 2D matrix structure to track spaces, we can simulate the vertical bounce of the cursor. We keep track of the current row index and a direction variable (up or down). We can append characters directly to the string representing each row.

## Approach
1. If `numRows == 1` or `numRows >= s.length()`, return `s` immediately as no zigzagging occurs.
2. Initialize an array of `numRows` empty strings/StringBuilder to store characters for each row.
3. Initialize variables: `currRow = 0` and `goingDown = false`.
4. Iterate through each character in the string:
   - Append the character to the current row `rows[currRow]`.
   - If `currRow == 0` or `currRow == numRows - 1`, we toggle the direction (`goingDown = !goingDown`).
   - Move the cursor: `currRow += goingDown ? 1 : -1`.
5. Join all rows sequentially and return the final string.

## Why It Works
By simulating the vertical cursor movement, we map each input character to its respective row in $O(n)$ time. Reading sequentially row-by-row gives the correct zigzag-traversed string.

## Complexity
- Time: `O(n)` where `n` is the length of the string, since we iterate through the input string once.
- Space: `O(n)` to store the converted string rows.

## Python
```python
class Solution:
    def convert(self, s, numRows):
        if numRows == 1 or numRows >= len(s):
            return s
            
        rows = [""] * numRows
        curr_row = 0
        going_down = False
        
        for char in s:
            rows[curr_row] += char
            if curr_row == 0 or curr_row == numRows - 1:
                going_down = not going_down
            curr_row += 1 if going_down else -1
            
        return "".join(rows)
```

## Java
```java
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i] = new StringBuilder();
        }
        
        int currRow = 0;
        boolean goingDown = false;
        
        for (int i = 0; i < s.length(); i++) {
            rows[currRow].append(s.charAt(i));
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currRow += goingDown ? 1 : -1;
        }
        
        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }
        
        return result.toString();
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
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.length()) {
            return s;
        }
        
        vector<string> rows(numRows);
        int currRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currRow += goingDown ? 1 : -1;
        }
        
        string result;
        for (const string& row : rows) {
            result += row;
        }
        
        return result;
    }
};
```
