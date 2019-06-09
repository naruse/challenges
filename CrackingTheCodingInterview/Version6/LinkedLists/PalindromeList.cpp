// Implement a function to check if a linked list is a palindrome.


//APPROACH:
//have 2 pointers one move 1 node the other moves 2 nodes each time and start
//storing values on a stack for the 1rst node. When the 2nd pointer reaches
//the end start popping from the stack and compare.

#include <iostream>
#include <stack>

class Node {
public:
    int data;
    Node* next;
    Node(int _d) { data = _d; next = nullptr; }

    Node* AddToTail(int ds) {
        Node* current = this;
        Node* nodeToAdd = new Node(ds);
        while(current->next != nullptr)
            current = current->next;
        current->next = nodeToAdd;
        return nodeToAdd;
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

bool IsPalindrome(Node* head) {
    if(head == nullptr)
        return false;
    Node* slow = head;
    Node* fast = head->next;

    std::stack<int> detectedValues;

    bool needToMove = false;
    //lets get to the middle of the list.
    while(fast != nullptr) {
        std::cout << "\nAdding: " << slow->data;
        detectedValues.push(slow->data);
        slow = slow->next;

        fast = fast->next;
        if(fast != nullptr) {
            needToMove = true;
            fast = fast->next;
        } else
            needToMove = false;
    }


    //by here we are in the middle of the list
    if(needToMove)
        slow = slow->next;

    //now lets start checking if its a palindrome
    while(slow != nullptr) {
        if(detectedValues.top() != slow->data)
            return false;
        slow = slow->next;
        detectedValues.pop();
    }
    return true;
}


int main() {
    Node* head = new Node(4);
    head->AddToTail(3);
    head->AddToTail(3);
    //head->AddToTail(66);
    head->AddToTail(4);



    std::cout << "List to check:\n";
    Print(head);
    
    std::cout << "Is palindrome: " << (IsPalindrome(head) ? "true" : "false") << "\n";
}
