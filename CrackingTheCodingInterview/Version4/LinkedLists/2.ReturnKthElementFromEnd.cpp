/*
  Implement an algorithm to find the kth to last element of a singly linked
  list.

  Approach:

  2 different approaches implemented here; 1rst one is save the list to a
  vector and increment its values until it ends, then return the vector at
  position vector.size()-1-kth

  Second approach is more optimal; we create 2 pointers (current and a runner
  pointer); we displace the runner pointer k spaces and carry on displacing
  the pointer until we reach the end; when we get there we return the current
  pointer node data.
 */

#include <iostream>
#include <vector>

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
    if(head == NULL)
        return;
    Node* current = head;
    cout << current->data << " -> ";
    while(current->next != NULL) {
        cout << current->next->data << " -> ";
        current = current->next;
    }
    cout << "END" << endl;
}

int GetKthElementFromEnd(Node* head, int index) {
    if(head == NULL)
        return -1;
    vector<int> values;
    Node* nextN = head->next;
    values.push_back(head->data);
    while(nextN != NULL) {
        values.push_back(nextN->data);
        nextN = nextN->next;
    }
    if(index > values.size() || index < 0)
        return -1;
    return values[values.size()-1-index];
}

int GetKthElementFromEndUsingRunnerPointer(Node* head, int index) {
    if(head == NULL)
        return -1;
    Node* current = head;
    Node* runner = head;
    //lets move the runner pointer index values forward, so when it reaches
    //the end, we return the data on current.
    for(int i = 0; i < index; i++) {
        if(runner == NULL) {
            cout << "Index out of bounds." << endl;
            return -1;
        }
        runner = runner->next;
    }

    while(runner != NULL) {
        runner = runner->next;
        if(runner != NULL)
            current = current->next;
    }
    return current->data;
}


int main(int argc, char* argv[]) {
    Node* head = new Node(1);
    head->AddToEnd(3);
    head->AddToEnd(9);
    head->AddToEnd(8);
    head->AddToEnd(7);
    head->AddToEnd(6);
    head->AddToEnd(2);
    PrintList(head);
    int index = 6;
    cout << index << " th element from end is: " << GetKthElementFromEnd(head, index) << endl;
    cout << index << " th element from end is: " << GetKthElementFromEndUsingRunnerPointer(head, index) << endl;
}


