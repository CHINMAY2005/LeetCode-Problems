#include <string>
#include <climits>
#include <cctype>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i == n) {
            return 0;
        }
        
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        int res = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            res = res * 10 + digit;
            i++;
        }
        
        return sign * res;
    }
};
