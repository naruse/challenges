/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no 
nodes with a value greater than X.

Return the number of good nodes in the binary tree.
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
public class CountGoodNodesInBinaryTree {
    

    public int GoodNodes(TreeNode root) {
        return IsGoodNode(root, root.val);
    }

    public int IsGoodNode(TreeNode node, int maxValSoFar) {
        if(node == null)
            return 0;
        int result = 0;

        if(node.val >= maxValSoFar)
            result = 1;
        
        result += IsGoodNode(node.left, Math.Max(node.val, maxValSoFar));
        result += IsGoodNode(node.right, Math.Max(node.val, maxValSoFar));

        return result;
    }
}