/*
https://leetcode.com/problems/subtree-of-another-tree/description/
We just do a BFS and check for each node if node n is the same tree as subroot
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
public class SubtreeOfAnotherTree {
    Queue<TreeNode> q = new();
    public bool IsSubtree(TreeNode root, TreeNode subRoot) {
        q.Enqueue(root);

        while(q.Count != 0) {
            TreeNode currNode = q.Dequeue();

            if(SameTree(currNode, subRoot))
                return true;

            if(currNode.left != null)
                q.Enqueue(currNode.left);
            if(currNode.right != null)
                q.Enqueue(currNode.right);
        }
        return false;
    }

    bool SameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null)
            return true;

        if(p == null || q == null)
            return false;

        if(p.val != q.val)
            return false;

        return (SameTree(p.left, q.left) && SameTree(p.right, q.right));
    }
}