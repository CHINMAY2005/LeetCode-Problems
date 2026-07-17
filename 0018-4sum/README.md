# 0018 - 4Sum

## Problem
Given an array `nums` of `n` integers, return an array of all the unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:
- `0 <= a, b, c, d < n`
- `a`, `b`, `c`, and `d` are distinct.
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in any order.

## Key Insight
By sorting the array and pinning the first two numbers (`nums[i]` and `nums[j]`), we can reduce the 4Sum problem to a 2Sum search on the remaining subarray. We use a two-pointer approach for the remaining two values to achieve an $O(n^3)$ solution.

## Approach
1. Sort the input array `nums`.
2. Iterate `i` from `0` to `n - 4` (first element):
   - Skip duplicate values: `if i > 0 and nums[i] == nums[i - 1]: continue`.
3. Iterate `j` from `i + 1` to `n - 3` (second element):
   - Skip duplicate values: `if j > i + 1 and nums[j] == nums[j - 1]: continue`.
4. Initialize two pointers: `left = j + 1` and `right = n - 1` (third and fourth elements).
5. While `left < right`:
   - Calculate the sum of the four elements. *(Note: cast to 64-bit integer in C++ and Java to avoid overflow).*
   - If the sum is less than `target`, increment `left`.
   - If the sum is greater than `target`, decrement `right`.
   - If the sum equals `target`, append the quadruplet to our result list. Move both pointers inward and skip duplicates.
6. Return the result.

## Why It Works
Similar to 3Sum, sorting allows us to easily skip duplicate values at each decision level. It also guarantees that moving `left` to the right increases the sum, and moving `right` to the left decreases it, enabling a correct two-pointer scanning behavior.

## Complexity
- Time: `O(n^3)` where `n` is the length of `nums`. There are nested loops for `i` and `j`, and the two-pointer inner scan runs in `O(n)`.
- Space: `O(log n)` to `O(n)` depending on the sorting implementation.

## Python
```python
class Solution:
    def fourSum(self, nums, target):
        nums.sort()
        result = []
        n = len(nums)
        
        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                    
                left = j + 1
                right = n - 1
                
                while left < right:
                    total = nums[i] + nums[j] + nums[left] + nums[right]
                    if total < target:
                        left += 1
                    elif total > target:
                        right -= 1
                    else:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
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
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long total = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (total < target) {
                        left++;
                    } else if (total > target) {
                        right--;
                    } else {
                        result.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long total = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (total < target) {
                        left++;
                    } else if (total > target) {
                        right--;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
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
        }
        
        return result;
    }
};
```
