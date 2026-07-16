# 0014 - Longest Common Prefix

## Problem
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

## Key Insight
Instead of comparing strings pairs horizontally, we can compare them vertically. We scan characters of the first string one by one from left to right, comparing the character at the same position in all other strings.

## Approach
1. If the input array `strs` is empty, return `""` immediately.
2. Iterate through each character index `i` of the first string `strs[0]`:
   - Store the character `c = strs[0][i]`.
   - For all other strings in the array (from index `1` to `len(strs) - 1`):
     - If `i` reaches the end of the current string, or the character at index `i` does not match `c`:
       - Return the substring of `strs[0]` from index `0` to `i` (excluding `i`).
3. If the loop completes successfully, it means the entire first string is the common prefix. Return `strs[0]`.

## Why It Works
Vertical scanning stops as soon as a mismatch is found or any string is fully traversed. This avoids unnecessary character comparisons once the prefix limit is reached.

## Complexity
- Time: `O(S)` where `S` is the sum of all characters in all strings. In the worst case, all strings are identical, requiring us to scan all characters.
- Space: `O(1)` auxiliary space, as we return a slice of the existing string.

## Python
```python
class Solution:
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
            
        for i in range(len(strs[0])):
            char = strs[0][i]
            for string in strs[1:]:
                if i >= len(string) or string[i] != char:
                    return strs[0][:i]
                    
        return strs[0]
```

## Java
```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (i >= strs[j].length() || strs[j].charAt(i) != c) {
                    return strs[0].substring(0, i);
                }
            }
        }
        
        return strs[0];
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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        for (int i = 0; i < (int)strs[0].length(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < (int)strs.size(); j++) {
                if (i >= (int)strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};
```
