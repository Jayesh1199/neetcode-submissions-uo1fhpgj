class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (true) {
            // Traverse top row
            for (int i = left; i <= right; ++i) result.push_back(matrix[top][i]);
            if (++top > bottom) break;

            // Traverse right column
            for (int i = top; i <= bottom; ++i) result.push_back(matrix[i][right]);
            if (--right < left) break;

            // Traverse bottom row
            for (int i = right; i >= left; --i) result.push_back(matrix[bottom][i]);
            if (--bottom < top) break;

            // Traverse left column
            for (int i = bottom; i >= top; --i) result.push_back(matrix[i][left]);
            if (++left > right) break;
        }

        return result;
    }
};