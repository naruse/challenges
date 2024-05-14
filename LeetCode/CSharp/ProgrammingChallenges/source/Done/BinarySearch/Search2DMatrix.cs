/*
https://leetcode.com/problems/search-a-2d-matrix/

You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
 

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/

public class Search2DMatrix {
    public bool SearchMatrix(int[][] matrix, int target) {
        int rows = matrix.Length;
        int cols = matrix[0].Length;
        int start = 0;
        int end = rows*cols-1;
        int mid = start + (end-start)/2;
        while( start <= end) {
            int val = matrix[mid/cols][mid%cols];//divided the number of columns and then at the remaining with modulo (%)
            if(val == target) {
                return true;
            } else if(val < target) {
                start = mid + 1;
            } else if(val > target) {
                end = mid - 1;
            }

            mid = start + (end-start)/2;
        }

        return false;
    }
}