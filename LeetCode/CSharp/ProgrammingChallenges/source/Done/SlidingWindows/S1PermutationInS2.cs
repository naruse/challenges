/*
https://leetcode.com/problems/permutation-in-string/description/

Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

*/

public class S1PermutationInS2 {
    public bool CheckInclusion(string s1, string s2) {

        int left = 0; 
        //int right = s1.Length;

        bool isPermutation = false;

        while(left < s2.Length-s1.Length+1) {//no entiendo porue +1 pero si :shrug:
            var currentSubstr = s2.Substring(left, s1.Length);
            Console.WriteLine("Checking " + s2 + " currentSubstr: " + currentSubstr + " Perm: " + s1);
            if(IsPermutation(currentSubstr, s1))
                return true;
            
            left++;
        }
        Console.WriteLine("Is permutation: " + isPermutation);
        return isPermutation;
    }

    bool IsPermutation(string s1, string s2) {
        string sortedS1 = SortString(s1);
        string sortedS2 = SortString(s2);

        return sortedS1 == sortedS2;
    }

    string SortString(string s){
        char[] sCharArr = s.ToCharArray();
        Array.Sort(sCharArr);
        return String.Join("",sCharArr);
    }
}
