//given a sorted (increasing order) array with unique integer elements write
//a program to create a binary search tree with minimal height.

//APPROACH:

//Get to half of the tree and put the middle half tot he left and from the
//middle to length-1 to the right.


#include <iostream>
#include <vector>
#include <queue>
#include <utility>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) { data = d; left = right = nullptr; }

    void InsertLeft(Node* n) {

    }
    void InsertRight(Node* n) {

    }
};

Node* GenerateTreeFromArray(std::vector<int> values, int min, int max) {
    if(min > max)
        return nullptr;

    int mid = (min + max)/2;
    Node* current = new Node(values[mid]);

    current->left = GenerateTreeFromArray(values, min, mid-1);
    current->right = GenerateTreeFromArray(values, mid+1, max);


    return current;
}

void Print(Node* n) {
    std::queue<std::pair<Node*, int> > q;
    int lvl = 0;
    q.push(std::pair<Node*, int>(n, lvl));

    std::vector<std::vector<int> > valuesToPrint;
    while(!q.empty()) {
        std::pair<Node*, int> currPair = q.front();
        q.pop();

        if(currPair.second >= valuesToPrint.size()) {
            valuesToPrint.push_back(std::vector<int>());
        }
        valuesToPrint[currPair.second].push_back(currPair.first->data);

        if(currPair.first->left != nullptr)
            q.push(std::pair<Node*, int>(currPair.first->left, currPair.second+1));
        if(currPair.first->right != nullptr)
            q.push(std::pair<Node*, int>(currPair.first->right, currPair.second+1));
    }
    for(int i = 0; i < valuesToPrint.size(); i++) {
        for(int j = 0; j < valuesToPrint[i].size(); j++) {
            std::cout << valuesToPrint[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

int main() {
    std::vector<int> vals{1, 2, 3, 4, 5, 6 , 7};

    Node* root = GenerateTreeFromArray(vals, 0, vals.size());

    Print(root);
}


