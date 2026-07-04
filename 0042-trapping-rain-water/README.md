# 0042 - Trapping Rain Water

## Problem
Given `n` non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

## Key Insight
The water above each position depends on the tallest bar to its left and the tallest bar to its right.

For each position, the trapped water is determined by the smaller of those two boundaries.

## Approach
Use two pointers, one starting at the left end and one at the right end.

- Track the tallest bar seen so far from each side.
- Move the pointer with the smaller current height inward.
- If the current height is below the tracked maximum on that side, it traps water equal to the difference.

This works because the smaller side is the limiting boundary for the current position.

## Why It Works
If the left side is lower, then the amount of water at the left pointer is fully determined by the tallest bar seen so far on the left, because the right boundary is already at least as tall as the current left height.

Symmetrically, if the right side is lower, the same argument applies from the right.

So moving the smaller side always preserves correctness and accounts for every trapped unit exactly once.

## Complexity
- Time: `O(n)`
- Space: `O(1)`

## Python
```python
class Solution:
    def trap(self, height):
        left = 0
        right = len(height) - 1
        left_max = 0
        right_max = 0
        water = 0

        while left < right:
            if height[left] < height[right]:
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    water += left_max - height[left]
                left += 1
            else:
                if height[right] >= right_max:
                    right_max = height[right]
                else:
                    water += right_max - height[right]
                right -= 1

        return water
```

## Java
```java
class Solution {
    public int trap(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
    }
}
```

## C++
```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = (int)height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
    }
};
```