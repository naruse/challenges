/*
  How would you design a stack that in addiciton to push / pop, also has a
  min which returns the minimum element in the stack.

  All operations should be O(1).

  APPROACH:

  The idea here is to use 2 stacks, one for the normal numbers and the other
  that keeps track of the current min of the whole stack at any level.

 */

#include <iostream>
#include <stack>

using namespace::std;


class StackWithMinimum {
private:
    stack<int> s;
    stack<int> mins;
public:
    StackWithMinimum() {}
    void Push(int val) {
        if(mins.empty() || mins.top() >= val)
            mins.push(val);
        s.push(val);
    }
    void Pop() {
        if(s.empty()) {
            cerr << "Stack empty, cant pop." << endl;
            return;
        }
        cout << "Poping" << endl;
        if(mins.top() == s.top())
            mins.pop();
        s.pop();
    }
    pair<int, int> Peek() {
        if(s.empty()) {
            cerr << "Stack empty, cant peek." << endl;
            return pair<int, int>(-1, -1);
        }
        cout << "Peek: " << s.top() << " min: " << mins.top() << endl;;
        return pair<int, int>(s.top(), mins.top());
    }
};


int main(int argc, char* argv[]) {
    StackWithMinimum s;
    s.Push(9);
    s.Push(3);
    s.Push(4);
    s.Push(1);
    s.Push(8);
    s.Push(2);
    s.Push(9);
    s.Push(0);
    s.Push(2);
    s.Push(9);
    s.Peek();
    s.Pop();
    s.Peek();
    s.Pop();
    s.Peek();
    s.Pop();
    s.Peek();
    s.Pop();
    s.Peek();
    s.Pop();
    s.Peek();
    s.Pop();
    s.Peek();
    s.Pop();
    s.Peek();
    s.Pop();
    s.Peek();
    s.Pop();
    s.Peek();
    s.Pop();
    s.Peek();
}
