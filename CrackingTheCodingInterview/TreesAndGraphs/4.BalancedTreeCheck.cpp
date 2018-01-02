/*
  Check if a tree is balanced.
 */

#include <iostream>

using namespace::std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = nullptr;
    }

    void InsertLeft(int d) {
        Node* inserted = new Node(d);
        if(left == nullptr)
            left = inserted;
        else {
            inserted->left = left;
            left = inserted;
        }
    }
    void InsertRight(int d) {
        Node* inserted = new Node(d);
        if(right == nullptr)
            right = inserted;
        else {
            inserted->right = right;
            right = inserted;
        }
    }
};

int GetTreeHeight(Node* const n) {

    if(n == nullptr) return 0;
    int lHeight = GetTreeHeight(n->left) +1;
    int rHeight = GetTreeHeight(n->right) +1;

    if(lHeight == -1)
        return -1;
    if(rHeight == -1)
        return -1;
    if(abs(lHeight - rHeight) > 1)
        return -1;
    else
        return max(lHeight, rHeight);
}

bool IsTreeBalanced(Node* root) {
    if(GetTreeHeight(root) == -1)
        return false;
    else
        return true;
}


int main(int argc, char* argv[]) {
    Node* root = new Node(1);
    root->InsertLeft(2);
    root->InsertRight(5);

    root->left->InsertLeft(3);
    root->left->InsertRight(4);

    root->right->InsertLeft(6);
    root->right->InsertRight(7);

    cout << "Tree Balanced: " << IsTreeBalanced(root) << endl;
}
