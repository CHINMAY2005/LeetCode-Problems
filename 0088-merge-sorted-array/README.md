# 0088 - Merge Sorted Array

## Problem
You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, along with two integers `m` and `n`.

Merge `nums2` into `nums1` so that `nums1` becomes one sorted array.

## Key Insight
Because `nums1` has extra space at the end, the merge can be done from the back.

That avoids overwriting values in `nums1` before they are compared.

## Approach
Use three pointers:

- `i` at the last valid element of `nums1`
- `j` at the last element of `nums2`
- `k` at the last position of `nums1`

Compare `nums1[i]` and `nums2[j]`, place the larger one at `nums1[k]`, and move the corresponding pointer backward.

If `nums2` still has elements left, copy them into `nums1`.

## Why It Works
The largest remaining value among the two arrays must belong at the end of the merged array.

By filling `nums1` from right to left, every comparison is made against untouched data, so no value is lost before it is used.

## Complexity
- Time: `O(m + n)`
- Space: `O(1)`

## Python
```python
class Solution:
    def merge(self, nums1, m, nums2, n):
        i = m - 1
        j = n - 1
        k = m + n - 1

        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
```

## Java
```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
}
```

## C++
```cpp
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};
```