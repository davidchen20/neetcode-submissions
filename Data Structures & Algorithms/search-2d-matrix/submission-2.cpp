class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int currentRow = 0;
        bool rowFound = false;
        for (; currentRow < matrix.size(); currentRow++) {
            vector<int>& row = matrix[currentRow];
            int left = row[0];
            int right = row[row.size() - 1];

            if (left == target || right == target) return true;

            if (left < target && target < right) {
                rowFound = true;
                break;
            }
        }

        if (!rowFound) return false;

        return binarySearch(matrix[currentRow], 0, matrix[currentRow].size(), target);
    }

    bool binarySearch(vector<int>& row, int left, int right, int target) {
        if (left >= right) return false;

        int middle = (left + right) / 2;

        if (row[middle] > target) return binarySearch(row, left, middle, target);
        else if (row[middle] < target) return binarySearch(row, middle + 1, right, target);
        else return true;
    }
};
