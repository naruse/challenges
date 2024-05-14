/**
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the 
longest path from the root node down to the farthest leaf node.

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
public class MaxDepthOfATree {

    public int MaxDepth(TreeNode root) {
        int depth = 0;
        if(root != null) {
            depth++;
            int depthLeft = MaxDepth(root.left);
            int depthRight = MaxDepth(root.right);
            depth = depth + (depthLeft > depthRight ? depthLeft : depthRight);
        }
        return depth;
    }
}