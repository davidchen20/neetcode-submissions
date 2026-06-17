class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch(matrix, 0, matrix.size() * matrix[0].size(), target);
    }

    bool binarySearch(vector<vector<int>>& matrix, int left, int right, int target) {
        if (left >= right) return false;

        int middle = (left + right) / 2;

        int elementsPerRow = matrix[0].size();
        int rowIndex = middle / elementsPerRow;
        int columnIndex = middle % elementsPerRow;

        if (matrix[rowIndex][columnIndex] < target) return binarySearch(matrix, middle + 1, right, target);
        else if (matrix[rowIndex][columnIndex] > target) return binarySearch(matrix, left, middle, target);
        else return true;
    }
};
