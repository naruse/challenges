//You have two numbers represented by a linked list, where each node contains
//a single digit. The digits are stored in reverse order, such that the 1's
//digit is at the head of the list. Write a function that adds the two
//numbers and returns the sum as a linked list.

//EXAMPLE
//Input: (7-> 1 -> 6) + (5 -> 9 -> 2).  That is, 617 + 295.
//Output: 2 -> 1 -> 9.That is, 912.

//APPROACH:
//lets go through the two lists and create a new list and start adding while
//building the addition list.

//==== FOLLOW UP =====
// Suppose the digits are stored in forward order. Repeat the above problem.
//APPROACH Change the list to number, add numbers and then convert back to list.

#include <iostream>
#include <utility> //std::pair
#include <stack>


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
        return;
    Node* current = head;

    while(current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

//returns the adition and 1 if there is a carry.
std::pair<int, int> AddWithCarry(int a, int b) {
    int ab = a + b;
    int carry = 0;
    if(ab > 9) {
        ab = ab%10;
        carry = 1;
    }
    std::pair<int, int> result(ab, carry);
    return result;
}

//Adds the lists (Lists are expected to be in reverse order)//7->1->6 (is 617)
//suppossing the lists are not null.
Node* AddReversedLists(Node* n1, Node* n2) {
    int carry = 0;
    Node* current1 = n1;
    Node* current2 = n2;

    std::pair<int, int> addition = AddWithCarry(n1->data, n2->data);

    Node* result = new Node(addition.first);
    current1 = current1->next;
    current2 = current2->next;

    while(current1 != nullptr || current2 != nullptr) {
        int val1 = 0;
        int val2 = 0;
        if(current1 != nullptr)
            val1 = current1->data;
        if(current2 != nullptr)
            val2 = current2->data;

        addition = AddWithCarry(val1, val2 + addition.second/*carry*/);
        result->AddToTail(addition.first);

        current1 = current1->next;
        current2 = current2->next;
    }
    return result;
}

int ListToNumber(Node* head) {
    Node* current = head;
    std::string result = "";//this is a hack; but to do it better we need the
                            //length of the list.
    while(current != nullptr) {
        result += std::to_string(current->data);
        current = current->next;
    }
    return stoi(result);
}

Node* NumberToList(int i) {
    std::stack<int> digits;

    int tmp = i;
    while(tmp/10 != 0) {
        digits.push(tmp%10);
        tmp = tmp/10;
    }
    digits.push(tmp%10);
    Node* converted = new Node(digits.top());
    digits.pop();
    while(!digits.empty()) {
        converted->AddToTail(digits.top());
        digits.pop();
    }
    return converted;
}

Node* AddForwardLists(Node* n1, Node* n2) {
    int number1 = ListToNumber(n1);
    int number2 = ListToNumber(n2);
    std::cout << "n1+n2: " << number1+number2 << "\n";
    return NumberToList(number1+number2);
}

int main() {
    std::cout << "REVERSE ORDER\n";
    Node* number1 = new Node(7);
    number1->AddToTail(1);
    number1->AddToTail(6);

    std::cout << "Number 1: (617)\n";
    Print(number1);

    Node* number2 = new Node(5);
    number2->AddToTail(9);
    number2->AddToTail(2);
    std::cout << "Number 2: (295)\n";
    Print(number2);
    std::cout << "Result:\n";
    Node* resultReverse = AddReversedLists(number1, number2);
    Print(resultReverse);

    std::cout << "\n\nFORWARD ORDER\n";

    Node* number1F = new Node(6);
    number1F->AddToTail(1);
    number1F->AddToTail(7);

    std::cout << "Number 1: (617)\n";
    Print(number1F);

    Node* number2F = new Node(2);
    number2F->AddToTail(9);
    number2F->AddToTail(5);
    std::cout << "Number 2: (295)\n";
    std::cout << "List to num: " << ListToNumber(number2F) << "\n";
    Print(number2F);

    Node* resultForward = AddForwardLists(number1F, number2F);
    std::cout << "Result:\n";
    Print(resultForward);

}
