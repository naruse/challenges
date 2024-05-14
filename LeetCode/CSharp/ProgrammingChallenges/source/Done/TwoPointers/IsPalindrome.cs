/*
https://leetcode.com/problems/valid-palindrome/description/

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

using System.Reflection.Metadata;
using System.Text;

public class IsStringAPalindrome {
    public bool IsPalindrome(string s) {
        StringBuilder cleanupStrBuilder = new();

        for(int i = 0; i < s.Length; i++) {
            if(char.IsLetterOrDigit(s[i])) {
                cleanupStrBuilder.Append(char.ToLower(s[i]));
            }
        }
        
        string cleanupStr = cleanupStrBuilder.ToString();

        for(int i = 0; i < cleanupStr.Length; i++) {
            if(cleanupStr[i] != cleanupStr[cleanupStr.Length-1-i])
            return false;
        }

        return true;
    }
}