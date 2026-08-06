/*class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        // Pre-allocate memory for efficiency 
        result.reserve(word1.length() + word2.length());
        
        int i = 0, j = 0;
        int m = word1.length(), n = word2.length();
        
        while (i < m || j < n) {
            if (i < m) {
                result += word1[i++];
            }
            if (j < n) {
                result += word2[j++];
            }
        }
        
        return result;
    }
};
*/
#include <string>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int i = 0, j = 0;
        int l1 = word1.size();
        int l2 = word2.size();
        std::string word3 = ""; // Truly empty string

        // Step 1: Alternate while BOTH strings have characters
        while (i < l1 && j < l2) {
            word3 = word3 + word1[i];
            word3 = word3 + word2[j];
            
            i++; // Moved safely inside the loop!
            j++; // Moved safely inside the loop!
        }

        // Step 2: Append any leftovers from word1 (if it was longer)
        while (i < l1) {
            word3 = word3 + word1[i];
            i++;
        }

        // Step 3: Append any leftovers from word2 (if it was longer)
        while (j < l2) {
            word3 = word3 + word2[j];
            j++;
        }

        return word3;
    }
};