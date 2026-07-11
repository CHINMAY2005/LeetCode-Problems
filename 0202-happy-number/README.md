# 0202 - Happy Number

## Problem
Write an algorithm to determine if a number `n` is happy.

A happy number is defined by repeatedly replacing the number with the sum of the squares of its digits until it becomes `1`, or it loops endlessly in a cycle that does not include `1`.

## Key Insight
The process either reaches `1` or eventually repeats a previous value.

That means we can detect happiness by tracking the values we have already seen.

## Approach
Repeatedly compute the sum of the squares of the digits of the current number.

- If the number becomes `1`, return true.
- If the number has been seen before, a cycle exists and the number is not happy.
- Otherwise, store the number and continue.

## Why It Works
The transformation is deterministic, so if the sequence ever revisits a value, all future values will repeat as well.

Therefore, the only two possible outcomes are reaching `1` or entering a cycle, and the set of seen values separates those cases correctly.

## Complexity
- Time: `O(k log n)`
- Space: `O(k)`

Here `k` is the number of unique values generated before the process ends.

## Python
```python
class Solution:
    def isHappy(self, n):
        seen = set()

        while n != 1 and n not in seen:
            seen.add(n)
            total = 0

            while n > 0:
                digit = n % 10
                total += digit * digit
                n //= 10

            n = total

        return n == 1
```

## Java
```java
import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean isHappy(int n) {
        Set<Integer> seen = new HashSet<>();

        while (n != 1 && !seen.contains(n)) {
            seen.add(n);
            int total = 0;

            while (n > 0) {
                int digit = n % 10;
                total += digit * digit;
                n /= 10;
            }

            n = total;
        }

        return n == 1;
    }
}
```

## C++
```cpp
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            int total = 0;

            while (n > 0) {
                int digit = n % 10;
                total += digit * digit;
                n /= 10;
            }

            n = total;
        }

        return n == 1;
    }
};
```