#include <iostream>
#include <unordered_set>

using namespace::std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int d) {
        data = d;
        left = right = parent = nullptr;
    }

    Node* InsertLeft(int d) {
        Node* inserted = new Node(d);
        inserted->parent = this;
        if(left == nullptr) {
            left = inserted;
        } else {
            inserted->left = left;
            left = inserted;
            left->parent = inserted;
        }
        return inserted;
    }

    Node* InsertRight(int d) {
        Node* inserted = new Node(d);
        inserted->parent = this;
        if(right == nullptr) {
            right = inserted;
        } else {
            inserted->right = right;
            right = inserted;
            right->parent = inserted;
        }
        return inserted;
    }
};

Node const* CommonAncestor(Node const* m, Node const* n) {
    if( n == nullptr || m == nullptr) return nullptr;
    unordered_set<int> nodesN;
    unordered_set<int> nodesM;

    Node const* currentN = n;
    Node const* currentM = m;
    while(currentN != nullptr || currentM != nullptr) {
        if(nodesN.find(currentM->data) != nodesN.end())
            return currentM;
        if(nodesM.find(currentN->data) != nodesM.end())
            return currentN;

        if(currentN != nullptr) {
            nodesN.insert(currentN->data);
            currentN = currentN->parent;
        }
        if(currentM != nullptr) {
            nodesM.insert(currentM->data);
            currentM = currentM->parent;
        }
    }
    return nullptr;
}

int main(int argc, char* argv[]) {
    Node* root = new Node(3);

    Node* n;
    Node* m;

    root->InsertRight(-1);
    root->InsertLeft(7);
    root->right->InsertRight(70);
    root->right->right->InsertLeft(89);
    root->right->right->InsertRight(91);
    root->right->right->right->InsertRight(15);
    m = root->right->right->right->InsertLeft(99);

    root->left->InsertLeft(6);
    root->left->InsertRight(9);
    root->left->right->InsertLeft(5);
    root->left->right->left->InsertRight(8);
    root->left->right->left->right->InsertRight(10);
    root->left->right->left->right->InsertRight(11);
    root->left->left->InsertLeft(4);
    root->left->left->InsertRight(2);
    root->left->left->right->InsertRight(1);
    n = root->left->left->right->right->InsertLeft(0);

    Node const* ancestor = CommonAncestor(n, m);
    if(ancestor == nullptr) {
        cout << "No common ancestor" << endl;
        return 0;
    }
    cout << "Common ancestor of: " << n->data << " and " << m->data << " is: " << ancestor->data << endl;
}
