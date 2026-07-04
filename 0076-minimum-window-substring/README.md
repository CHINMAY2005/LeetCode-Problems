# 0076 - Minimum Window Substring

## Problem
Given two strings `s` and `t`, return the minimum window in `s` which contains every character in `t` including duplicates.

If there is no such window, return the empty string.

## Key Insight
Use a sliding window with character counts.

Expand the window until it contains all required characters, then shrink it as much as possible while preserving validity.

## Approach
Maintain:
- a frequency map for characters in `t`
- a count of how many required characters are currently satisfied
- two pointers defining the current window in `s`

Expand the right pointer to include more characters.

When the window becomes valid, move the left pointer inward to remove unnecessary characters and record the smallest valid window.

## Why It Works
The window is only valid when it contains at least the required number of each character from `t`.

Once valid, shrinking from the left never misses a smaller valid answer because any character removed only makes the window less constrained or invalid, and we stop shrinking exactly when validity would break.

## Complexity
- Time: `O(m + n)`
- Space: `O(k)` where `k` is the number of distinct characters in `t`

## Python
```python
class Solution:
    def minWindow(self, s, t):
        if not t:
            return ''

        need = {}
        for char in t:
            need[char] = need.get(char, 0) + 1

        have = {}
        formed = 0
        required = len(need)
        left = 0
        best = (float('inf'), 0, 0)

        for right, char in enumerate(s):
            have[char] = have.get(char, 0) + 1
            if char in need and have[char] == need[char]:
                formed += 1

            while formed == required:
                if right - left + 1 < best[0]:
                    best = (right - left + 1, left, right)

                left_char = s[left]
                have[left_char] -= 1
                if left_char in need and have[left_char] < need[left_char]:
                    formed -= 1
                left += 1

        return '' if best[0] == float('inf') else s[best[1]:best[2] + 1]
```

## Java
```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    public String minWindow(String s, String t) {
        if (t.isEmpty()) {
            return "";
        }

        Map<Character, Integer> need = new HashMap<>();
        for (char c : t.toCharArray()) {
            need.put(c, need.getOrDefault(c, 0) + 1);
        }

        Map<Character, Integer> have = new HashMap<>();
        int formed = 0;
        int required = need.size();
        int left = 0;
        int bestLen = Integer.MAX_VALUE;
        int bestLeft = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            have.put(c, have.getOrDefault(c, 0) + 1);

            if (need.containsKey(c) && have.get(c).intValue() == need.get(c).intValue()) {
                formed++;
            }

            while (formed == required) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestLeft = left;
                }

                char leftChar = s.charAt(left);
                have.put(leftChar, have.get(leftChar) - 1);
                if (need.containsKey(leftChar) && have.get(leftChar) < need.get(leftChar)) {
                    formed--;
                }
                left++;
            }
        }

        return bestLen == Integer.MAX_VALUE ? "" : s.substring(bestLeft, bestLeft + bestLen);
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
    string minWindow(string s, string t) {
        if (t.empty()) {
            return "";
        }

        unordered_map<char, int> need;
        for (char c : t) {
            need[c]++;
        }

        unordered_map<char, int> have;
        int formed = 0;
        int required = (int)need.size();
        int left = 0;
        int bestLen = INT_MAX;
        int bestLeft = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            have[c]++;

            if (need.count(c) && have[c] == need[c]) {
                formed++;
            }

            while (formed == required) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestLeft = left;
                }

                char leftChar = s[left];
                have[leftChar]--;
                if (need.count(leftChar) && have[leftChar] < need[leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestLeft, bestLen);
    }
};
```