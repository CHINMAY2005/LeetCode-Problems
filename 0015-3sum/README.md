# 0015 - 3Sum

## Problem
Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

## Key Insight
Sorting the array helps us easily avoid duplicates and apply a two-pointer approach to search for matching pairs in $O(n)$ time for each element, bringing down the total time complexity to $O(n^2)$.

## Approach
1. Sort the input array `nums`.
2. Iterate through `nums` with pointer `i` from `0` to `n - 3`:
   - If `nums[i] > 0`, break the loop (since all elements to the right are also positive, we cannot sum to 0).
   - If `i > 0` and `nums[i] == nums[i - 1]`, skip the iteration to avoid duplicate triplets.
   - Initialize two pointers: `left = i + 1` and `right = n - 1`.
   - While `left < right`:
     - Calculate `total = nums[i] + nums[left] + nums[right]`.
     - If `total < 0`, we need a larger value, so we increment `left`.
     - If `total > 0`, we need a smaller value, so we decrement `right`.
     - If `total == 0`, we found a matching triplet. Append it to our result, then advance `left` and `right` while skipping duplicate elements at both pointers to prevent duplicate triplets.
3. Return the result list.

## Why It Works
Sorting simplifies the search from $O(n^3)$ brute force to $O(n^2)$ by allowing us to use a two-pointer approach (similar to 2Sum on a sorted array) for the remaining two values.

## Complexity
- Time: `O(n^2)` where `n` is the length of `nums`. Sorting takes `O(n log n)`, and the nested loop takes `O(n^2)`.
- Space: `O(log n)` to `O(n)` depending on the sorting implementation.

## Python
```python
class Solution:
    def threeSum(self, nums):
        nums.sort()
        result = []
        n = len(nums)
        
        for i in range(n - 2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue
                
            left = i + 1
            right = n - 1
            
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total < 0:
                    left += 1
                elif total > 0:
                    right -= 1
                else:
                    result.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
                    
        return result
```

## Java
```java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (total < 0) {
                    left++;
                } else if (total > 0) {
                    right--;
                } else {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        
        return result;
    }
}
```

## C++
```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (total < 0) {
                    left++;
                } else if (total > 0) {
                    right--;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        
        return result;
    }
};
```
