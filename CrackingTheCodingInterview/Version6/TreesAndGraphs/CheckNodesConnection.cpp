// Given a directed graph, design an algorithm to find out whether ther is a
// route between two nodes.

//do a BFS Search and store visited nodes on a set

#include <vector>
#include <set>
#include <queue>

using namespace::std;

class Node {
public:
    int data;
    vector<Node*> adjNodes;
    Node(int i) { data = i; }
};

set<Node*> visitedNodes;
vector<Node*> path;

void BFS(Node* startNode, Node* candidateNode) {
    queue<Node*> q;
    q.push(startNode);
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();

        //do whatever with the current node
        if(current == candidateNode)
            return true;

        if(visitedNodes.find(current) == visitedNodes.end()) {//WeHavntVisitedThisNode
            visitedNodes.insert(current);
            for(int i = 0; i < current->adjNodes.size(); i++) {
                q.push(current->adjNodes[i]);

            }
        }
    }
    return false;
}

int main() {

}
