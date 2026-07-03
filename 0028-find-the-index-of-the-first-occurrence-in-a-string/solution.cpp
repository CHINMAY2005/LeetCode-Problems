#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        vector<int> lps = buildLps(needle);
        int i = 0;
        int j = 0;

        while (i < (int)haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == (int)needle.size()) {
                    return i - j;
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return -1;
    }

private:
    vector<int> buildLps(const string& needle) {
        vector<int> lps(needle.size(), 0);
        int length = 0;
        int i = 1;

        while (i < (int)needle.size()) {
            if (needle[i] == needle[length]) {
                length++;
                lps[i] = length;
                i++;
            } else if (length > 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }

        return lps;
    }
};