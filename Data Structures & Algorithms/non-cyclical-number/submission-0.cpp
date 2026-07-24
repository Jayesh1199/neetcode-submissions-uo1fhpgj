#include <unordered_set>

class Solution {
private:
    // Helper function to calculate the sum of the squares of digits
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += (digit * digit);
            n = n / 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;
        
        // Loop until we find 1, or we encounter a number we've already seen
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);      // Mark current number as seen
            n = getSum(n);       // Get the next number in the sequence
        }
        
        // If the loop terminated because n == 1, it's a non-cyclical number
        return n == 1;
    }
};