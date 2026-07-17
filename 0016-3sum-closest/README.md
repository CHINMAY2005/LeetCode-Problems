# 0016 - 3Sum Closest

## Problem
Given an integer array `nums` of length `n` and an integer `target`, find three integers in `nums` such that the sum is closest to `target`.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

## Key Insight
Sorting the array lets us use a two-pointer search to systematically narrow down the closest sum. For each element `nums[i]`, we can search for the other two elements in $O(n)$ time.

## Approach
1. Sort the input array `nums`.
2. Initialize `closestSum = nums[0] + nums[1] + nums[2]`.
3. Iterate through `nums` with pointer `i` from `0` to `n - 3`:
   - Initialize two pointers: `left = i + 1` and `right = n - 1`.
   - While `left < right`:
     - Calculate `currentSum = nums[i] + nums[left] + nums[right]`.
     - If `currentSum == target`, return `target` immediately as it is the closest possible sum.
     - If `abs(currentSum - target) < abs(closestSum - target)`, update `closestSum = currentSum`.
     - If `currentSum < target`, increment `left` to increase the sum.
     - If `currentSum > target`, decrement `right` to decrease the sum.
4. Return `closestSum`.

## Why It Works
Sorting simplifies the search. When `currentSum < target`, we know that incrementing the left pointer will move the sum closer to `target` (or past it), whereas decrementing the right pointer would only make the sum smaller (further away from the target).

## Complexity
- Time: `O(n^2)` where `n` is the length of `nums`. Sorting takes `O(n log n)`, and the nested loop takes `O(n^2)`.
- Space: `O(log n)` to `O(n)` depending on the sorting implementation.

## Python
```python
class Solution:
    def threeSumClosest(self, nums, target):
        nums.sort()
        n = len(nums)
        closest_sum = nums[0] + nums[1] + nums[2]
        
        for i in range(n - 2):
            left = i + 1
            right = n - 1
            
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
                if current_sum == target:
                    return target
                    
                if abs(current_sum - target) < abs(closest_sum - target):
                    closest_sum = current_sum
                    
                if current_sum < target:
                    left += 1
                else:
                    right -= 1
                    
        return closest_sum
```

## Java
```java
import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                if (currentSum == target) {
                    return target;
                }
                
                if (Math.abs(currentSum - target) < Math.abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closestSum;
    }
}
```

## C++
```cpp
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                if (currentSum == target) {
                    return target;
                }
                
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closestSum;
    }
};
```
