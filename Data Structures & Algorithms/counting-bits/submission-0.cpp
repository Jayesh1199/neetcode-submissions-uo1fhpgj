class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            // dp[i >> 1] gets the set bits of i / 2 (shifts bits right by 1)
            // (i & 1) adds 1 if the current number is odd (least significant bit is 1)
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;
    }
};