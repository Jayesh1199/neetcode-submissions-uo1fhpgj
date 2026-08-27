#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class CountSquares {
private:
    // Maps x-coordinate -> y-coordinate -> frequency
    unordered_map<int, unordered_map<int, int>> pointCounts;
    vector<pair<int, int>> pointsList;

public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        
        pointCounts[x][y]++;
        pointsList.push_back({x, y});
    }
    
    int count(vector<int> point) {
        int qx = point[0];
        int qy = point[1];
        int res = 0;
        
        for (const auto& p : pointsList) {
            int x = p.first;
            int y = p.second;
            
            // Check if the current point forms a diagonal with the query point
            // It must form a square (dx == dy) and cannot be the same point (x != qx)
            if (abs(qx - x) == abs(qy - y) && qx != x) {
                // The remaining two corners must exist to form a square
                // Multiply their frequencies to find all possible valid combinations
                res += pointCounts[x][qy] * pointCounts[qx][y];
            }
        }
        
        return res;
    }
};