/*
https://leetcode.com/problems/same-tree/
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the
 same value.
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
public class CheckIfSameTree {
    public bool IsSameTree(TreeNode p, TreeNode q) {
        return IsTheSame(p,q);
    }

    bool IsTheSame(TreeNode node1, TreeNode node2) {
        if(node1 == null && node2 == null)
            return true;

        if(node1 == null || node2 == null)
            return false;
        if(node1.val != node2.val)
            return false;
        
        //we are checking both subtrees 
        return (IsTheSame(node1.left, node2.left) && IsTheSame(node1.right, node2.right));       
    }
}