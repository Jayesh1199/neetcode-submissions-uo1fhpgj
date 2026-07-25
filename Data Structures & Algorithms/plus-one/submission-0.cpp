class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Start from the least significant digit (rightmost)
        for (int i = digits.size() - 1; i >= 0; --i) {
            // If the digit is less than 9, we can just increment it and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // If the digit is 9, it becomes 0, and we carry over the 1 to the next iteration
            digits[i] = 0;
        }
        
        // If we exit the loop, it means all digits were 9 (e.g., 999 -> 000)
        // We need to add a 1 at the most significant position (e.g., 1000)
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};