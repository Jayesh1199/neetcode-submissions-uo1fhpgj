#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        
        // Binary search to find the left bound of the k-sized window
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Compare the distance of x from the boundaries of the window.
            // If x is closer to arr[mid + k] than to arr[mid], the window 
            // should shift to the right.
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // Return the k elements starting from the found left bound
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};