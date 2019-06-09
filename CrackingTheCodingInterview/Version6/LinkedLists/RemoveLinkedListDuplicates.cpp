// Write code to remove duplicates from an unsorted li nked list.

//APPROACH
//store the values on a set and check if they already exist; if they do remove.
//FOLLOW UP
//How would you solve this problem if a temporary buffer is not allowed?
// --> It would became O(n^2) and for each element check that it doesnt exist
//in the list
#include <iostream>
#include <unordered_set>

class Node {
public:
    int data;
    Node* next;

    Node(int _data) { data = _data; next = nullptr; }

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
        return;
    Node* current = head;
    while(current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

std::unordered_set<int> detectedValues;
void RemoveDuplicates(Node* head) {
    Node* current = head;

    detectedValues.insert(current->data);
    //lets iterate through the list
    while(current->next != nullptr) {
        if(detectedValues.find(current->next->data) == detectedValues.end()){//if val doesntExist
            detectedValues.insert(current->next->data);
            current = current->next;
        } else {//value already exists. lets remove next
            //current->next needs to be removed.
            Node* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            delete(nodeToDelete);
        }

    }

}

int main() {
    Node* head = new Node(-9);
    head->AddToTail(-8);
    head->AddToTail(-7);
    head->AddToTail(-7);
    head->AddToTail(-7);
    head->AddToTail(-7);
    head->AddToTail(-7);
    head->AddToTail(-7);
    head->AddToTail(-4);
    head->AddToTail(2);

    std::cout << "Original List:" << std::endl;
    Print(head);

    RemoveDuplicates(head);
    std::cout << "No duplicates: " << std::endl;
    Print(head);
}
