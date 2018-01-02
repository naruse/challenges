/*
  Given a circular linked list, implement an algorithm which returns the node
  at the beginning of the loop.

DEFINITION

Circular linked list: A (corrupt) linked list in which a node's next pointer
points to an earlier node, so as to make a loop in the linked list.

EXAMPLE
Input:5->7->6->2->5-> C[same 5 as earlier] Output:5


APPROACH:
We start by going through the list and saving the nodes in a hash by the node
id (in this case will be the data value), if a node already exists means
there is a loop!
*/

#include <iostream>
#include <unordered_set>

using namespace::std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
    void AddToEnd(int d) {
        Node* end = new Node(d);
        Node* current = this;
        while(current->next != nullptr)
            current = current->next;
        current->next = end;
    }
};

void PrintList(const Node* head) {
    if(head == nullptr) return;
    cout << head->data << " -> ";
    Node* nextN = head->next;
    while(nextN != nullptr) {
        cout << nextN->data << " -> ";
        nextN = nextN->next;
    }
    cout << "END" << endl;
}
//Node const* --> Pointer to a constant node
//Node *const --> Constaint pointer to a node
pair<bool,Node const*> IsListCorrupted(Node const* head) { // Node const* foo
                                                           // IS: a POINTER
                                                           // to a CONSTANT
                                                           // NODE, Meaning I
                                                           // CANNOT CHANGE
                                                           // THE NODE but
                                                           // the pointer can
                                                           // be changed
    if(head == nullptr) return pair<bool, Node const*>(false,nullptr);//empty list is good list
    unordered_set<int> checkedValues;
    Node const* current = head;//pointer to a constant node
    checkedValues.insert(current->data);
    while(current->next != nullptr) {
        if(checkedValues.find(current->next->data) == checkedValues.end())//value doesnt exists,letsAddItToHash
            checkedValues.insert(current->next->data);
        else {//found loop!
            Node* corruptNode = current->next;//cant return next as the next doesnt point
                                        //to the node but the value is
                                        //repeated!

            cout << current->next->data << endl;
            return pair<bool, Node const*>(true, corruptNode);
        }
        current = current->next;
    }
    return pair<bool, Node const *>(false,nullptr);
}

int main(int argc, char* argv[]) {
    Node* const head = new Node(5);//A Constant pointer to a node
    head->AddToEnd(7);
    head->AddToEnd(3);
    head->AddToEnd(4);
    head->AddToEnd(6);
    head->AddToEnd(2);
    head->AddToEnd(4);


    cout << "Checking list for loops: " << endl;
    PrintList(head);


    pair<bool, Node const*/*pointer to a constant Node*/> corruptedListResult(false, nullptr);
    corruptedListResult = IsListCorrupted(head);
    if(corruptedListResult.first) {
        cout << "Found corruption on list, node: " << corruptedListResult.second->data << endl;
    } else {
        cout << "List doesnt have loops" << endl;
    }
}
