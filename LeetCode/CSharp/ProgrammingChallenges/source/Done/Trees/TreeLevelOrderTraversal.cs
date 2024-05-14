/*
https://leetcode.com/problems/binary-tree-level-order-traversal/

Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).

output [[3],[9,20],[15,7]]
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

 // LA CLAVE es guardar el nivel en una tupla
 // la solucion de neetcode es que el man usa un queue y saca por la izq
 //https://youtu.be/6ZnyEApgFYg
public class TreeLevelOrderTraversal {
    public IList<IList<int>> LevelOrder(TreeNode root) {
        List<List<int>> result = new List<List<int>>();
        if(root == null)
            return result.ToList<IList<int>>();

        Queue<(TreeNode, int)> q = new();
        q.Enqueue((root, 0));

        while(q.Count != 0) {
            (TreeNode, int) currNodeT = q.Dequeue();
            int currentLevel = currNodeT.Item2;
            // process
            if(result.Count == currentLevel)
                result.Add(new List<int>());

            result[currentLevel].Add(currNodeT.Item1.val);

            if(currNodeT.Item1.left != null)
                q.Enqueue((currNodeT.Item1.left,currentLevel+1));
            if(currNodeT.Item1.right != null)
                q.Enqueue((currNodeT.Item1.right,currentLevel+1));
        }

        return result.ToList<IList<int>>();
    }
}