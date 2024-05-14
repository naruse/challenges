/*
https://leetcode.com/problems/product-of-array-except-self/description/

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Explicacion GAS: https://youtu.be/5bS636lE_R0

*/
public class ProductOrArrayExceptSelf {
    public int[] ProductExceptSelf(int[] nums) {
        int[] left = new int[nums.Length];
        left[0] = 1;         
        //left
        for(int i = 1; i < nums.Length; i++) {
            left[i] = left[i-1]*nums[i-1];
        }

        Print(left);
        //right
        int[] right = new int[nums.Length];
        right[right.Length-1] = 1;
        for(int i = nums.Length-2; i >= 0 ; i--) {
            right[i] = right[i+1]*nums[i+1];
        }

        int[] answer = new int[nums.Length];
        for(int i = 0; i < nums.Length; i++) {
            answer[i] = left[i]*right[i];
        }
        return answer;
    }

    void Print(int[] arr) {
        for(int i = 0; i < arr.Length; i++) {
            Console.Write(arr[i] + " ");
        }
        Console.WriteLine();
    }
}