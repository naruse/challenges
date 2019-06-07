#include <iostream>

using namespace::std;

class Node {
public:
    char data;
    Node* leftChild;
    Node* rightChild;

    Node(char c) {
        data = c;
        leftChild = nullptr;
        rightChild = nullptr;
    }

    void InsertLeft(char lVal) {
        if(leftChild == nullptr) {
            leftChild = new Node(lVal);
        } else {
            Node* tmp = leftChild;
            leftChild = new Node(lVal);
            leftChild->leftChild = tmp;
        }
    }

    void InsertRight(char rVal) {
        if(rightChild == nullptr) {
            rightChild = new Node(rVal);
        } else {
            Node* tmp = rightChild;
            rightChild = new Node(rVal);
            rightChild->rightChild = tmp;
        }
    }
};

void DFSPreOrder(Node *const n) {
    cout << n->data << " ";

    if(n->leftChild != nullptr)
        DFSPreOrder(n->leftChild);
    if(n->rightChild != nullptr)
        DFSPreOrder(n->rightChild);
}

int main(int argc, char* argv[]) {
    Node* root = new Node('a');
    root->InsertLeft('b');
    root->InsertRight('c');
    root->leftChild->InsertRight('d');

    root->rightChild->InsertRight('f');
    root->rightChild->InsertLeft('e');

    DFSPreOrder(root);
    cout << endl;

}
