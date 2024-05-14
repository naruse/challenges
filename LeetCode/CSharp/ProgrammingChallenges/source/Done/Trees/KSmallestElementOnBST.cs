/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed)
of all the values of the nodes in the tree.

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
public class KSmallestElementOnBST {
    List<int> values;
    public int KthSmallest(TreeNode root, int k) {
        values = new();
        if(root == null) 
            return -1;

        InOrderDFS(root);

        return values[k-1];        
    }

    void InOrderDFS(TreeNode node) {
        if(node == null)
            return;

        InOrderDFS(node.left);
        values.Add(node.val);//process
        InOrderDFS(node.right);
    }
}