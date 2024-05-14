/*
https://leetcode.com/problems/3sum/description/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

*/

using System.Diagnostics;

public class ThreeSum {
/*
Como lo hice:
Simplemente hago un TwoSum con x+ y + z = 0 ==> -x = y + z 
que me retorne todas las posibles sumas.
y apenas tenga el two sum, guardo en un diccionario que tiene string,int[] 
donde string es el key de los valores concatenados (previamente sorted)
*/
    public IList<IList<int>> Check(int[] nums) {
        // x + y + z = 0 ==> -x = y + z
        List<List<int>> result = new List<List<int>>();
        Dictionary<string, int[]> validValues = new();
        HashSet<int> seenTargets = new();
        
        for(int i = 0; i < nums.Length; i++) {

            var target = -nums[i];
            /***** this is optimization ****/
            if(seenTargets.Contains(target))
                continue;
            else 
                seenTargets.Add(target);
            /***************/
            
            var listOfTwoSum = TwoSum(nums, target, i);
            
            for(int j = 0; j < listOfTwoSum.Count; j++) {
                var idxTrio = new int[] { listOfTwoSum[j][0], listOfTwoSum[j][1], i };//trio of indices
                var valuesTrio = new int[] { nums[idxTrio[0]], nums[idxTrio[1]], nums[idxTrio[2]] };
                var key = GenerateUniqueTrioKey(valuesTrio);
                if(!validValues.ContainsKey(key)) {
                    validValues.Add(key, valuesTrio);
                    result.Add(valuesTrio.ToList());
                }

                /*Console.WriteLine("Encountered: " + 
                "["+idxTrio[0]+"]:" + valuesTrio[0] + " + " + 
                "["+idxTrio[1]+"]:" + valuesTrio[1] + " + " + 
                "["+idxTrio[2]+"]:" + valuesTrio[2] + " =? 0");*/
                
            }
        }
        PrintList(result);

        return result.ToList<IList<int>>();
    }

    void PrintList(List<List<int>> l) {
        Console.Write("[");
        for(int i = 0; i < l.Count; i++) {
            Console.Write("[");
            for(int j = 0; j < l[i].Count; j++) {
                Console.Write(l[i][j] + (j == l.Count-1 ? "" : " "));
            }
            Console.Write("],");
        }
        Console.Write("]\n");
    }

    string GenerateUniqueTrioKey(int[] trio) {
        Array.Sort(trio);
        return trio[0].ToString() + trio[1].ToString() + trio[2].ToString();
    }
    string GenerateUniqueDuoKey(int[] duo) {
        Array.Sort(duo);
        return duo[0].ToString() + duo[1].ToString();
    }

    public List<int[]> TwoSum(int[] nums, int target, int ignoreIndex) {

        Dictionary<int,int> seenValues = new();//value, index
        List<int[]> results = new();
        HashSet<string> seenResults = new();
        //target = x + y ==> x = target - y
        for(int i = 0; i < nums.Length; i++) {  
            if(ignoreIndex == i)
                continue;          

            int neededValue = target - nums[i];
            if(seenValues.ContainsKey(neededValue)) {
                //Console.WriteLine("Found Two Sum: " + 
                //"[" + i + "]:" + nums[i] + " + [" + seenValues[neededValue] + "]:" + neededValue + " = target: " + target);
                var foundDuo = new int[] { i, seenValues[neededValue] };

                var uniqueDuoKey = GenerateUniqueDuoKey(foundDuo);
                if(!seenResults.Contains(uniqueDuoKey)){
                    seenResults.Add(uniqueDuoKey);
                    results.Add(foundDuo);
                }
                
            } else {
                if(!seenValues.ContainsKey(nums[i]))
                    seenValues.Add(nums[i], i);
            }        
        }
        return results;
    }
}