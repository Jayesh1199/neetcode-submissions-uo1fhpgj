#include <numeric>
#include <string>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        // If concatenating the strings in different orders produces different results, 
        // they do not share a common divisor.
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // If they do share a common divisor, the length of the greatest common divisor 
        // string is the GCD of their lengths.
        int gcdLength = std::gcd(str1.length(), str2.length());
        
        // Return the prefix of str1 up to the GCD length
        return str1.substr(0, gcdLength);
    }
};