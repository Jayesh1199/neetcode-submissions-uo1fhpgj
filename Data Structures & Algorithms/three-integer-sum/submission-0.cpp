class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        // 1. Sort the array to enable two pointers and easily skip duplicates
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // 2. Skip duplicates for our fixed first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // 3. Initialize two pointers
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum > 0) {
                    right--; // Sum is too large, decrement the right pointer
                } else if (sum < 0) {
                    left++;  // Sum is too small, increment the left pointer
                } else {
                    // Found a valid triplet
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move pointers to evaluate the next potential matches
                    left++;
                    right--;
                    
                    // Skip duplicates for the second and third elements to prevent duplicate triplets
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return res;
    }
};