
/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Longest Substring Without Repeating Characters

Given a string s, find the length of the longest
substring
without repeating characters.

 

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
public class LongestSubstringWithoutRepeatingChars {
    public int LengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;

        int longestSubStr = 0;

        HashSet<char> seenChars = new();

        while(right < s.Length) {
            right = left;
            seenChars.Clear();
            int currSubStrLength = 0;

            while(right < s.Length && !seenChars.Contains(s[right])) {
                seenChars.Add(s[right]);
                currSubStrLength++;
                right++;
            }
            longestSubStr = Math.Max(longestSubStr, currSubStrLength);
            left++;
        }

        return longestSubStr;
    }
}