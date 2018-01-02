#include <iostream>

using namespace::std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }

    Node* InsertLeft(int d) {
        Node* inserted = new Node(d);
        if(left == nullptr)
            left = inserted;
        else {
            inserted->left = left;
            left = inserted;
        }
        return inserted;
    }

    Node* InsertRight(int d) {
        Node* inserted = new Node(d);
        if(right == nullptr)
            right = inserted;
        else {
            inserted->right = right;
            right = inserted;
        }
        return inserted;
    }
};


void DFSPreOrder(Node* n) {
    cout << n->data << " ";
    if(n->left != nullptr)
        DFSPreOrder(n->left);
    if(n->right != nullptr)
        DFSPreOrder(n->right);
}

void DFSInOrder(Node *n) {
    if(n->left != nullptr)
        DFSInOrder(n->left);
    cout << n->data << " ";
    if(n->right != nullptr)
        DFSInOrder(n->right);
}

void DFSPostOrder(Node *n) {
    if(n->left != nullptr)
        DFSPostOrder(n->left);
    if(n->right != nullptr)
        DFSPostOrder(n->right);
    cout << n->data << " ";
}

int main(int argc, char* argv[]) {
    Node* root = new Node(1);
    root->InsertLeft(2);
    root->InsertRight(5);

    root->left->InsertLeft(3);
    root->left->InsertRight(4);

    root->right->InsertLeft(6);
    root->right->InsertRight(7);

    cout << "Pre  Order" << endl;
    DFSPreOrder(root);
    cout << endl;

    cout << "In   Order" << endl;
    DFSInOrder(root);
    cout << endl;

    cout << "Post Order" << endl;
    DFSPostOrder(root);
    cout << endl;
}
