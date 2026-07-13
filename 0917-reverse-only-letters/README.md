# 0917 - Reverse Only Letters

## Problem
Given a string `s`, reverse the string according to the following rules:
- All the characters that are not English letters remain in the same position.
- All the English letters should be reversed.

Return `s` after reversing it.

## Key Insight
Use a two-pointer approach starting from both ends. Only swap characters if both point to English letters, skipping non-letter characters.

## Approach
1. Initialize two pointers: `left` at the beginning (`0`) and `right` at the end (`s.length() - 1`).
2. While `left < right`:
   - If `s[left]` is not an alphabetical letter, increment `left`.
   - Else if `s[right]` is not an alphabetical letter, decrement `right`.
   - Otherwise, swap the letters at `left` and `right`, then increment `left` and decrement `right`.
3. Return the modified string.

## Why It Works
By using the two-pointer approach and bypassing non-letter characters, we guarantee that only letters are swapped relative to their mirrored positions, while non-letter elements remain stationary.

## Complexity
- Time: `O(n)` where `n` is the length of the string, as each character is scanned at most once.
- Space: `O(1)` auxiliary space if mutable in-place (like in C++), or `O(n)` space to store the character representation (Python/Java).

## Python
```python
class Solution:
    def reverseOnlyLetters(self, s):
        chars = list(s)
        left, right = 0, len(chars) - 1
        
        while left < right:
            while left < right and not chars[left].isalpha():
                left += 1
            while left < right and not chars[right].isalpha():
                right -= 1
            if left < right:
                chars[left], chars[right] = chars[right], chars[left]
                left += 1
                right -= 1
                
        return "".join(chars)
```

## Java
```java
class Solution {
    public String reverseOnlyLetters(String s) {
        char[] chars = s.toCharArray();
        int left = 0;
        int right = chars.length - 1;
        
        while (left < right) {
            while (left < right && !Character.isLetter(chars[left])) {
                left++;
            }
            while (left < right && !Character.isLetter(chars[right])) {
                right--;
            }
            if (left < right) {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
                left++;
                right--;
            }
        }
        
        return new String(chars);
    }
}
```

## C++
```cpp
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !isalpha(s[left])) {
                left++;
            }
            while (left < right && !isalpha(s[right])) {
                right--;
            }
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};
```
