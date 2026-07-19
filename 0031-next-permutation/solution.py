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
