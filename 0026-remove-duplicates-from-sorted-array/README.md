# 0026 - Remove Duplicates from Sorted Array

## Problem
Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in `nums`.

## Key Insight
Since the array is sorted, duplicates are guaranteed to be adjacent. We can use a two-pointer approach (a read pointer and a write pointer) to shift unique elements to the front of the array in a single pass.

## Approach
1. If the input array `nums` is empty, return `0`.
2. Initialize `writeIndex = 1`. This pointer tracks where the next unique element should be written.
3. Iterate a `readIndex` pointer from `1` to `nums.length - 1`:
   - If the element at `readIndex` is different from the previous element at `readIndex - 1`:
     - Assign `nums[writeIndex] = nums[readIndex]`.
     - Increment `writeIndex`.
4. Return `writeIndex` as the count of unique elements.

## Why It Works
By comparing each element with its predecessor, we identify when the value changes. Since the elements are sorted, this change indicates a new unique value. Writing it to `writeIndex` ensures that all unique values are packed at the front of the array.

## Complexity
- Time: `O(n)` where `n` is the length of `nums`, as we scan the array in a single pass.
- Space: `O(1)` auxiliary space, as the operation is done entirely in-place.

## Python
```python
class Solution:
    def removeDuplicates(self, nums):
        if not nums:
            return 0
            
        write_index = 1
        for read_index in range(1, len(nums)):
            if nums[read_index] != nums[read_index - 1]:
                nums[write_index] = nums[read_index]
                write_index += 1
                
        return write_index
```

## Java
```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int writeIndex = 1;
        for (int readIndex = 1; readIndex < nums.length; readIndex++) {
            if (nums[readIndex] != nums[readIndex - 1]) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        
        return writeIndex;
    }
}
```

## C++
```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int writeIndex = 1;
        for (int readIndex = 1; readIndex < (int)nums.size(); readIndex++) {
            if (nums[readIndex] != nums[readIndex - 1]) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        
        return writeIndex;
    }
};
```
