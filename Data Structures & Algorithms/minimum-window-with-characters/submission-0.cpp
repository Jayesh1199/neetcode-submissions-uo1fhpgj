#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // If s is shorter than t, it's impossible to find a valid window
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Use a vector to keep track of character frequencies in string t
        vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }

        // counter tracks how many characters of t we still need to match
        int counter = t.length();
        int begin = 0, end = 0, minLen = INT_MAX, head = 0;

        while (end < s.length()) {
            // If the current character is in t, decrement our required counter
            if (map[s[end]] > 0) {
                counter--;
            }
            // Decrease the count in the map and expand the window to the right
            map[s[end]]--;
            end++;

            // When counter reaches 0, the current window is valid
            while (counter == 0) {
                // Update minimum length and starting index (head) if we found a shorter window
                if (end - begin < minLen) {
                    minLen = end - begin;
                    head = begin;
                }

                // Try to shrink the window from the left
                map[s[begin]]++;
                // If the character slipping out of the window was part of t, we need to find it again
                if (map[s[begin]] > 0) {
                    counter++;
                }
                begin++;
            }
        }

        // If minLen was never updated, no valid window was found
        return minLen == INT_MAX ? "" : s.substr(head, minLen);
    }
};