/*
https://leetcode.com/problems/balanced-binary-tree/description/

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node 
never differs by more than one.
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
public class Solution {
    bool isBalanced = true;
    public bool IsBalanced(TreeNode root) {
        if(root == null)
            return true;
        
        CalculateDepth(root);

        return isBalanced;
    }

    int CalculateDepth(TreeNode node) {
        if(node == null)
            return 0;

            
        int depthLeft = CalculateDepth(node.left);
        int depthRight = CalculateDepth(node.right);

        if(Math.Abs(depthLeft - depthRight) > 1)
            isBalanced = false;

        return Math.Max(depthLeft,depthRight) + 1;
    }
}