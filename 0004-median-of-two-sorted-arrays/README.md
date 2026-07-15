# 0004 - Median of Two Sorted Arrays

## Problem
Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

## Key Insight
To achieve `O(log(m+n))` time complexity, we must perform a binary search. Instead of combining the arrays, we partition both arrays into two halves (left and right) such that the left half contains the same number of elements as the right half, and every element in the left half is less than or equal to every element in the right half.

## Approach
1. Ensure we binary search on the smaller array (say, `A` of size `m`) to minimize search space. Let the larger array be `B` of size `n`.
2. Binary search on array `A` with search range `[0, m]` to find partition index `i`. The partition index `j` in array `B` is calculated as `(m + n + 1) / 2 - i`.
3. Identify the boundary elements:
   - `maxLeftA` = element to the left of partition in `A`.
   - `minRightA` = element to the right of partition in `A`.
   - `maxLeftB` = element to the left of partition in `B`.
   - `minRightB` = element to the right of partition in `B`.
4. Check if we found the correct partition (`maxLeftA <= minRightB` and `maxLeftB <= minRightA`):
   - If total elements is odd, the median is `max(maxLeftA, maxLeftB)`.
   - If total elements is even, the median is `(max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0`.
5. Adjust search range:
   - If `maxLeftA > minRightB`, move search left: `high = i - 1`.
   - Otherwise, move search right: `low = i + 1`.

## Why It Works
By dividing the search space in half at each step, we quickly isolate the elements that would lie around the median index in a fully merged array without actually performing the merge.

## Complexity
- Time: `O(log(min(m, n)))` where `m` and `n` are the sizes of the two arrays.
- Space: `O(1)` since we only use a few pointer variables.

## Python
```python
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
            
        m, n = len(nums1), len(nums2)
        low, high = 0, m
        
        while low <= high:
            partitionX = (low + high) // 2
            partitionY = (m + n + 1) // 2 - partitionX
            
            maxLeftX = nums1[partitionX - 1] if partitionX > 0 else float('-inf')
            minRightX = nums1[partitionX] if partitionX < m else float('inf')
            
            maxLeftY = nums2[partitionY - 1] if partitionY > 0 else float('-inf')
            minRightY = nums2[partitionY] if partitionY < n else float('inf')
            
            if maxLeftX <= minRightY and maxLeftY <= minRightX:
                if (m + n) % 2 == 0:
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0
                else:
                    return max(maxLeftX, maxLeftY)
            elif maxLeftX > minRightY:
                high = partitionX - 1
            else:
                low = partitionX + 1
                
        return 0.0
```

## Java
```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.length;
        int n = nums2.length;
        int low = 0;
        int high = m;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? Integer.MIN_VALUE : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? Integer.MAX_VALUE : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? Integer.MIN_VALUE : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? Integer.MAX_VALUE : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return ((double) Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY)) / 2.0;
                } else {
                    return (double) Math.max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        
        return 0.0;
    }
}
```

## C++
```cpp
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        
        return 0.0;
    }
};
```
