/*
  Implementation of a simple singly linked list in C++

 */

#include <iostream>

using namespace::std;

class Node {
private:
public:
    Node* next;
    int data;

    Node(int d) {
        data = d;
        next = NULL;
    }

    void Add(int d) {
        Node* current = this;
        Node* end = new Node(d);

        while(current->next != NULL)
            current = current->next;

        current->next = end;
    }

    //returns the head
    Node* Delete(Node* head, int d) {
        Node *n = head;
        if(head->data == d) {
            head = head->next;
            delete(n);
            return head;
        }

        while(n->next != NULL) {
            if(n->next->data == d) {
                Node *deletionNode = n->next;
                n->next = n->next->next;
                delete(deletionNode);
                return head;
            }
            n = n->next;
        }
        return head;
    }
};

void PrintList(Node* head) {
    Node* current = head;
    cout << current->data << " -> ";
    while(current->next != NULL) {
        cout << current->next->data << " -> ";
        current = current->next;
    }
    cout << "END" << endl;
}


int main(int argc, char* argv[]) {
    Node* head = new Node(5);
    head->Add(6);
    head->Add(7);
    head->Add(8);
    head->Add(9);
    PrintList(head);

    cout << "Deleting" << endl;
    head = head->Delete(head, 6);
    PrintList(head);
    cout << "Deleting Head" << endl;
    head = head->Delete(head, 9);
    PrintList(head);

}
