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

Node* const  GenerateValidBST() {
    Node* root = new Node(4);
    root->InsertLeft(3);
    root->InsertRight(7);

    root->right->InsertLeft(5);
    root->right->left->InsertRight(6);

    root->left->InsertLeft(2);
    root->left->left->InsertLeft(1);

    root->InsertLeft(3);
    return root;
}

Node* GenerateInvalidBST() {
    Node* root = new Node(5);
    root->InsertLeft(3);
    root->InsertRight(8);

    root->left->InsertLeft(2);
    root->left->InsertRight(6);

    root->right->InsertLeft(7);
    root->right->InsertRight(9);
    return root;
}

bool IsBinTreeBST(Node* n, int min, int max) {
    if(n == nullptr) return true;

    if(min < n->data && max >= n->data)
        if(IsBinTreeBST(n->left, min, n->data) && IsBinTreeBST(n->right, n->data, max))
            return true;

    return false;
    
}

int main(int argc, char* argv[]) {
    Node* invalidBST = GenerateInvalidBST();
    Node* validBST = GenerateValidBST();

    cout << "Invalid: " << (IsBinTreeBST(invalidBST, -999, 999)?"true":"false") << endl;
    cout << "valid: " << (IsBinTreeBST(validBST, -999, 999)?"true":"false") << endl;

}
