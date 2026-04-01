class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Step 1: Safety Guard (The Base Case)
        if (strs.empty()) return "";

        string result = "";

        // Step 2: The Outer Loop (Character Index)
        // We move through the first word character by character
        for (int i = 0; i < strs[0].size(); i++) {
            char target = strs[0][i]; // This is our "Gold Standard"

            // Step 3: The Inner Loop (Word Index)
            // We check this character against every other word in the list
            for (int j = 1; j < strs.size(); j++) {
                
                // CRITICAL SAFETY CHECK:
                // 1. i == strs[j].size() -> This word is shorter than our index
                // 2. strs[j][i] != target -> The character doesn't match
                if (i == strs[j].size() || strs[j][i] != target) {
                    return result; // Mismatch found! Return the prefix we built so far.
                }
            }

            // Step 4: Growth
            // If the inner loop finishes without returning, it's a match!
            result += target;
        }

        return result;
    }
};