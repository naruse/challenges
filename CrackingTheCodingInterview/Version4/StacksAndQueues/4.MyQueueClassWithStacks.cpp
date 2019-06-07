/*
  Implement a MyQueue class which implements a queue using two stacks.
*/

#include <iostream>
#include <stack>

using namespace::std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

    void Move(stack<int> &s1, stack<int> &s2) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
public:
    MyQueue(){}

    void Print() {
        Move(s1, s2);
        stack<int> tmp = s2;
        while(!tmp.empty()) {
            cout << "-> " << tmp.top() << " ";
            tmp.pop();
        }
        cout << endl;
    }

    int FrontPeek() {
        Move(s2,s1);
        if(!s1.empty())
            return s1.top();
        else {
            cout << "Nothing to peek, Q empty" << endl;
            return -1;
        }
    }
    int BackPeek() {
        Move(s1,s2);
        if(!s2.empty())
            return s2.top();
        else {
            cout << "Nothing to peek, Q empty" << endl;
            return -1;
        }
    }
    void EnQueue(int val) {
        Move(s1, s2);
        s2.push(val);
    }

    void DeQueue() {
        Move(s2, s1);
        if(s1.empty())
            cout << "" << endl;
        s1.pop();
    }
};

int main(int argc, char* argv[]) {
    MyQueue q;
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    q.EnQueue(4);
    q.EnQueue(5);
    q.EnQueue(6);
    q.EnQueue(7);
    q.EnQueue(8);
    q.EnQueue(9);

    q.Print();

    cout << "Front: " << q.FrontPeek() << " Back: " << q.BackPeek() << endl;

    cout << "Enqueue 0" << endl;
    q.EnQueue(0);
    q.Print();
    cout << "Dequeue" << endl;
    q.DeQueue();
    q.Print();
}
