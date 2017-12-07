/*
  This is a follow up of the last problem (5.ListAdditions.cpp) where the
  lists are stored in normal order for the numbers.
  You have two numbers represented by a linked list, where each node contains
  a single digit. The digits are stored in normal order. Write a function
  that adds the two numbers and returns the sum as a linked list.

  EXAMPLE
  Input:(6 -> 1 -> 7) + (2 -> 9 -> 5).Thatis,617 + 295.
  Output: 9 -> 1 -> 2.That is, 912.

  Approach:
  We divide this problem into 2 subproblems.
  1. List To Number:
  Go through the list and if next != NULL multiply by 10 and add next
  2. Number to List:
  Same approach as the number to list from 5.ListAdditions.cpp, but the list
  starts by the end and we create nodes and set those nodes->next to point to
  the beginning of the list
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
    Node* beginning = new Node(val%10);
    int valueProcessed = val/10;

    while(valueProcessed > 0) {
        Node* nodeToAdd = new Node(valueProcessed%10);
        nodeToAdd->next = beginning;
        beginning = nodeToAdd;
        valueProcessed /= 10;
    }
    return beginning;
}

int ListToNumber(Node* head) {
    if(head == NULL) { cerr << "List is empty." << endl; return -1;}
    Node* nextNode = head->next;
    int generatedValue = head->data;
    while(nextNode != NULL) {
        generatedValue = (generatedValue*10) + nextNode->data;
        nextNode = nextNode->next;
    }
    return generatedValue;
}

int main(int argc, char* argv[]) {
    int value1 = 100;
    int value2 = 1000;

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
