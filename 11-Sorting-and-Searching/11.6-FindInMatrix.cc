//Given an M*N matrix in which each row and each column is sorted in ascending order, write a method to find an element.
//剑指offer上有原题
//跟leetcode上一题也很接近 https://oj.leetcode.com/problems/search-a-2d-matrix/


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty())
            return false;
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = col-1;
        while(r < row && c>=0)
        {
            if(matrix[r][c] > target)
                --c;
            else if(matrix[r][c] < target)
                ++r;
            else
                return true;
        }
        return false;
    }
};


