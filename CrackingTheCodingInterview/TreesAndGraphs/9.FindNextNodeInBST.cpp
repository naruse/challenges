/*
  Write an algorithm to find the'next'node (i.e., in-order successor) of a
  given node in a binary search tree. You may assume that each node has a link
  to its parent.
*/

#include <iostream>

using namespace::std;

class Node {
private:
    static int currentId;
    int id;
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int GetID() { return id; }
    Node(int d) {
        data = d;
        left = right = parent = nullptr;
        id = currentId;
        currentId++;
    }

    void Insert(int d) {
        if(d <= data && left == nullptr) {
            left = new Node(d);
            left->parent = this;
        } else if(d <= data) {
            left->Insert(d);
        } else if(d > data && right == nullptr) {
            right = new Node(d);
            right->parent = this;
        } else {
            right->Insert(d);
        }
    }
};

Node* LeftMostNode(Node * n) {
    if(n == nullptr) return nullptr;
    Node * mostLeft = n;
    while(mostLeft->left != nullptr)
        mostLeft = mostLeft->left;
    return mostLeft;
}

Node* FindNextNodeInBST(Node* n) {
    if(n == nullptr) return nullptr;
    if(n->right != nullptr)
        return LeftMostNode(n->right);
    else {
        Node* maybeRight = n;
        Node* parentN = maybeRight->parent;
        while(parentN != nullptr && parentN->left->GetID() != maybeRight->GetID()) {
            maybeRight = parentN;
            parentN = parentN->parent;
        }
        return parentN;
    }
}


int Node::currentId = 0;
int main(int argc, char* argv[]) {
    Node* root = new Node(30);
    root->Insert(15);
    root->Insert(45);
    root->Insert(46);
    root->Insert(50);
    root->Insert(57);
    root->Insert(95);
    root->Insert(19);

    Node* original = root->right;
    Node* next = FindNextNodeInBST(original);
    cout << "Next node from: " << original->data << " is:" << next->data << endl;

}
