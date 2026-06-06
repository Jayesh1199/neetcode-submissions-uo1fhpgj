#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Array to store the last seen index of each ASCII character.
        // Initialized to -1 to indicate the character hasn't been seen.
        std::vector<int> charIndex(128, -1); 
        
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // If we've seen this character before AND its last seen index 
            // is within our current window, move the left pointer.
            if (charIndex[currentChar] >= left) {
                left = charIndex[currentChar] + 1;
            }
            
            // Update the last seen index of the current character
            charIndex[currentChar] = right;
            
            // Calculate the length of the current valid window and update max
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};