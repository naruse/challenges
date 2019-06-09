//Implement an algorithm to find the kth to last element of a singly linked
//list.

//APPROACH:
// I would have two nodes separated by K nodes between them and start counting through the list
// until the second node finishes, then I return the first node.


#include <iostream>


class Node {
public:
    int data;
    Node* next;
    Node(int _d) { data = _d; next = nullptr; }

    void AddToTail(int d) {
        Node* current = this;
        Node* nodeToAdd = new Node(d);

        while(current->next != nullptr)
            current = current->next;
        current->next = nodeToAdd;
    }
};

void Print(Node* head) {
    if(head == nullptr)
        std::cerr << "Head is null!" << std::endl;
    Node* current = head;

    while(current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

//returns the kth element from the end
Node* FindKthFromLast(Node* head, int kthFromLast) {
    Node* firstNode = head;
    Node* secondNode = head;

    //move secondNode kth spaces from the 1rst one.
    for(int i = 0; i < kthFromLast; i++) {
        if(secondNode != nullptr)
            secondNode = secondNode->next;
        else {
            std::cerr <<"Kth element "<< kthFromLast << "Is bigger than list size!" << std::endl;
            return nullptr;
        }
    }
    //now lets start moving the 1rst node and the second until we reach the end :)
    while(secondNode != nullptr) {
        firstNode = firstNode->next;
        secondNode = secondNode->next;
    }
    return firstNode;

}

int main() {
    Node* head = new Node(-9);
    head->AddToTail(8);
    head->AddToTail(7);
    head->AddToTail(3);
    head->AddToTail(4);
    head->AddToTail(6);
    head->AddToTail(2);
    head->AddToTail(1);
    head->AddToTail(3);
    head->AddToTail(5);

    std::cout << "Original List:" << std::endl;
    Print(head);

    Print(FindKthFromLast(head, 3));

}
