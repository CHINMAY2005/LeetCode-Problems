#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
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
