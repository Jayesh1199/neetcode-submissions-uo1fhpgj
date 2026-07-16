class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long remaining = n - 1;
        long long bit_position = 1;
        
        while (remaining > 0) {
            // If the current bit position in x is 0, it's available to be flipped
            if ((x & bit_position) == 0) { 
                // If the current least significant bit of 'remaining' is 1, set the bit in result
                if (remaining & 1) {       
                    result |= bit_position;
                }
                // Move to the next bit of the remaining count
                remaining >>= 1;           
            }
            // Shift to check the next bit position
            bit_position <<= 1;            
        }
        
        return result;
    }
};
