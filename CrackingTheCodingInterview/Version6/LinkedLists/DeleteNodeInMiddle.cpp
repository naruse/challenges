//Implement an algorithm to delete a node in the middle (i.e., any node but
//the first and last node, not necessarily the exact middle) of a singly
//linked list, given only access to that node.
//EXAMPLE
//Input:  the node c from the linked list a - >b- >c - >d - >e- >f
//Result: new linked list looks like a - >b- >d - >e- >f

//Approach:
// Given the node to delete, start replacing the contents of the next node
// with the current one and delete the last node.

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int _d) { data = _d; next = nullptr; }
    ~Node() { data = -1; }

    //returns added node
    Node* AddToTail(int d) {
        Node* current = this;
        Node* nodeOnTail = new Node(d);

        while(current->next != nullptr)
            current = current->next;
        current->next = nodeOnTail;
        return nodeOnTail;
    }
};

void Print(Node* head) {
    Node* current = head;

    while(current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

void RemoveNode(Node* n) {
    //assuming the node to remove is not the last one nor the first one.
    Node* current = n;
    Node* nextNode = current->next;

    while(nextNode != nullptr) {
        current->data = nextNode->data;
        current = nextNode;
        nextNode = nextNode->next;
        std::cout << "Current: " << current->data << " Next: " << ((nextNode == nullptr) ? "null" : std::to_string(nextNode->data)) << std::endl;
    }
    //NOSE PORQUE PUTAS SIGUE IMPRIMIENDO EL -1!!! en vez de NO IMPRIMIR EL ULTIMO!
    delete(current);
    current = nullptr;

}

int main() {
    Node* head = new Node(-9);
    head->AddToTail(8);
    head->AddToTail(7);
    head->AddToTail(3);
    head->AddToTail(4);
    Node* nodeToDelete = head->AddToTail(6);
    head->AddToTail(2);
    head->AddToTail(1);
    head->AddToTail(3);
    head->AddToTail(5);

    std::cout << "Original List:" << std::endl;
    Print(head);

    RemoveNode(nodeToDelete);
    std::cout << "Removed node List:" << std::endl;
    Print(head);

}
