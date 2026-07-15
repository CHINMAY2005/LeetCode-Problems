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
