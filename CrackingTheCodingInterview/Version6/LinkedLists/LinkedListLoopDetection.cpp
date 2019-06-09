//Given a circular linked list, implement an algorithm that returns the node
//at the beginning of the loop.
//EXAMPLE
// Input: A -> B -> C -> D -> E -> C[the same C as earlier]
// Output: C
//
//APPROACH:
// We start to go through the list and save values on a set; if the values in
// the set already exist then we found the loop and return the node.

#include <iostream>
#include <set>

class Node {
public:
    char data;
    Node* next;
    Node(char c) { data = c; next = nullptr; }

    Node* AddToTail(char c) {
        Node* current = this;
        Node* nodeToAdd = new Node(c);
        while(current->next != nullptr)
            current = current->next;
        current->next = nodeToAdd;
        return nodeToAdd;
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

Node* AddAndPrintAddress(Node* head, char c) {
    Node* added = head->AddToTail(c);
    std::cout << "(" << added->data << ") address: " << added << std::endl;
    return added;
}

//returns nullptr if there is no loop
Node* DetectLoop(Node* head) {
    std::set<Node*> detectedAddresses;

    Node* current = head;
    while(current != nullptr) {
        if(detectedAddresses.find(current) == detectedAddresses.end()) {//AddressHasntBeenSeen
            detectedAddresses.insert(current);//insert address
        } else {//address has been seen!, lets return this node
            return current;
        }
        
        current = current->next;
    }
    return nullptr;
}

int main() {
    Node* head = new Node('A');

    AddAndPrintAddress(head, 'B');
    Node* n = AddAndPrintAddress(head, 'C');
    AddAndPrintAddress(head, 'D');
    AddAndPrintAddress(head, 'E');
    Node* loop = AddAndPrintAddress(head, 'F');
    AddAndPrintAddress(head, 'G');

    std::cout << "ORIG LIST: " << std::endl;
    Print(head);

    loop->next = n;//<-- HERE WE INSERT THE LOOP
    Node* loopedNode = DetectLoop(head);
    std::cout << "Looped node: " << loopedNode->data << std::endl;
    //Print(head);//uncoment this to have a infinite loop :)

}
