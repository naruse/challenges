/*
  Write code to partition a linked list around a value x, such that all nodes
  less than x come before all nodes greater than or equal to x

  Approach:
  Given the partition number and the head of the linked list, we split the
  list into 2 sublists and then at the end we merge the sublists and return
  the new head. (beginning of the 1rst sublist).
*/

#include <iostream>

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
        Node* end = new Node(d);
        Node* current = this;
        while(current->next != NULL)
            current = current->next;
        current->next = end;
    }
};

void PrintList(Node* head) {
    if(head == NULL)
        return;
    Node* current = head;
    cout << current->data << " -> ";
    while(current->next != NULL) {
        cout << current->next->data << " -> ";
        current = current->next;
    }
    cout << "END" << endl;
}

Node* PartitionList(Node* head, int partitionValue) {
    if(head == NULL) return NULL;
    Node* afterPartition = NULL;
    Node* beforePartition = NULL;
    Node* beginningBefore = NULL;
    Node* beginningAfter = NULL;
    Node* current = head;

    while(current != NULL) {
        Node* nextN = current->next;
        current->next = NULL;

        if(current->data >= partitionValue) {
            if(afterPartition == NULL) {
                beginningAfter = current;
                afterPartition = current;
            }
            afterPartition->next = current;
            afterPartition = current;
        } else {
            if(beforePartition == NULL) {
                beginningBefore = current;
                beforePartition = current;
            }
            beforePartition->next = current;
            beforePartition = current;
        }
        current = nextN;
    }
    beforePartition->next = beginningAfter;//connect sublists
    return beginningBefore;
}

int main(int argc, char* argv[]) {
    Node* head = new Node(7);
    head->AddToEnd(6);
    head->AddToEnd(2);
    head->AddToEnd(9);
    head->AddToEnd(4);
    head->AddToEnd(1);
    PrintList(head);
    int partition = 7;
    cout << "Partitioning list with: " << partition << endl;
    Node* reArrangedList = PartitionList(head, partition);
    PrintList(reArrangedList);
}
