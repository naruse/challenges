/*
https://leetcode.com/problems/binary-search/description/

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.


Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

public class BinarySearch {
    public int Search(int[] nums, int target) {

        int left = 0;
        int right = nums.Length-1;
        int pivot = (right+left)/2;
        while(left <= right) {
            if(nums[pivot] == target) {
                Console.WriteLine(pivot);
                return pivot;
            } else if(nums[pivot] < target) {
                left = pivot + 1;
                pivot = (left + right) / 2;
            } else if(nums[pivot] > target) {
                right = pivot - 1;
                pivot = (left + right) / 2;
            }

            Console.WriteLine(left + " " + right);
        }
        Console.WriteLine("-1");
        return -1;
    }
}