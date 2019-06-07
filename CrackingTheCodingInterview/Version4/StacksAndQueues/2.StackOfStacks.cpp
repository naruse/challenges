/*
  Imagine a (literal) stack of plates. If the stack gets too high, it might
  topple. Therefore, in real life, we would likely start a new stack when the
  previous stack exceeds somethreshold. Implement a data structureSetOf
  Stacks that mimics this. SetOf Stacks should be composed of several stacks
  and should create a newstackoncethe previous
  oneexceedscapacity. SetOfStacks.push() and SetOfStacks.pop()
  shouldbehaveidenticallytoasinglestack(thatis,popO should return the same
  values as it would if there were just a single stack)

  APPROACH:
  On this case, I use a stack of stacks of integers with an upper limit; when
  thelimit is reached, we create a new stack and start adding values; for
  popping, we check if the stack is empty and if its not we pop; if it is we
  pop from the stack of stacks and check on the last stack and pop from there.

  **** **** **** **** **** **** ****
  FOLLOW UP:
  sImplement afunction popAt(int index) which performsapopoperation on a
  specific sub-stack.

  APPROACH:
  we check the size of the stack and compare if its bigger than index first;
  if its not we put the contents of the stack into a temp stack index times,
  pop and then move back the temp stack to the original stack.

  A faster approach would be using a vector of stacks, but I implemented it
  with stacks.
*/

#include <iostream>
#include <stack>

using namespace::std;

class StackOfStacks {
private:
    int stackLimit;
public:
    stack<stack<int> > ss;
    StackOfStacks(int limit) {
        stackLimit = limit;
    }
    void Push(int val) {
        if(ss.empty() || ss.top().size() >= stackLimit) {
            stack<int> newStack;
            ss.push(newStack);
        }
        ss.top().push(val);
    }

    void Pop() {
        if(ss.empty()) {
            cerr << "cant pop, stack empty" << endl;
            return;
        }
        ss.top().pop();
        if(ss.top().empty())
            ss.pop();

    }

    int Peek() {
        if(ss.empty()) {
            cerr << "Empty stack, nothing to peek" << endl;
            return -1;
        }
        if(ss.top().empty())
            ss.pop();
        if(ss.empty()) {
            cerr << "popped stack as it was empty, this new stack is also empty stack, nothing to peek" << endl;
            return -1;
        }
        return ss.top().top();
    }

    void PopAt(int index) {
        if(index >= ss.size()) {
            cerr << "invalid index" << endl;
            return;
        }
        stack<stack<int> > tmp;
        for(int i = 0; i < index; i++) {
            tmp.push(ss.top());
            ss.pop();
        }
        Pop();
        for(int i = 0; i < index; i++) {
            ss.push(tmp.top());
            tmp.pop();
        }
    }
};

void PrintStackOfStacks(StackOfStacks sos, int limit) {//copy argument
    StackOfStacks tmp(2);
    while(!sos.ss.empty()) {//move contents to tmp to reverse them
        stack<int> s = sos.ss.top();
        stack<int> tmpS;
        while(!s.empty()) {
            tmpS.push(s.top());
            s.pop();
        }
        tmp.ss.push(tmpS);
        sos.ss.pop();
    }
    //print contents
    cout << "Printing Stack Of Stacks" << endl;
    while(!tmp.ss.empty()) {
        cout << "*--->";
        stack<int> s = tmp.ss.top();
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        tmp.ss.pop();
    }
}

int main(int argc, char* argv[]) {
    int stackLimit = 2;
    StackOfStacks ss(stackLimit);
    ss.Push(9);
    ss.Push(6);
    ss.Push(2);
    ss.Push(4);
    ss.Push(4);
    ss.Push(6);
    ss.Push(7);

    PrintStackOfStacks(ss, stackLimit);
    cout << "Press enter to pop" << endl;
    while(true) {
        cin.get();
        ss.PopAt(3);
        PrintStackOfStacks(ss, stackLimit);
    }
}
