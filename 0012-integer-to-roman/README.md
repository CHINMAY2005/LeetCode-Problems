# 0012 - Integer to Roman

## Problem
Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

Given an integer, convert it to a Roman numeral. The input is guaranteed to be within the range from 1 to 3999.

## Key Insight
Since the number of unique Roman numeral sub-values (including subtractive combinations like `IV`, `IX`, etc.) is finite, we can store all values and their corresponding symbols in descending order. Then, we can repeatedly subtract the largest possible value and append its symbol to the result.

## Approach
1. Define a list of integer values: `[1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]`.
2. Define a matching list of Roman symbols: `["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]`.
3. Loop through the values list:
   - While the remaining number `num` is greater than or equal to the current value:
     - Subtract the value from `num`.
     - Append the corresponding Roman symbol to the result.
4. Return the assembled Roman numeral string.

## Why It Works
Using a greedy approach is correct here because Roman numerals are always constructed from the largest symbols to the smallest. Subtracting the largest possible value at each step guarantees we use the minimal number of symbols correctly.

## Complexity
- Time: `O(1)` because the input range is bounded (up to 3999), meaning the loops run a constant number of times.
- Space: `O(1)` auxiliary space.

## Python
```python
class Solution:
    def intToRoman(self, num):
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        
        roman = []
        for i in range(len(values)):
            while num >= values[i]:
                num -= values[i]
                roman.append(symbols[i])
                
        return "".join(roman)
```

## Java
```java
class Solution {
    public String intToRoman(int num) {
        int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        StringBuilder roman = new StringBuilder();
        for (int i = 0; i < values.length; i++) {
            while (num >= values[i]) {
                num -= values[i];
                roman.append(symbols[i]);
            }
        }
        
        return roman.toString();
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
    string intToRoman(int num) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string roman;
        for (int i = 0; i < 13; i++) {
            while (num >= values[i]) {
                num -= values[i];
                roman += symbols[i];
            }
        }
        
        return roman;
    }
};
```
