# 0010 - Regular Expression Matching

## Problem
Given an input string `s` and a pattern `p`, determine whether the entire string matches the pattern.

The pattern supports two special characters:
- `.` matches any single character
- `*` matches zero or more of the preceding element

## Key Insight
This is a prefix-matching dynamic programming problem.

For each prefix of `s` and each prefix of `p`, we only need to know whether they match completely.

## Approach
Let `dp[i][j]` mean whether `s[:i]` matches `p[:j]`.

- If `p[j - 1]` is a normal character or `.`, it must match the current character in `s`, and we inherit from `dp[i - 1][j - 1]`.
- If `p[j - 1]` is `*`, we have two choices:
  - use `*` as zero occurrences of the previous pattern element, so we check `dp[i][j - 2]`
  - use `*` as one or more occurrences, if the previous element matches the current character, so we check `dp[i - 1][j]`

We also initialize the empty-string row so patterns like `a*` can match an empty string.

## Why It Works
Each state `dp[i][j]` depends only on smaller prefixes.

The recurrence covers every valid way a character or `*` can contribute to a full match, so if a match exists, the DP will discover it; if the DP says true, the transitions guarantee the match is valid.

## Complexity
- Time: `O(mn)`
- Space: `O(mn)`

## Python
```python
class Solution:
    def isMatch(self, s, p):
        m = len(s)
        n = len(p)

        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True

        for j in range(2, n + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 2]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] != '*':
                    dp[i][j] = dp[i - 1][j - 1] and (p[j - 1] == '.' or p[j - 1] == s[i - 1])
                else:
                    dp[i][j] = dp[i][j - 2]
                    if p[j - 2] == '.' or p[j - 2] == s[i - 1]:
                        dp[i][j] = dp[i][j] or dp[i - 1][j]

        return dp[m][n]
```

## Java
```java
class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length();
        int n = p.length();

        boolean[][] dp = new boolean[m + 1][n + 1];
        dp[0][0] = true;

        for (int j = 2; j <= n; j++) {
            if (p.charAt(j - 1) == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char patternChar = p.charAt(j - 1);

                if (patternChar != '*') {
                    dp[i][j] = dp[i - 1][j - 1]
                        && (patternChar == '.' || patternChar == s.charAt(i - 1));
                } else {
                    dp[i][j] = dp[i][j - 2];
                    char previous = p.charAt(j - 2);
                    if (previous == '.' || previous == s.charAt(i - 1)) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
}
```

## C++
```cpp
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = (int)s.size();
        int n = (int)p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*') {
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
                } else {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
```