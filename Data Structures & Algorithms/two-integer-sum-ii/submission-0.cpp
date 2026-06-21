class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int currentSum = numbers[left] + numbers[right];
            
            if (currentSum == target) {
                // The problem states the array is 1-indexed
                return {left + 1, right + 1};
            } else if (currentSum < target) {
                // If the sum is too small, move the left pointer up to increase the sum
                left++;
            } else {
                // If the sum is too large, move the right pointer down to decrease the sum
                right--;
            }
        }
        
        return {}; // The problem guarantees exactly one valid solution, so we won't reach this.
    }
};