class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
            for(int i = 0; i < n; i++){
                n = n & (n-1);
                    count++;
            }
            return count;
    }
};
