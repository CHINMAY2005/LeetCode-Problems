# 0001 - Two Sum

## Problem
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

You may assume exactly one valid answer exists, and you may not use the same element twice.

## Key Insight
Use a hash map to store values we have already seen and their indices.

If the current number needs a partner that has already appeared, the answer is available immediately.

## Approach
For each number `nums[i]`, compute the complement `target - nums[i]`.
- If the complement is already in the hash map, return the stored index and the current index.
- Otherwise, store the current number and index in the hash map.

This works in one pass and avoids the $O(n^2)$ brute-force search.

## Why This Works
When we reach index `i`, the map contains exactly the values seen before `i`.
If `nums[i]` needs a partner `complement` and that partner was seen earlier, the pair is valid and uses two different indices.

## Complexity
- Time: `O(n)`
- Space: `O(n)`

## Python
```python
class Solution:
    def twoSum(self, nums, target):
        seen = {}

        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i
```

## Java
```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> seen = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (seen.containsKey(complement)) {
                return new int[] { seen.get(complement), i };
            }
            seen.put(nums[i], i);
        }

        return new int[0];
    }
}
```

## C++
```cpp
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};
```
