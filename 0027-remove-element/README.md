# 0027 - Remove Element

## Problem
Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` in-place. The order of the elements may be changed. Then return the number of elements in `nums` which are not equal to `val`.

## Key Insight
Using a two-pointer approach (a read index and a write index), we can filter out elements matching `val` in a single pass. The elements that do not match `val` are copied to the beginning of the array, while matching elements are overwritten.

## Approach
1. Initialize a `writeIndex = 0` to track the placement position of the next non-`val` element.
2. Iterate `readIndex` from `0` to `nums.length - 1`:
   - If the element at `nums[readIndex]` is not equal to `val`:
     - Assign `nums[writeIndex] = nums[readIndex]`.
     - Increment `writeIndex`.
3. Return `writeIndex` as the number of elements not equal to `val`.

## Why It Works
Since we only write to `writeIndex` when we encounter an element not equal to `val`, we effectively pack all non-`val` elements at the beginning of the array. The `writeIndex` also serves as the correct count of elements to return.

## Complexity
- Time: `O(n)` where `n` is the length of `nums`, as we inspect each element exactly once.
- Space: `O(1)` auxiliary space, as all operations are performed in-place.

## Python
```python
class Solution:
    def removeElement(self, nums, val):
        write_index = 0
        for read_index in range(len(nums)):
            if nums[read_index] != val:
                nums[write_index] = nums[read_index]
                write_index += 1
                
        return write_index
```

## Java
```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int writeIndex = 0;
        for (int readIndex = 0; readIndex < nums.length; readIndex++) {
            if (nums[readIndex] != val) {
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
    int removeElement(vector<int>& nums, int val) {
        int writeIndex = 0;
        for (int readIndex = 0; readIndex < (int)nums.size(); readIndex++) {
            if (nums[readIndex] != val) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        
        return writeIndex;
    }
};
```
