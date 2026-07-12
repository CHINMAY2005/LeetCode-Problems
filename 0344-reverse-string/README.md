# 0344 - Reverse String

## Problem
Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array in-place with `O(1)` extra memory.

## Key Insight
Use a two-pointer approach starting from both ends of the character array and swap elements until they meet in the middle.

## Approach
1. Initialize two pointers: `left` at the beginning (`0`) and `right` at the end (`s.length - 1`) of the array.
2. While `left < right`:
   - Swap the characters at `s[left]` and `s[right]`.
   - Increment `left` and decrement `right`.

This reverses the array in-place.

## Why It Works
By swapping characters from opposite ends and moving inward, each character is moved to its correct mirrored position. Since the pointers meet in the middle, every element is swapped exactly once.

## Complexity
- Time: `O(n)` where `n` is the length of the string, as we traverse half the array.
- Space: `O(1)` since we only use a few helper variables for swapping in-place.

## Python
```python
class Solution:
    def reverseString(self, s):
        """
        Do not return anything, modify s in-place instead.
        """
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
```

## Java
```java
class Solution {
    public void reverseString(char[] s) {
        int left = 0;
        int right = s.length - 1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
}
```

## C++
```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
```
