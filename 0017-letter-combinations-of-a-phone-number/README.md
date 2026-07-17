# 0017 - Letter Combinations of a Phone Number

## Problem
Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given. Note that 1 does not map to any letters.

## Key Insight
This problem is a classic application of recursion and backtracking. Since we need to generate all possible combinations, we can build the strings character-by-character. For each digit, we branch into all of its possible letter mappings.

## Approach
1. If the input `digits` string is empty, return an empty array/list.
2. Maintain a phone mapping (e.g., `'2'` maps to `"abc"`, `'3'` to `"def"`, etc.).
3. Define a helper backtracking function `backtrack(index, path)`:
   - Base Case: If `index` equals the length of `digits`, we have formed a complete combination. Add `path` to the result list and return.
   - Recursive Step: Get the letter mapping for `digits[index]`. For each letter in the mapping:
     - Append the letter to `path`.
     - Recursively call `backtrack(index + 1, path)`.
     - Remove the letter from `path` (backtrack) to try the next letters.
4. Start the process with `backtrack(0, "")` and return the collected combinations.

## Why It Works
Backtracking systematically walks through a decision tree where each level represents a digit in the input. By building combinations depth-first, we ensure all configurations are explored, and removing the last character (backtracking) lets us reuse the buffer efficiently.

## Complexity
- Time: `O(4^n * n)` where `n` is the length of `digits`. The digit '7' and '9' have 4 letters, while others have 3. In the worst case, there are up to $4^n$ combinations, and building each string takes `O(n)` time.
- Space: `O(n)` to store the recursion stack and the path buffer.

## Python
```python
class Solution:
    def letterCombinations(self, digits):
        if not digits:
            return []
            
        phone_map = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }
        
        result = []
        
        def backtrack(index, path):
            if index == len(digits):
                result.append("".join(path))
                return
                
            letters = phone_map[digits[index]]
            for letter in letters:
                path.append(letter)
                backtrack(index + 1, path)
                path.pop()
                
        backtrack(0, [])
        return result
```

## Java
```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    private final Map<Character, String> phoneMap = new HashMap<>() {{
        put('2', "abc"); put('3', "def"); put('4', "ghi"); put('5', "jkl");
        put('6', "mno"); put('7', "pqrs"); put('8', "tuv"); put('9', "wxyz");
    }};
    
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (digits == null || digits.length() == 0) {
            return result;
        }
        
        backtrack(digits, 0, new StringBuilder(), result);
        return result;
    }
    
    private void backtrack(String digits, int index, StringBuilder path, List<String> result) {
        if (index == digits.length()) {
            result.add(path.toString());
            return;
        }
        
        String letters = phoneMap.get(digits.charAt(index));
        for (int i = 0; i < letters.length(); i++) {
            path.append(letters.charAt(i));
            backtrack(digits, index + 1, path, result);
            path.deleteCharAt(path.length() - 1);
        }
    }
}
```

## C++
```cpp
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
```
