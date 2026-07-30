class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
                {
                    if(nums[i]== nums[j])
                        count++;
                }
        }
        if(count>=1)
            return true;
        else
            return false;
    }
};