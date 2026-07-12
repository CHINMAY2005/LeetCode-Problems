# 0345 - Reverse Vowels of a String

## Problem
Given a string `s`, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

## Key Insight
Use a two-pointer approach where we scan from both ends. We only swap characters when both pointers land on a vowel.

## Approach
1. Initialize two pointers: `left` at `0` and `right` at `s.length() - 1`.
2. While `left < right`:
   - Move `left` forward until it points to a vowel.
   - Move `right` backward until it points to a vowel.
   - If `left < right`, swap `s[left]` and `s[right]`, then increment `left` and decrement `right`.
3. Return the modified string.

## Why It Works
By checking elements from both ends and only swapping when both pointers are on vowels, we ensure that only vowels are reversed while non-vowels remain in their original positions.

## Complexity
- Time: `O(n)` where `n` is the length of the string, as each character is visited at most twice.
- Space: `O(1)` auxiliary space if we modify the string in-place (in C++), or `O(n)` space to store the character array/list (in Python/Java since strings are immutable).

## Python
```python
class Solution:
    def reverseVowels(self, s):
        vowels = set("aeiouAEIOU")
        chars = list(s)
        left, right = 0, len(chars) - 1
        
        while left < right:
            while left < right and chars[left] not in vowels:
                left += 1
            while left < right and chars[right] not in vowels:
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
    public String reverseVowels(String s) {
        char[] chars = s.toCharArray();
        int left = 0;
        int right = chars.length - 1;
        
        boolean[] isVowel = new boolean[128];
        for (char c : "aeiouAEIOU".toCharArray()) {
            isVowel[c] = true;
        }
        
        while (left < right) {
            while (left < right && !isVowel[chars[left]]) {
                left++;
            }
            while (left < right && !isVowel[chars[right]]) {
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
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        auto isVowel = [](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            while (left < right && !isVowel(s[right])) {
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
