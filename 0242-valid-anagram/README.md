# 0242 - Valid Anagram

## Problem
Given two strings `s` and `t`, return true if `t` is an anagram of `s`, and false otherwise.

An anagram uses the same characters with the same frequencies, just in a different order.

## Key Insight
Two strings are anagrams if and only if they contain exactly the same character counts.

That means we can compare frequency counts instead of checking every permutation.

## Approach
Count how many times each character appears in both strings.

- If the strings have different lengths, return false immediately.
- Build a frequency map for one string and subtract counts while scanning the other.
- If every count returns to zero, the strings are anagrams.

## Why It Works
An anagram must preserve the multiset of characters.

Matching character frequencies is both necessary and sufficient, so the frequency comparison captures exactly the condition the problem asks for.

## Complexity
- Time: `O(n)`
- Space: `O(1)` if the alphabet is fixed, otherwise `O(k)` for `k` distinct characters

## Python
```python
class Solution:
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False

        counts = {}
        for char in s:
            counts[char] = counts.get(char, 0) + 1

        for char in t:
            if char not in counts:
                return False
            counts[char] -= 1
            if counts[char] == 0:
                del counts[char]

        return not counts
```

## Java
```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }

        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (!counts.containsKey(c)) {
                return false;
            }

            counts.put(c, counts.get(c) - 1);
            if (counts.get(c) == 0) {
                counts.remove(c);
            }
        }

        return counts.isEmpty();
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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        for (char c : t) {
            if (!counts.count(c)) {
                return false;
            }

            counts[c]--;
            if (counts[c] == 0) {
                counts.erase(c);
            }
        }

        return counts.empty();
    }
};
```