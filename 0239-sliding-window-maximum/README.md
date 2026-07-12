# 0239 - Sliding Window Maximum

## Problem
Given an array of integers `nums` and an integer `k`, return the maximum value in each sliding window of size `k`.

The window moves from left to right by one position at a time.

## Key Insight
We only need to keep track of candidates for the current maximum.

A monotonic deque stores indices in decreasing order of their values, so the front always holds the maximum of the current window.

## Approach
Use a deque of indices.

- Remove indices from the front if they are outside the current window.
- Remove indices from the back while their values are less than or equal to the current value.
- Add the current index to the back.
- Once the first window is formed, record the value at the front of the deque as the window maximum.

## Why It Works
The deque always contains indices of elements that could still become the maximum of the current or a future window.

Elements smaller than the current value can never become a maximum again while the current value remains in the deque, so removing them preserves correctness and keeps the structure efficient.

## Complexity
- Time: `O(n)`
- Space: `O(k)`

## Python
```python
from collections import deque


class Solution:
    def maxSlidingWindow(self, nums, k):
        dq = deque()
        result = []

        for i, num in enumerate(nums):
            while dq and dq[0] <= i - k:
                dq.popleft()

            while dq and nums[dq[-1]] <= num:
                dq.pop()

            dq.append(i)

            if i >= k - 1:
                result.append(nums[dq[0]])

        return result
```

## Java
```java
import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k == 0) {
            return new int[0];
        }

        Deque<Integer> deque = new ArrayDeque<>();
        int[] result = new int[nums.length - k + 1];
        int index = 0;

        for (int i = 0; i < nums.length; i++) {
            while (!deque.isEmpty() && deque.peekFirst() <= i - k) {
                deque.pollFirst();
            }

            while (!deque.isEmpty() && nums[deque.peekLast()] <= nums[i]) {
                deque.pollLast();
            }

            deque.offerLast(i);

            if (i >= k - 1) {
                result[index++] = nums[deque.peekFirst()];
            }
        }

        return result;
    }
}
```

## C++
```cpp
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < (int)nums.size(); i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
```