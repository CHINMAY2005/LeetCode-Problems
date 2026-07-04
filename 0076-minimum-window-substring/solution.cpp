#include <string>
#include <unordered_map>
#include <climits>
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