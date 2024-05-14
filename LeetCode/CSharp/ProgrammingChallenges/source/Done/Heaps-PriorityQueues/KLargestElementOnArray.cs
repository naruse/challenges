/*
https://leetcode.com/problems/kth-largest-element-in-an-array/description/

215. Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

*/
// THIS IS A MAX HEAP
public class KLargestElementOnArray {
    public int FindKthLargest(int[] nums, int k) {
        var items = nums.Select(i => (i, i));
        PriorityQueue<int, int> q = new PriorityQueue<int, int>(items, Comparer<int>.Create((a,b) => b -a));

        for(int i = 0; i < k-1; i++) {
            q.Dequeue();
        }
        return q.Dequeue();
    }
}