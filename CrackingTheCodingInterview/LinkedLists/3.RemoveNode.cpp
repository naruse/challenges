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

    Node* AddToEnd(int d) {
        Node* end = new Node(d);
        Node* current = this;
        while(current->next != NULL)
            current = current->next;
        current->next = end;
        return end;
    }
    ~Node() {
        data = -1;
        delete(next);
        next = NULL;
    }
};

void PrintList(Node* head) {
    if(head == NULL)
        return;
    cout << head->data << " -> ";
    Node* nextNode = head->next;
    while(nextNode != NULL) {
        cout << nextNode->data << " -> ";
        nextNode = nextNode->next;
    }
    cout << "END" << endl;
}


void DeleteNode(Node* n) {
    if(n == NULL || n->next == NULL)
        return;
    Node* current = n;
    Node* runner = n->next;
    Node* nodeBeforeEnd;
    while(runner != NULL) {
        current->data = runner->data;

        if(current->next->next == NULL)//last pointer before the one we are deleting
            nodeBeforeEnd = current;

        runner = runner->next;
        current = current->next;

    }
    cout << "deleting last node" << endl;
    delete(current);
    current = NULL;
    nodeBeforeEnd->next = NULL;
}


int main(int argc, char* argv[]) {
    Node* head = new Node(2);
    head->AddToEnd(4);
    head->AddToEnd(6);
    head->AddToEnd(8);
    head->AddToEnd(10);
    Node* n = head->AddToEnd(12);
    head->AddToEnd(14);
    head->AddToEnd(16);
    PrintList(head);
    cout << "Removing " << n->data << endl;
    DeleteNode(n);
    PrintList(head);
}
