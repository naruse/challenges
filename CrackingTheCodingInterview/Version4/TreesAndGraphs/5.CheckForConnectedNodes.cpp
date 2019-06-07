/*
  Given a directed graph, design an algorithm to find out wether there is a
  route between 2 nodes.
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace::std;

unordered_set<int> visitedNodes;

class Node {
private:
    static int objId;
public:
    int data;
    int id;
    vector<Node*> adjNodes;

    Node(int d) {
        data = d;
        objId++;
        id = objId;
        cout << "Created node id: " << id << endl;
    }
    void CreateConnection(Node* n) {
        cout << id << "->" << n->id << endl;
        adjNodes.push_back(n);
    }
};

bool DFSConnection(Node* from, int const idTo) {
    if(from == nullptr) return false;
    if(visitedNodes.find(from->id) != visitedNodes.end())//if visited nodes
        return false;
    visitedNodes.insert(from->id);
    if(from->id == idTo) return true;

    bool foundConnection = false;
    for(int i = 0; i < from->adjNodes.size(); i++) {
        foundConnection = DFSConnection(from->adjNodes[i], idTo);
        if(foundConnection) {
            cout << from->adjNodes[i]->id << "->";
            return true;
        }
    }
    return false;
}

int Node::objId = 0;
int main(int argc, char* argv[]) {
    cout << "Creating nodes:" << endl;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    cout << "Creating connections:" << endl;
    node1->CreateConnection(node2);

    node2->CreateConnection(node3);

    node3->CreateConnection(node1);
    node3->CreateConnection(node4);

    node4->CreateConnection(node5);

    node5->CreateConnection(node4);
    node5->CreateConnection(node3);
    node5->CreateConnection(node1);

    node6->CreateConnection(node5);

    cout << "Check connection" << endl;
    bool found = DFSConnection(node5, 5);
    cout << "Found connection: " << (found?"true":"false") << endl;
    cout << endl;
}
