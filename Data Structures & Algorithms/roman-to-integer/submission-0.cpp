#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // 1. Create a map for the Roman numeral values
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, 
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.length(); 
        
        for (int i = 0; i < n; i++) {
            // 2. Use romanMap instead of the function name
            if (i < n - 1 && romanMap[s[i]] < romanMap[s[i+1]]) {
                total -= romanMap[s[i]];
            } else {
                total += romanMap[s[i]];
            }
        }
        
        // 3. Don't forget to return the result!
        return total;
    }
};