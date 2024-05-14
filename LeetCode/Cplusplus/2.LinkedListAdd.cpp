/*
  https://leetcode.com/articles/add-two-numbers/

  You are given two non-empty linked lists representing two non-negative
  integers. The digits are stored in reverse order and each of their nodes
  contain a single digit. Add the two numbers and return it as a linked
  list.

  You may assume the two numbers do not contain any leading zero, except the
  number 0 itself.

  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
  Explanation: 342 + 465 = 807.
*/

#include <iostream>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {}
};

ListNode* AddTwoNumers(ListNode* L1, ListNode* L2);
ListNode* AddToList(ListNode* l, int val);

void PrintList(ListNode* l) {
    ListNode* current = l;
    while(current != nullptr) {
        cout << current->val << "->";
        current = current->next;
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    ListNode* l1 = new ListNode(2);
    //l1->next = new ListNode(4);
    //l1->next->next = new ListNode(3);
    ListNode* l;
    l = AddToList(l1, 4);
    l = AddToList(l, 3);
    PrintList(l1);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    PrintList(l2);

    ListNode* result = AddTwoNumers(l1, l2);
    PrintList(result);
}

ListNode* AddTwoNumers(ListNode* l1, ListNode* l2) {
    ListNode* currentL1 = l1;
    ListNode* currentL2 = l2;
    ListNode* resultHead = nullptr;
    ListNode* currentResult = nullptr;
    int carry = 0;
    bool start = true;

    while(currentL1 != nullptr || currentL2 != nullptr) {
        int valL1 = currentL1 != nullptr ? currentL1->val : 0;
        int valL2 = currentL2 != nullptr ? currentL2->val : 0;

        int currResult = valL1 + valL2 + carry;

        if(currResult > 9) {
            currResult = currResult%10;
            carry = 1;
        } else {
            carry = 0;
        }

        if(start) {
            resultHead = new ListNode(currResult);
            currentResult = resultHead;
            start = false;
        } else {
            currentResult = AddToList(currentResult, currResult);
        }

        currentL1 = currentL1 != nullptr ? currentL1->next : nullptr;
        currentL2 = currentL2 != nullptr ? currentL2->next : nullptr;
    }
    if(carry == 1) {
        currentResult = AddToList(currentResult, 1);
    }

    return resultHead;
}

ListNode* AddToList(ListNode* l, int val) {
    l->next = new ListNode(val);
    return l->next;
}
