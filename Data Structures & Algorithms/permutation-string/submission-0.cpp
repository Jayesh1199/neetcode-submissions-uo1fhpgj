#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int m = s1.length();
        int n = s2.length();
        
        if (m > n) return false;

        // Count frequencies for s1
        std::vector<int> s1Count(26, 0);
        for (char c : s1) {
            s1Count[c - 'a']++;
        }

        // Check every possible substring of length 'm' in s2
        for (int i = 0; i <= n - m; i++) {
            std::vector<int> currentWindowCount(26, 0);
            
            // Build the frequency map for the current substring from scratch
            for (int j = 0; j < m; j++) {
                currentWindowCount[s2[i + j] - 'a']++;
            }

            // Compare the frequency maps
            bool isMatch = true;
            for (int k = 0; k < 26; k++) {
                if (s1Count[k] != currentWindowCount[k]) {
                    isMatch = false;
                    break;
                }
            }
            
            if (isMatch) return true;
        }

        return false;
    }
};