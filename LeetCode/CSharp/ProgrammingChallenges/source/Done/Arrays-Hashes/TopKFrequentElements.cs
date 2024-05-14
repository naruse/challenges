/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

public class TopKFrequentElements {

    public TopKFrequentElements() {

    }

    public int[] Check(int[] nums, int k) {

        Dictionary<int, int> ocurrences = new Dictionary<int, int>();

        for(int i = 0; i < nums.Length; i++) {
            if(!ocurrences.ContainsKey(nums[i])){
                ocurrences.Add(nums[i], 1);
            } else {
                ocurrences[nums[i]]++;
            }
        }

        var orderedOcurrences = ocurrences.OrderByDescending(pair => pair.Value).ToDictionary(pair => pair.Key, pair => pair.Value);

        int[] valuesToReturn = new int[k];
        int counter = 0;
        foreach(var ocurrence in orderedOcurrences) {
            Console.WriteLine(ocurrence.Key + " " + ocurrence.Value);
            if(counter < k)
                valuesToReturn[counter] = ocurrence.Key;
            else
                break;
            
            counter++;
        }
        return valuesToReturn;
    }
}