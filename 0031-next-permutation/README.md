# 0031 - Next Permutation

## Problem
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

Given an array of integers `nums`, find the next permutation of `nums`. The replacement must be in place and use only constant extra memory.

## Key Insight
Lexicographical order is determined by scanning from left to right. To find the next greater permutation, we want to find the rightmost "breakpoint" where an element is smaller than the element following it. By replacing this element with the next larger element found to its right and reversing the remainder of the array, we get the lexicographically smallest increase.

## Approach
1. Scan the array from right to left to find the first element `nums[i]` that is smaller than its successor `nums[i + 1]`. Let this index be the `pivot`.
2. If no such `pivot` exists (meaning the array is sorted in descending order), reverse the entire array to transition back to the lexicographically smallest order and return.
3. If a `pivot` is found, scan from right to left again to find the first element `nums[j]` that is strictly greater than `nums[pivot]`. Let this be the `successor`.
4. Swap `nums[pivot]` and `nums[successor]`.
5. Reverse all elements to the right of the `pivot` (i.e. from index `pivot + 1` to the end of the array).

## Why It Works
Since the subarray to the right of the `pivot` is sorted in descending order prior to the swap, swapping `nums[pivot]` with the smallest element larger than it (`nums[successor]`) preserves this descending property. Reversing this suffix transitions it from descending to ascending order, which is the lexicographically smallest arrangement for that suffix.

## Complexity
- Time: `O(n)` where `n` is the number of elements in `nums`. We perform at most two linear scans and one partial reverse.
- Space: `O(1)` as all swaps and reverses are performed in-place.

## Python
```python
class Solution:
    def nextPermutation(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        # 1. Find the first decreasing element from the right
        pivot = -1
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                pivot = i
                break
                
        if pivot == -1:
            # Entire array is in descending order, reverse it
            nums.reverse()
            return
            
        # 2. Find the element just larger than the pivot to swap with
        successor = -1
        for j in range(n - 1, pivot, -1):
            if nums[j] > nums[pivot]:
                successor = j
                break
                
        # Swap
        nums[pivot], nums[successor] = nums[successor], nums[pivot]
        
        # 3. Reverse the elements after the pivot
        left = pivot + 1
        right = n - 1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
```

## Java
```java
class Solution {
    public void nextPermutation(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return;
        }
        
        int n = nums.length;
        // 1. Find the first decreasing element from the right
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        if (pivot == -1) {
            // Entire array is in descending order, reverse it
            reverse(nums, 0, n - 1);
            return;
        }
        
        // 2. Find the element just larger than the pivot to swap with
        int successor = -1;
        for (int j = n - 1; j > pivot; j--) {
            if (nums[j] > nums[pivot]) {
                successor = j;
                break;
            }
        }
        
        // Swap
        swap(nums, pivot, successor);
        
        // 3. Reverse the elements after the pivot
        reverse(nums, pivot + 1, n - 1);
    }
    
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
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
    void nextPermutation(vector[int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }
        
        // 1. Find the first decreasing element from the right
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        if (pivot == -1) {
            // Entire array is in descending order, reverse it
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // 2. Find the element just larger than the pivot to swap with
        int successor = -1;
        for (int j = n - 1; j > pivot; j--) {
            if (nums[j] > nums[pivot]) {
                successor = j;
                break;
            }
        }
        
        // Swap
        swap(nums[pivot], nums[successor]);
        
        // 3. Reverse the elements after the pivot
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
```
