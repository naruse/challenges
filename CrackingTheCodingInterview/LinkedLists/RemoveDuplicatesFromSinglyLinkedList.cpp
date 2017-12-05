#include <iostream>
#include <unordered_map>

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
        Node* current = this;
        Node* end = new Node(d);
        while(current->next != NULL)
            current = current->next;
        current->next = end;
    }

    Node* Delete(Node* head, int d) {
        if(head->data == d) {//if the head has the value, then lets return
                             //the next and delete the head.
            Node* newHead = head->next;
            delete(head);
            return newHead;
        }

        Node* current = head;
        while(current->next != NULL) {
            if(current->next->data == d) {
                Node* nodeToDelete = current->next;
                current->next = current->next->next;
                delete(nodeToDelete);
                return head;
            }
            current = current->next;
        }
        return head;
    }
};

void PrintLinkedList(Node* head) {
    if(head == NULL){
        cout << "Null head, maybe empty list?" << endl;
        return;
    }
    
    Node* current = head;
    cout << current->data << " -> ";
    while(current->next != NULL) {
        cout << current->next->data << " -> ";
        current = current->next;
    }
    cout << "END" << endl;
}

void DeleteDuplicateNodesUsingHashTable(Node* head) {//O(n)
    unordered_map<int, bool> duplicatedValues;

    Node* current = head;
    if(current == NULL)
        return;
    duplicatedValues[current->data] = true;

    while(current->next != NULL) {
        if(duplicatedValues.find(current->next->data) == duplicatedValues.end()) {
            duplicatedValues[current->next->data] = true;
            current = current->next;
        } else {
            Node* deletionNode = current->next;
            current->next = current->next->next;
            delete(deletionNode);
        }
    }
}

void DeleteDuplicateNodesWith2Pointers(Node* head) {//O(1) Space, O(n^2) time
    //here we set a runner pointer to find duplicates as we go through the list
    if(head == NULL)
        return;

    Node* current = head;

    while(current != NULL) {
        Node* runner = current;
        while(runner->next != NULL) {
            if(runner->next->data == current->data) {
                delete(runner->next);
                runner->next = runner->next->next;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;

    }
}

int main(int argc, char* argv[]) {
    Node* head = new Node(10);
    head->AddToEnd(5);
    head->AddToEnd(10);
    head->AddToEnd(15);
    head->AddToEnd(25);
    head->AddToEnd(25);
    head->AddToEnd(30);
    head->AddToEnd(25);
    head->AddToEnd(30);
    head->AddToEnd(35);
    head->AddToEnd(40);
    head->AddToEnd(45);
    PrintLinkedList(head);
    //DeleteDuplicateNodesUsingHashTable(head);
    DeleteDuplicateNodesWith2Pointers(head);
    PrintLinkedList(head);
}
