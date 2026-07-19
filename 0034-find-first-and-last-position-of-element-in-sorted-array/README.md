# 0034 - Find First and Last Position of Element in Sorted Array

## Problem
Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with $O(\log n)$ runtime complexity.

## Key Insight
Since the array is sorted, we can search for the boundaries using Binary Search. Instead of performing a standard search and scanning linearly (which could degenerate to $O(n)$ time if the target is duplicated many times), we can run two separate binary searches: one to locate the first occurrence (by pushing the boundary to the left when a match is found) and another to locate the last occurrence (by pushing the boundary to the right).

## Approach
1. Define a helper function `findBound(nums, target, isFirst)` that performs a binary search:
   - Initialize `left = 0`, `right = nums.length - 1`, and `bound = -1`.
   - While `left <= right`:
     - Calculate `mid = left + (right - left) / 2`.
     - If `nums[mid] == target`:
       - Update `bound = mid`.
       - If `isFirst == true` (searching for the starting index), shrink the search space to the left by setting `right = mid - 1`.
       - If `isFirst == false` (searching for the ending index), shrink the search space to the right by setting `left = mid + 1`.
     - If `nums[mid] < target`, search the right half: `left = mid + 1`.
     - If `nums[mid] > target`, search the left half: `right = mid - 1`.
   - Return the recorded `bound`.
2. In the main function, return `[findBound(nums, target, true), findBound(nums, target, false)]`.

## Why It Works
By recording the matching index and continuing to search in the remaining sub-array (either left or right), we are guaranteed to find the extreme bounds (first and last occurrences) of the target while maintaining logarithmic time complexity.

## Complexity
- Time: `O(log n)` since we run two independent binary searches, each taking `O(log n)` time.
- Space: `O(1)` as the search is performed in-place using simple scalar variables.

## Python
```python
class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        def findBound(is_first: bool) -> int:
            left, right = 0, len(nums) - 1
            bound = -1
            
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] == target:
                    bound = mid
                    if is_first:
                        right = mid - 1
                    else:
                        left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return bound
            
        return [findBound(True), findBound(False)]
```

## Java
```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = new int[2];
        result[0] = findBound(nums, target, true);
        result[1] = findBound(nums, target, false);
        return result;
    }
    
    private int findBound(int[] nums, int target, boolean isFirst) {
        int left = 0;
        int right = nums.length - 1;
        int bound = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return bound;
    }
}
```

## C++
```cpp
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }

private:
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return bound;
    }
};
```
