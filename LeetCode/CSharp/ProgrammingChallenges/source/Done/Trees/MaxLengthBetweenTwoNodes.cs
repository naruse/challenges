/*
https://leetcode.com/problems/diameter-of-binary-tree/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/

// Esta solucion es O(n2) que yo hice
/*
 Solucion O(n)
 public class Solution {
    int result = -1;
    public int DiameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return result;
    }

    int dfs(TreeNode current){
        if ( current == null){
            return -1;
        }
        int left = dfs(current.left) + 1;
        int right = dfs(current.right) + 1;
        result = Math.Max(result, (left+right));
        return Math.Max(left, right);
    }
} // pero como super rebuscada nose...
*/

public class MaxLengthBetweenTwoNodes {

    int maxDiameter = 0;
    public int DiameterOfBinaryTree(TreeNode root) {

        Queue<TreeNode> q = new();
        q.Enqueue(root);

        while(q.Count != 0) {
            var currentNode = q.Dequeue();
            int currDiameter = MaxDepth(currentNode.left) + MaxDepth(currentNode.right);

            maxDiameter = maxDiameter < currDiameter ? currDiameter : maxDiameter;

            if(currentNode.left != null)
                q.Enqueue(currentNode.left);
            if(currentNode.right != null)
                q.Enqueue(currentNode.right);

        }
        return maxDiameter;
    }

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