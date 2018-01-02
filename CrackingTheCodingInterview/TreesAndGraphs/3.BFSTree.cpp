#include <iostream>
#include <queue>

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

void BFS(Node *n) {
    cout << "BFS" << endl;
    queue<Node*> q;
    q.push(n);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if(current->left != nullptr)
            q.push(current->left);
        if(current->right != nullptr)
            q.push(current->right);
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    Node* root = new Node(1);
    root->InsertLeft(2);
    root->InsertRight(5);

    root->left->InsertLeft(3);
    root->left->InsertRight(4);

    root->right->InsertLeft(6);
    root->right->InsertRight(7);

    BFS(root);

}
