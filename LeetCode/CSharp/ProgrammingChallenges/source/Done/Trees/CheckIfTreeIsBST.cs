/*
https://leetcode.com/problems/validate-binary-search-tree/
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

 // LA CLAVE ES QUE NECESITAMOS UN INTERVALO en el subtree
public class CheckIfTreeIsBST {
    public bool IsValidBST(TreeNode root) {
        return IsValidSubtree(root, long.MinValue, long.MaxValue);
    }

    bool IsValidSubtree(TreeNode node, long leftInterval, long rightInterval) {
        if(node == null)
            return true;

        if(!(node.val < rightInterval && node.val > leftInterval))
            return false;
            
        return IsValidSubtree(node.left, leftInterval, node.val) &&
               IsValidSubtree(node.right, node.val, rightInterval);
    }
}
