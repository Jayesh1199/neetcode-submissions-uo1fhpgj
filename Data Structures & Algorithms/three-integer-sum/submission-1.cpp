/*class Solution {
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
*/

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> results;
        
        // Step 1: Always sort first!
        std::sort(nums.begin(), nums.end()); 

        for (int i = 0; i < nums.size(); i++) {
            
            // DUPLICATE CHECK FOR ANCHOR (i): 
            // If this anchor is the same as the last one, skip it to avoid duplicate triplets.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; 
            }
            
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == 0) {
                    results.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    
                    // DUPLICATE CHECK FOR LEFT POINTER (j):
                    // Keep skipping forward if it's the exact same number we just looked at
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    
                    // DUPLICATE CHECK FOR RIGHT POINTER (k):
                    // Keep skipping backward if it's the exact same number we just looked at
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } 
                else if (sum > 0) {
                    k--; // Too heavy
                } 
                else {
                    j++; // Too light
                }
            }
        }
        
        return results;
    }
};