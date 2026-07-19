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
