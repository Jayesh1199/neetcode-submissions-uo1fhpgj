class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Pointers for the end of the valid elements in nums1 and nums2
        int p1 = m - 1;
        int p2 = n - 1;
        // Pointer for the end of the entire nums1 array
        int p = m + n - 1;

        // While there are still elements to process in nums2
        while (p2 >= 0) {
            // If p1 is valid and the element in nums1 is strictly greater
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                // Otherwise, the element in nums2 is greater or equal
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
    }
};