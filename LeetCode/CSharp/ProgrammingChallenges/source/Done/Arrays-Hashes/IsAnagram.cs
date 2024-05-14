/*
https://leetcode.com/problems/valid-anagram/description/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

*/

using System;

public class IsAnagram {
    string s;
    string t;
    public IsAnagram(string _s, string _t) {
        s = _s;
        t = _t;
    }

    // mejor y mas rapido, cojer las dos str y convertirlas a charArr, hacer sort y comparar si son iguales y listo.
    public bool Check() {
        if(s.Length != t.Length) //base case different sizes
            return false;

        for(int i = 0; i < s.Length; i++) {
            var index = t.IndexOf(s[i]);
            if(index == -1)//the char doesnt exist
                return false;
            
            t = t.Remove(index,1);
        }

        if(t.Length == 0)
            return true;
        else
            return false;
    }
}