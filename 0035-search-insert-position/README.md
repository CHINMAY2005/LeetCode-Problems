# 0035 - Search Insert Position

## Problem
Given a sorted array of distinct integers and a target value, return the index if the target is found.

If not, return the index where it would be if it were inserted in order.

## Key Insight
Because the array is sorted, binary search can find both the target and the insertion point.

## Approach
Use binary search to narrow the range.

- If the middle value equals the target, return its index.
- If the middle value is less than the target, search the right half.
- Otherwise search the left half.

When the search ends, `left` is the correct insertion position.

## Why It Works
Binary search preserves the invariant that the target, if present, must lie inside the current search interval.

When the interval becomes empty, every value before `left` is smaller than the target and every value after `left` is larger, so `left` is exactly the insertion position.

## Complexity
- Time: `O(log n)`
- Space: `O(1)`

## Python
```python
class Solution:
    def searchInsert(self, nums, target):
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return left
```

## Java
```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
}
```

## C++
```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};
```