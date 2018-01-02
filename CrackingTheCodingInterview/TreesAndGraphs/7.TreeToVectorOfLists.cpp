/*
Given a binary tree, design an algorithm which creates a linked list of all
the nodes at each depth (e.g., if you have a tree with depth D,you'll have D
linked lists).
 */

#include <iostream>
#include <vector>
#include <list>

using namespace::std;

vector<list<int> > lists;


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

void DFSPreOrderPrint(Node* n) {
    if(n == nullptr) return;

    cout << n->data << " ";
    DFSPreOrderPrint(n->left);
    DFSPreOrderPrint(n->right);
}

void DFSGenerateLists(Node* root, int lvl) {
    if(root == nullptr) return;
    //    vector<int> l;
    if(lvl == lists.size())
        lists.push_back(list<int>());

    lists[lvl].push_back(root->data);
    cout << "adding: " << root->data << " lvl:" << lvl << endl;

    DFSGenerateLists(root->left, lvl+1);
    DFSGenerateLists(root->right, lvl+1);
}

void PrintLists(vector<list<int> > vecLists) {
    for(int i = 0; i < vecLists.size(); i++) {
        list<int>::iterator it = vecLists[i].begin();
        cout << "List " << i << ":" << endl;
        while(it != vecLists[i].end()) {
            cout << *it << "->";
            it++;
        }
        cout << endl;
    }
}


int main(int argc, char* argv[]) {
    Node* root = new Node(1);
    root->InsertLeft(2);
    root->InsertRight(5);

    root->left->InsertLeft(3);
    root->left->InsertRight(4);

    root->right->InsertLeft(6);
    root->right->InsertRight(7);

    //DFSPreOrderPrint(root);

    DFSGenerateLists(root, 0);
    cout << "\nPrinting generated lists: " << endl;
    PrintLists(lists);
}
