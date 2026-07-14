class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actual_sum = 0;
        int expected_sum = 0;
        int missing_num = 0;
        int n = nums.size();
        expected_sum = n * (n+1)/2;
        for(int i = 0; i<n; i++){
            actual_sum = actual_sum + nums[i];
        }
        missing_num = expected_sum - actual_sum;
        return missing_num;
    }
};
