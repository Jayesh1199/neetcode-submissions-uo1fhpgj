#include <string>
#include <algorithm>

class Solution {
private:
    // Helper 1: Adds two numeric strings together (column addition)
    std::string addStrings(std::string num1, std::string num2) {
        std::string res = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }
            carry = sum / 10;
            res.push_back((sum % 10) + '0');
        }

        std::reverse(res.begin(), res.end());
        return res;
    }

    // Helper 2: Multiplies num1 by a single digit and appends trailing zeros
    std::string multiplyByDigit(std::string num1, char digitChar, int zeroes) {
        if (digitChar == '0' || num1 == "0") return "0";
        
        int digit = digitChar - '0';
        std::string res = "";
        int carry = 0;

        for (int i = num1.length() - 1; i >= 0; i--) {
            int prod = (num1[i] - '0') * digit + carry;
            carry = prod / 10;
            res.push_back((prod % 10) + '0');
        }

        if (carry > 0) {
            res.push_back(carry + '0');
        }

        std::reverse(res.begin(), res.end());

        // Append trailing zeros based on place value
        for (int i = 0; i < zeroes; i++) {
            res.push_back('0');
        }

        return res;
    }

public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        std::string res = "0";
        int n = num2.length();

        for (int i = n - 1; i >= 0; i--) {
            int zeroes = n - 1 - i;
            std::string intermediate = multiplyByDigit(num1, num2[i], zeroes);
            res = addStrings(res, intermediate);
        }

        return res;
    }
};