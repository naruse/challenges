/*
https://leetcode.com/problems/valid-parentheses/
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input
string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

la clave es cada vez que vea una cerrada de parentesis mirar el peek del stack si coincide con uno que abre
*/

public class ValidParentheses {
    public bool CheckForValidity(string s) {
        if(s == "")
            return true;
        if(s.Length % 2 == 1)
            return false;

            Stack<char> stack = new();

        for(int i = 0; i < s.Length; i++) {
            if(s[i] == '('|| s[i] == '['|| s[i] == '{'){
                stack.Push(s[i]);
            }

            if(s[i] == ')' && stack.Count != 0 && stack.Peek() == '(') {
                stack.Pop();
            }
            if(s[i] == ']' && stack.Count != 0 && stack.Peek() == '[') {
                stack.Pop();
            }
            if(s[i] == '}' && stack.Count != 0 && stack.Peek() == '{') {
                stack.Pop();
            }
        }

        return stack.Count == 0;
    }
}