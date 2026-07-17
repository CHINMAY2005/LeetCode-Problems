#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char, string> phoneMap = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        string path = "";
        backtrack(digits, 0, path, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& path, vector<string>& result) {
        if (index == (int)digits.length()) {
            result.push_back(path);
            return;
        }
        
        string letters = phoneMap[digits[index]];
        for (char c : letters) {
            path.push_back(c);
            backtrack(digits, index + 1, path, result);
            path.pop_back();
        }
    }
};
