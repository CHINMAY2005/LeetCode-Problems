# 0003 - Longest Substring Without Repeating Characters

## Problem
Given a string `s`, find the length of the longest substring without repeating characters.

## Key Insight
We can use a sliding window approach with two pointers (`left` and `right`) to represent the current substring. A hash map is used to store the last seen index of each character, allowing us to quickly adjust the left pointer when a duplicate is found.

## Approach
1. Initialize a hash map `charMap` to store the last seen index of characters.
2. Initialize `left = 0` (left pointer of the window) and `maxLen = 0`.
3. Iterate the `right` pointer from `0` to `s.length() - 1`:
   - If `s[right]` is already in `charMap` and its index is greater than or equal to `left`, update `left = charMap[s[right]] + 1`.
   - Update the last seen index of `s[right]` to `right`.
   - Calculate the current window size `right - left + 1` and update `maxLen` with the maximum value.
4. Return `maxLen`.

## Why It Works
Using a sliding window ensures we check all possible substrings in a single pass. Instead of resetting the left pointer to the beginning of the search range, the hash map lets us jump `left` directly past the last occurrence of the repeated character, avoiding redundant checks.

## Complexity
- Time: `O(n)` where `n` is the length of the string, as each character is processed at most twice.
- Space: `O(min(m, n))` where `n` is the length of the string and `m` is the size of the character set (alphabet).

## Python
```python
class Solution:
    def lengthOfLongestSubstring(self, s):
        char_map = {}
        left = 0
        max_len = 0
        
        for right, char in enumerate(s):
            if char in char_map and char_map[char] >= left:
                left = char_map[char] + 1
            char_map[char] = right
            max_len = max(max_len, right - left + 1)
            
        return max_len
```

## Java
```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> charMap = new HashMap<>();
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            if (charMap.containsKey(c) && charMap.get(c) >= left) {
                left = charMap.get(c) + 1;
            }
            charMap.put(c, right);
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
}
```

## C++
```cpp
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < (int)s.length(); right++) {
            char c = s[right];
            if (charMap.count(c) && charMap[c] >= left) {
                left = charMap[c] + 1;
            }
            charMap[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
```
