/*
https://leetcode.com/problems/subsets-ii/description/

Given an integer array nums that may contain duplicates, return all possible
subsets
(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

class SubsetWithRepeatedNums {
    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        List<List<int>> indexResult = new List<List<int>>();
        HashSet<List<int>> addedSubsets = new();
        List<int> subset = new();
        void DFS(int i) {
            if(i >= nums.Length) {
                if(!addedSubsets.Contains(subset)) {
                    indexResult.Add(subset);
                    addedSubsets.Add(subset);
                }
                return;
            }

            //with the value
            subset.Add(nums[i]);
            DFS(i+1);
            //without the value
            subset.RemoveAt(subset.Count-1);
            DFS(i+1);
        }

        DFS(0);

        return indexResult.ToList<IList<int>>();
    }
}