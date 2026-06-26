#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            // Calculate the current area
            int current_water = min(heights[left], heights[right]) * (right - left);
            max_water = max(max_water, current_water);
            
            // Move the pointer that has the smaller height
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};