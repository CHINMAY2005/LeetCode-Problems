# 0013 - Roman to Integer

## Problem
Given a Roman numeral, convert it to an integer. The input is guaranteed to be within the range from 1 to 3999.

## Key Insight
Roman numerals are usually written largest to smallest from left to right. When a smaller value appears before a larger value, it represents subtraction (e.g. `IV` for 4). Therefore, we can sum the values of all characters, but subtract a value if it is smaller than the value of the character following it.

## Approach
1. Define a map associating Roman characters to their integer values: `I: 1, V: 5, X: 10, L: 50, C: 100, D: 500, M: 1000`.
2. Initialize `total = 0`.
3. Loop through the string from index `0` to `n - 1`:
   - Get the value of the current character `currVal`.
   - Compare `currVal` with the value of the next character `nextVal` (if it exists):
     - If `currVal < nextVal`, subtract `currVal` from `total`.
     - Otherwise, add `currVal` to `total`.
4. Return `total`.

## Why It Works
Since Roman numerals only use subtractive notation in cases where a smaller value precedes a larger value, a single-pass comparison of adjacent elements is sufficient to compute the correct value.

## Complexity
- Time: `O(n)` where `n` is the length of the string.
- Space: `O(1)` since the map size is fixed.

## Python
```python
class Solution:
    def romanToInt(self, s):
        roman_map = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50,
            'C': 100, 'D': 500, 'M': 1000
        }
        
        total = 0
        n = len(s)
        
        for i in range(n):
            curr_val = roman_map[s[i]]
            if i + 1 < n and curr_val < roman_map[s[i+1]]:
                total -= curr_val
            else:
                total += curr_val
                
        return total
```

## Java
```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> romanMap = new HashMap<>();
        romanMap.put('I', 1);
        romanMap.put('V', 5);
        romanMap.put('X', 10);
        romanMap.put('L', 50);
        romanMap.put('C', 100);
        romanMap.put('D', 500);
        romanMap.put('M', 1000);
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            int currVal = romanMap.get(s.charAt(i));
            if (i + 1 < n && currVal < romanMap.get(s.charAt(i + 1))) {
                total -= currVal;
            } else {
                total += currVal;
            }
        }
        
        return total;
    }
}
```

## C++
```cpp
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            int currVal = romanMap[s[i]];
            if (i + 1 < n && currVal < romanMap[s[i + 1]]) {
                total -= currVal;
            } else {
                total += currVal;
            }
        }
        
        return total;
    }
};
```
