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