/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        // 'left' pointer tracks the position for the next unique element
        int left = 1; 
        
        // 'right' pointer scans through the array
        for (int right = 1; right < nums.size(); right++) {
            // If we find a new unique element
            if (nums[right] != nums[right - 1]) {
                nums[left] = nums[right];
                left++;
            }
        }
        
        return left;
    }
};
*/
class Solution{
public:
    int removeDuplicates(std :: vector<int> &nums){
        if(nums.empty()){
            return 0;
        }
        int slow = 1;
        for(int fast = 1; fast < nums.size(); fast++){
            if(nums[fast] != nums[fast - 1]){
                nums[slow] = nums[fast]; // Overrite
                slow++;
            }
        }
        return slow;
    }

};