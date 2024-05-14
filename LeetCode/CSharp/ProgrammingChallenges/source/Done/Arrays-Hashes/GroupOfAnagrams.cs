/*
https://leetcode.com/problems/group-anagrams/description/
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

*/

public class GroupOfAnagrams {
    public GroupOfAnagrams(string[] strs) 
    {

    }

    public IList<IList<string>> GroupAnagrams(string[] strs) {
        Dictionary<string, List<string>> anagramIndexes = new Dictionary<string, List<string>>();//dictionary of sorted anagrams with a list of the anagrams
        for(int i = 0; i < strs.Length; i++) {
            char[] arrStrI = strs[i].ToCharArray();
            Array.Sort(arrStrI);
            var arrStrIStr = new string(arrStrI);

            if(anagramIndexes.ContainsKey(arrStrIStr)) {
                anagramIndexes[arrStrIStr].Add(strs[i]);
            } else {
                anagramIndexes.Add(arrStrIStr, new List<string>());
                anagramIndexes[arrStrIStr].Add(strs[i]);
            }
        }

        List<List<string>> groupAnagrams = new List<List<string>>();

        foreach(var pair in anagramIndexes) {
            groupAnagrams.Add(pair.Value);
        }

        return groupAnagrams.ToList<IList<string>>();
    }
}