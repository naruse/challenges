/*
  You have two numbers represented by a linked list, where each node contains
  a single digit. The digits are stored in reverse order, such that the Ts
  digit is at the head of the list. Write a function that adds the two
  numbers and returns the sum as a linked list.

  EXAMPLE
  Input:(7-> 1 -> 6) + (5 -> 9 -> 2).Thatis,617 + 295.
  Output: 2 -> 1 -> 9.That is, 912.

  Approach:
  We divide this problem into 2 subproblems.
  1. List To Number:
   have a counter from 0 and go through the list and each time add the value
  of the node times 10^counter, return number at the end.

  2. Number to List:
  let X be the number; while X > 0, apply x%10 and add to the list, make x =
  x/ 10 and repeat.
*/

#include <iostream>
#include <cmath>

using namespace::std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }

    void AddToEnd(int d) {
        Node* end = new Node(d);
        Node* current = this;
        while(current->next != NULL)
            current = current->next;
        current->next = end;
    }
};

void PrintList(Node* head) {
    if(head == NULL) return;
    cout << head->data << " -> ";
    Node* nextN = head->next;
    while(nextN != NULL) {
        cout << nextN->data << " -> ";
        nextN = nextN->next;
    }
    cout << "END" << endl;
}

Node* NumberToList(int val) {
    int valueToProcess = val;
    Node* generatedListHead = new Node(valueToProcess%10);
    valueToProcess /= 10;

    while(valueToProcess > 0) {
        int toList = valueToProcess%10;
        generatedListHead->AddToEnd(toList);
        valueToProcess /= 10;
    }
    return generatedListHead;
}

int ListToNumber(Node* head) {
    if(head == NULL) { cerr << "List is empty." << endl; return -1;}
    int digit = 1;
    int generatedNumber = head->data;
    Node* nextNode = head->next;
    while(nextNode != NULL) {
        generatedNumber += (nextNode->data * pow(10, digit));
        digit++;
        nextNode = nextNode->next;
    }
    return generatedNumber;
}

int main(int argc, char* argv[]) {
    int value1 = 617;
    int value2 = 295;

    Node* l1 = NumberToList(value1);
    cout << "Converting " << value1 << " to list." << endl;
    PrintList(l1);

    Node* l2 = NumberToList(value2);
    cout << "Converting " << value2 << " to list." << endl;
    PrintList(l2);

    cout << "Adding " << value1 << " + " << value2 << " = " << (value1+value2) << endl;
    int result = ListToNumber(l1) + ListToNumber(l2);
    cout << " => RESULT: " << result << endl;
}
