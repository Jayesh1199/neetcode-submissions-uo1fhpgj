#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the weights in ascending order
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            // If the lightest and heaviest person can fit in the same boat
            if (people[left] + people[right] <= limit) {
                left++; // The lightest person gets on the boat
            }
            // The heaviest person gets on the boat regardless 
            // (either with the lightest person, or alone if they are too heavy to share)
            right--; 
            
            // One boat is used
            boats++;
        }
        
        return boats;
    }
};