//Implement a fn to check if a binary tree is balanced.


//APPROACH:
//We check for the height on the left and right subtree and return if bigger
//than 1.


bool IsTreeBalanced(Node* n) {
    if(ModifiedGetHeightChecker(n) == -1)
        return false;
    else
        return true;
}


/*int GetTreeHeight(Node* n) {
    if(n == nullptr)
        return 0;
    int heightL = GetTreeHeight(n->left);
    int heightR = GetTreeHeight(n->right);
    return Max(heightL, heightR) +1;
}*/


//modified GetHeight checker.
//return -1 if the tree is unbalanced.
int ModifiedGetHeightChecker(Node* n) {
    if(n == nullptr)
        return 0;
    int heightL = ModifiedGetHeightChecker(n->left);
    int heightR = ModifiedGetHeightChecker(n->right);

    if(heightL == -1)
        return -1;
    if(heightR == -1)
        return -1;
    if(abs(heightL-heightR) > 1)
        return -1;
    return max(heightL, heightR) + 1;
}


int GetTreeHeight(Node* n) {
    if(n == nullptr)
        return 0;
    int heightL = GetTreeHeight(n->left);
    int heightR = GetTreeHeight(n->right);
    return Max(heightL, heightR) +1;
}
