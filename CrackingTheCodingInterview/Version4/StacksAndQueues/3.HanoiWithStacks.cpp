/*
  In the classic problem of the Towers of Hanoi, you have 3 towers and Ndisks
  of different sizeswhichcanslideontoanytower.Thepuzzlestartswithdiskssorted
  in ascending order of size from top to bottom (i.e., each disk sits on top
  of an even larger one). You have the following constraints:

(1) Only one disk can be moved at a time.
(2) A disk is slid off the top of one tower onto the next tower.
(3) A disk can only be placed on top of a larger disk.

Write a program to move the disksfrom the first tower to the last using
stacks.

Approach:
took from:
https://python-course.eu/towers_of_hanoi.php
 */

#include <iostream>
#include <stack>

using namespace::std;

stack<int> source;
stack<int> aux;
stack<int> target;

void PrintStack(stack<int> s,string name) {
    stack<int> tmp;

    while(!s.empty()) {
        tmp.push(s.top());
        s.pop();
    }
    cout << "Printing stack " << name << endl;
    while(!tmp.empty()) {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << endl;
}

void Hanoi(int n, stack<int> &source, stack<int> &aux, stack<int> &target) {
    if(n > 0) {
        Hanoi(n-1, source, target, aux);
        if(!source.empty()) {
            target.push(source.top());
            source.pop();
        }
        Hanoi(n-1, aux, source, target);
    }
}


int main(int argc, char* argv[]) {
    source.push(10);
    source.push(9);
    source.push(8);
    source.push(7);
    source.push(6);
    source.push(5);
    source.push(4);
    source.push(3);
    source.push(2);
    source.push(1);
    PrintStack(source, "SOURCE");
    PrintStack(aux, "AUX");
    PrintStack(target, "TARGET");

    Hanoi(10, source, aux, target);

    PrintStack(source, "SOURCE");
    PrintStack(aux, "AUX");
    PrintStack(target, "TARGET");

}
