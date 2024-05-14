/*
https://leetcode.com/problems/two-sum/description/
Given an array of integers nums and an integer target, return indices of the two numbers such 
that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same 
element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/
using System;
using System.Globalization;

public class TwoSum {

    Dictionary<int, int> seenValues;

    int[] numbers;
    int target;
    public TwoSum(int[] _nums, int _targt) {

        numbers = _nums;
        target = _targt; 
        seenValues = new Dictionary<int, int>();// number, index
    }

    public int[] Calculate () {
        seenValues.Add(numbers[0], 0);

        // target = nums[a] + nums[b] ==> Return a and b and finish;
        // nums[a] = target - nums[b]

        for(int i = 1; i < numbers.Length; i++) {
            int hopeToFindNum = target - numbers[i];
            if(seenValues.ContainsKey(hopeToFindNum)) {
                return new int[] {i, seenValues[hopeToFindNum]};
            } else {//number not in dictionary, lets save it with the index if it doesnt exist
                if(!seenValues.ContainsKey(numbers[i])) 
                    seenValues.Add(numbers[i], i);
            }
            
        }
        return new int[] {-1,-1};
    }


}