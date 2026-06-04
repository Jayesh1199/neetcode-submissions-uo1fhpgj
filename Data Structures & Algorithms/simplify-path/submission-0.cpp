#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string token;
        
        // Split the path by the '/' delimiter
        while (getline(ss, token, '/')) {
            // Ignore empty tokens (caused by multiple slashes like "//") and "."
            if (token == "" || token == ".") {
                continue;
            } 
            // If we see "..", pop the top directory off the stack if it isn't empty
            else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } 
            // Otherwise, it's a valid directory or file name, so push it
            else {
                stack.push_back(token);
            }
        }
        
        // Reconstruct the simplified absolute path
        std::string result = "";
        for (const std::string& dir : stack) {
            result += "/" + dir;
        }
        
        // If the stack was empty (e.g., path was "/../"), return root "/"
        return result.empty() ? "/" : result;
    }
};