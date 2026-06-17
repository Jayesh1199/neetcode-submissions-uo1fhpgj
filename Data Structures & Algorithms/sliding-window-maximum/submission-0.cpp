#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq; // Stores indices of array elements
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove indices that are out of the current window bounds
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // 2. Remove indices of elements smaller than the current element 
            // since they can no longer be the maximum in this or any future window
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // 3. Add the current element's index to the deque
            dq.push_back(i);
            
            // 4. Once the window has reached size 'k', add the max to our results
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};