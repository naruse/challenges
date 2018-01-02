/*
  Given a sorted (increasingorder) array with unique integer
  elements, write an algorithm to createa binary search tree
  with minimal height.

  Approach:
  We are basically looking for a balanced binary search tree; given that the
  array is organized in increasing order, we select the middle of the array
  and set it up as a node, and then subdivide the middle left and middle
  right arrays and repeat.
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace::std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
    void Insert(int d) {
        if(d <= data && left == nullptr)
            left = new BSTNode(d);
        else if(d <= data)
            left->Insert(d);
        else if(d > data && right == nullptr)
            right = new BSTNode(d);
        else
            right->Insert(d);
    }

    int GetHeight() {
        int lHeight = 0;
        int rHeight = 0;
        if(left != nullptr)
            lHeight = left->GetHeight() + 1;
        if(right != nullptr)
            rHeight = right->GetHeight() + 1;
        return max(lHeight, rHeight);
    }
};

BSTNode* BSTMinHeight(vector<int> const &values, int start, int end) {
    if(start > end)
        return nullptr;
    int mid = (start+end)/2;
    BSTNode* n = new BSTNode(values[mid]);
    cout << "Created node: " << n->data << endl;
    n->left = BSTMinHeight(values, start, mid-1);
    n->right = BSTMinHeight(values, mid+1, end);
    return n;
}

BSTNode* GenerateMinHeightBSTTree(vector<int> const& values) {
    return BSTMinHeight(values, 0, values.size() - 1);
}

void BFSBST(BSTNode* n) {

    queue<BSTNode*> q;
    q.push(n);

    while(!q.empty()) {
        BSTNode* current = q.front();
        q.pop();
        cout << current->data << " ";
        if(current->left != nullptr)
            q.push(current->left);
        if(current->right != nullptr)
            q.push(current->right);

    }
}

void DFSPreOrder(BSTNode* n) {
    cout << n->data << " ";
    if(n->left != nullptr)
        DFSPreOrder(n->left);
    if(n->right != nullptr)
        DFSPreOrder(n->right);
}

int main (int argc, char* argv[]) {
    vector<int> values {1,2,5,6,8,9};//{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    BSTNode* root = GenerateMinHeightBSTTree(values);
    if(root == nullptr)
        cout << "ROOT NULL" << endl;
    cout << "BFS generated tree" << endl;
    BFSBST(root);
    cout << endl;
    //DFSPreOrder(root);
}


