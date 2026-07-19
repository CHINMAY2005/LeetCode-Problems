# 0033 - Search in Rotated Sorted Array

## Problem
There is an integer array `nums` sorted in ascending order (with distinct values).

Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (0-indexed).

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

You must write an algorithm with $O(\log n)$ runtime complexity.

## Key Insight
Even though the array has been rotated, dividing it in half will always yield at least one subarray that is fully sorted. We can leverage this property to perform a modified binary search: by identifying which half is sorted, we can check if the target falls within that sorted range and shrink our search boundary accordingly.

## Approach
1. Initialize two pointers: `left = 0` and `right = nums.length - 1`.
2. While `left <= right`:
   - Calculate `mid = left + (right - left) / 2`.
   - If `nums[mid] == target`, return `mid`.
   - **Check which half is sorted**:
     - If `nums[left] <= nums[mid]`, the left half is sorted:
       - Check if `target` lies within the sorted left half (`nums[left] <= target < nums[mid]`). If so, move the `right` pointer to `mid - 1`.
       - Otherwise, the target must be in the right half: move `left = mid + 1`.
     - Else, the right half must be sorted:
       - Check if `target` lies within the sorted right half (`nums[mid] < target <= nums[right]`). If so, move the `left` pointer to `mid + 1`.
       - Otherwise, move `right = mid - 1`.
3. If the loop exits without finding the target, return `-1`.

## Why It Works
In any rotated sorted array, the pivot point splits the array such that one half remains normally sorted while the other half contains the rotation boundary. By prioritizing search queries in the sorted half (where simple boundaries `[low, high]` apply), we can eliminate half of the remaining array at each step, maintaining the $O(\log n)$ logarithmic runtime.

## Complexity
- Time: `O(log n)` as we divide the search space in half at each iteration.
- Space: `O(1)` since we only use a few pointer variables.

## Python
```python
class Solution:
    def search(self, nums: list[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if nums[mid] == target:
                return mid
                
            # Check if left half is sorted
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            # Otherwise, the right half must be sorted
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
                    
        return -1
```

## Java
```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check if left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // Otherwise, right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
}
```

## C++
```cpp
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Check if left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Otherwise, right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
```
