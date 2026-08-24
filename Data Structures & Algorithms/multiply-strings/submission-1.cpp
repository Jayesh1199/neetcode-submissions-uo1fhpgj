#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.length();
        int n = num2.length();
        std::vector<int> pos(m + n, 0);

        // Multiply each digit from right to left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                
                // Position in the array
                int p1 = i + j;
                int p2 = i + j + 1;
                
                int sum = mul + pos[p2];

                pos[p2] = sum % 10;     // Store current digit
                pos[p1] += sum / 10;    // Add carry to the left position
            }
        }

        // Convert the vector result into a string, skipping leading zeros
        std::string res = "";
        for (int p : pos) {
            if (!(res.empty() && p == 0)) {
                res.push_back(p + '0');
            }
        }

        return res.empty() ? "0" : res;
    }
};