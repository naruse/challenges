/*
https://leetcode.com/problems/contains-duplicate/description/
Given an integer array nums, return true if any value appears at least twice in the array, and return false if
every element is distinct.

 Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

*/

class ContainsDuplicate {
    int[] nums;
    
    public ContainsDuplicate(int[] _nums) {
        nums = _nums;
    }

    public bool Check() {
        HashSet<int> seenNumbers = new HashSet<int>();
        for(int i = 0; i < nums.Length; i++) {
            if(!seenNumbers.Contains(nums[i]))
                seenNumbers.Add(nums[i]);
            else
                return true;
        }
        return false;
    }
}