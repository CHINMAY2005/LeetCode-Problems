# 0011 - Container With Most Water

## Problem
Given an array of non-negative integers `height`, where each value represents a vertical line on the x-axis, choose two lines that with the x-axis form a container holding the most water.

Return the maximum amount of water the container can store.

## Key Insight
The area is limited by the shorter line.

If we want a larger area, we need either a wider gap or a taller limiting side. Since the width only shrinks as we move inward, the only useful move is to discard the shorter line and look for a taller one.

## Approach
Use two pointers, one at the start and one at the end of the array.

- Compute the current area using the shorter of the two heights.
- Update the best answer.
- Move the pointer at the shorter line inward.

This greedily checks only the pairs that can possibly improve the answer.

## Why It Works
If `height[left] <= height[right]`, then keeping `left` fixed while moving `right` inward can never produce a better container with the same limiting height and a smaller width.

So the shorter side must move, because only that move can increase the limiting height enough to offset the reduced width.

## Complexity
- Time: `O(n)`
- Space: `O(1)`

## Python
```python
class Solution:
    def maxArea(self, height):
        left = 0
        right = len(height) - 1
        best = 0

        while left < right:
            width = right - left
            best = max(best, min(height[left], height[right]) * width)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return best
```

## Java
```java
class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int best = 0;

        while (left < right) {
            int width = right - left;
            best = Math.max(best, Math.min(height[left], height[right]) * width);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return best;
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
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = (int)height.size() - 1;
        int best = 0;

        while (left < right) {
            int width = right - left;
            best = max(best, min(height[left], height[right]) * width);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return best;
    }
};
```