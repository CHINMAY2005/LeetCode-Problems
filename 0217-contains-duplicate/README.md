# 0217 - Contains Duplicate

## Problem
Given an integer array `nums`, return true if any value appears at least twice in the array, and return false if every element is distinct.

## Key Insight
If we have already seen a number once, seeing it again means the array contains a duplicate.

That makes a set the simplest way to track previously visited values.

## Approach
Scan the array from left to right and store each number in a set.

- If the current number is already in the set, return true immediately.
- Otherwise add it to the set and continue.
- If the scan finishes without a repeat, return false.

## Why It Works
The set contains exactly the numbers seen so far.

If a number appears again, the problem's condition is satisfied; if no number repeats during the scan, then all values are distinct.

## Complexity
- Time: `O(n)`
- Space: `O(n)`

## Python
```python
class Solution:
    def containsDuplicate(self, nums):
        seen = set()

        for num in nums:
            if num in seen:
                return True
            seen.add(num)

        return False
```

## Java
```java
import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();

        for (int num : nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.add(num);
        }

        return false;
    }
}
```

## C++
```cpp
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};
```