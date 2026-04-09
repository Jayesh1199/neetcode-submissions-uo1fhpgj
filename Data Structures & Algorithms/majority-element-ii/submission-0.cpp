class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int counts = 0;
        int n = nums.size();
        int limit = n/3;
        vector <int> result;
        unordered_map<int, int> count;
        
        
        for(int i = 0; i<nums.size();i++){
                count[nums[i]]++;
            }
        for(auto it: count){
            if(it.second > limit){
                result.push_back(it.first);
            }
        }
        return result;
    }
};