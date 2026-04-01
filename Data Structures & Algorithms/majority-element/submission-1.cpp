class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i;
        int n = nums.size();
        unordered_map<int, int> freqMap;

        for(int i : nums){
            freqMap[i]++;
        
        if(freqMap[i] > n / 2){
            return i;
            }
        }
        return -1;

    }
};