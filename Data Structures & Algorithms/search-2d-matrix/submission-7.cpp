class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return helper(matrix, 0, matrix.size()*matrix[0].size()-1, target);
    }

    bool helper(vector<vector<int>>& matrix, int left, int right, int target) {
        if (left > right) return false;

        int mid = left + (right - left) / 2;

        int row = mid / matrix[0].size();
        int col = mid % matrix[0].size();

        if (matrix[row][col] < target) return helper(matrix, mid + 1, right, target);
        else if (matrix[row][col] > target) return helper(matrix, left, mid - 1, target);
        else return true;
    }
};
