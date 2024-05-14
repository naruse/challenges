/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.

*/

public class RPN {
    public int EvalRPN(string[] tokens) {             
        Stack<int> rpn = new();
        int val1;
        int val2;

        for(int i = 0; i < tokens.Length; i++) {
            switch(tokens[i]) {
                case "+":
                    val1 = rpn.Pop(); 
                    val2 = rpn.Pop();
                    rpn.Push(val1 + val2);
                    break;
                case "-":
                    val1 = rpn.Pop(); 
                    val2 = rpn.Pop();
                    rpn.Push(val2 - val1); // IMPORTANTE EL ORDEN
                    break;
                case "*":
                    val1 = rpn.Pop(); 
                    val2 = rpn.Pop();
                    rpn.Push(val1 * val2);
                    break;
                case "/":
                    val1 = rpn.Pop(); 
                    val2 = rpn.Pop();
                    rpn.Push(val2 / val1);//IMPORTANTE EL ORDEN
                    break;
                default: // its a number
                    int val = 0;
                    int.TryParse(tokens[i], out val);
                    rpn.Push(val);
                    break;
            }
        }
        return rpn.Pop();        
    }
}