/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
 p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a 
 descendant of itself).”

 PALABRA CLAVE: BINARY SEARCH TREE
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
//PALABRA CLAVE: BINARY SEARCH TREE -- el order es Log n y en memory order es O(1) porque no usamos nada mas
//simplemente navegamos a traves del arbol mirando si vamos para la izq o la der
public class LowestCommonAncestor {
    public TreeNode Solution(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode currNode = root;

        while(currNode != null) {
            if(p.val < currNode.val && q.val < currNode.val)
                currNode = currNode.left;
            else if(p.val > currNode.val && q.val > currNode.val)
                currNode = currNode.right;
            else
                return currNode;
        }
        return null;
    }
}