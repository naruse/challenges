/*
Write a program to sort a stack in ascending order (with biggest items on
top). You may use at most one additional stack to hold items, but you may not
copy the elements into any other data structure (suchasan array).The stack
supports the following operations: push, pop, peek, and isEmpty.

 */
#include <iostream>
#include <stack>

using namespace::std;

class OrderedStack {
private:
    stack<int> st;
    stack<int> aux;

public:
    OrderedStack() {}
    void Print() {
        stack<int> s = st;
        stack<int> tmp;
        cout << "Printing" << endl;
        while(!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }
        cout << "|";
        while(!tmp.empty()) {
            cout << tmp.top() << " -> ";
            tmp.pop();
        }
        cout << endl;
    }

    void OrderedPush(int val) {
        if(st.empty() || st.top() <= val)
            st.push(val);
        else {
            while(!st.empty()) {
                if(st.top() > val) {
                    aux.push(st.top());
                    st.pop();
                } else
                    break;
            }
            st.push(val);
            while(!aux.empty()) {
                st.push(aux.top());
                aux.pop();
            }
        }

    }
};

int main(int argc, char* argv[]) {
    OrderedStack s;
    s.OrderedPush(7);
    s.Print();
    s.OrderedPush(6);
    s.Print();
    s.OrderedPush(2);
    s.Print();
    s.OrderedPush(9);
    s.Print();
    s.OrderedPush(1);
    s.Print();
    s.OrderedPush(4);
    s.Print();
    s.OrderedPush(0);
    s.Print();
    s.OrderedPush(3);
    s.Print();
    s.OrderedPush(10);
    s.Print();
}
