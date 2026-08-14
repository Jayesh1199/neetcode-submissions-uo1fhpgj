class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to prevent overflow when n is INT_MIN (-2147483648)
        long long N = n; 
        
        // If the power is negative, invert x and make N positive
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        
        while (N > 0) {
            // If the current power is odd, multiply the result by x
            if (N % 2 == 1) {
                result *= x;
            }
            // Square the base and halve the power for the next iteration
            x *= x;
            N /= 2;
        }
        
        return result;
    }
};