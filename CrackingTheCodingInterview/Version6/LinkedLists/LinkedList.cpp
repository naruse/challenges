//This is the implementation of a linked list that contains numbers.

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int d) { data = d; next = nullptr; }

    void AppendToTail(int data) {
        Node* tailNode = new Node(data);
        Node* current = this;

        while(current->next != nullptr)
            current = current->next;
        current->next = tailNode;
    }

    //returns the head node
    Node* DeleteNode(Node* head, int _data) {
        Node* current = head;

        if(current->data == _data) {
            Node* newHead = current->next;
            delete(current);
            return newHead;
        }
        current = current->next;
        while(current->next != nullptr) {
            if(current->next->data == _data) {
                Node* deletionNode = current->next;
                current->next = deletionNode->next;
                delete(deletionNode);
            }
            current = current->next;
        }
        return head;
    }
};

void PrintList(Node* head) {
    if(head == nullptr)
        return;
    Node* current = head;
    while(current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(5);
    head->AppendToTail(8);
    head->AppendToTail(7);
    head->AppendToTail(6);
    head->AppendToTail(5);
    head->AppendToTail(4);

    PrintList(head);
    head->DeleteNode(head, 6);
    
    PrintList(head);
}
