#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // If there are less than 4 elements, it's impossible to form a quadruplet
        if (n < 4) return result;

        // Sort the array to easily skip duplicates and use two pointers
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicate values for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Two pointers for the remaining two elements
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to prevent integer overflow during addition
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicate values for the third element
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicate values for the fourth element
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        // Move both pointers inward
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++; // We need a larger sum
                    } else {
                        right--; // We need a smaller sum
                    }
                }
            }
        }
        
        return result;
    }
};