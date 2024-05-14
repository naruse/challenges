/*
https://leetcode.com/problems/permutations/description/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in
any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
*/

class PermutationsProblem { 
    public IList<IList<int>> Permute(int[] nums) {
        List<List<int>> result = new List<List<int>>();

        if(nums.Length == 1) {
            var baseCase = new List<List<int>>();
            baseCase.Add(nums.ToList());
            return baseCase.ToList<IList<int>>();
        }

        var numList = new List<int>(nums);
        for(int i = 0; i < numList.Count; i++) {
            var n = numList[0];//quitamos en la posicion 0
            numList.RemoveAt(0);

            var permutations = Permute(numList.ToArray());

            for(int j = 0; j < permutations.Count; j++) {
                permutations[j].Add(n);
                result.Add(new List<int>(permutations[j]));
            }

            numList.Add(n); // volvemos y agregamos lo que quitamos al final
        }

        return result.ToList<IList<int>>();
    }
}