/*
https://leetcode.com/problems/min-stack/description/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.
*/

public class MinStack {

    Stack<int> minStack;
    Stack<int> stack;

    public MinStack() {
        stack = new();
        minStack = new();
    }
    
    public void Push(int val) {
        stack.Push(val);
        if(minStack.Count != 0)
            minStack.Push(minStack.Peek() < val ? minStack.Peek() :  val);
        else
            minStack.Push(val);
    }
    
    public void Pop() {
        stack.Pop();
        minStack.Pop();
    }
    
    public int Top() {
        return stack.Peek();
    }
    
    public int GetMin() {
        return minStack.Peek();
    }
}