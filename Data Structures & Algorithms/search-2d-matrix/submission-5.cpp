class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search to find the row it is in
        // binary search within that row to find where it is

        // start from first row and check if its last number is greater than or equal to target
            // if equal, return true
            // if greater than, binary search that row

        int m = matrix.size();
        int n = matrix[0].size();

        // binary search to find row
        int rowIdx = -1;
        int left = 0;
        int right = m;

        while (right > left) {
            int mid = left + (right - left) / 2;

            if (target > matrix[mid][n - 1]) left = mid + 1;
            else if (target < matrix[mid][0]) right = mid;
            else {
                rowIdx = mid;
                break;
            }
        }

        if (rowIdx == -1) return false;
        

        left = 0; 
        right = n;

        while (right > left) {
            int mid = left + (right - left) / 2;

            if (matrix[rowIdx][mid] < target) left = mid + 1;
            else if (matrix[rowIdx][mid] > target) right = mid;
            else return true;
        }

        return false;
    }
};
