

using System.Resources;
using System.Security.Cryptography.X509Certificates;


/**
https://leetcode.com/problems/merge-k-sorted-lists/

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:[
  1->4->5,
  1->3->4,
  2->6]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 // hay un problema y es que se queda en un ciclo infinito sabra el putas porque -- prque se pierde una referncia pero no he podido dar bien que es .. es en MergeLists(l1,l2)
 */

 /*
test case
        
        ListNode node = new ListNode(1);
        node.next = new ListNode(2);
        node.next.next = new ListNode(3);
        node.next.next.next = new ListNode(4);
        node.next.next.next.next = new ListNode(5);
        node.next.next.next.next.next = null;

        ListNode[] lists = {node, node, node};
 */
public class MergeKSortedLists {
    public ListNode MergeKLists(ListNode[] lists) {
        if(lists == null || lists.Length == 0)
            return null;

        ListNode head = new ListNode();
        ListNode tipOfMergedList = head;
    
        List<ListNode> newLists = new List<ListNode>(lists);
        
        while(newLists.Count > 1) {
            List<ListNode> reducedList = new();
            for(int i = 0; i < newLists.Count; i+=2) {
                var l1 = newLists[i];
                var l2 = i+1 < newLists.Count ? newLists[i+1] : null;

                ListNode mergedListsHead = MergeTwoLists(l1, l2);

                reducedList.Add(mergedListsHead);
            }
            newLists = reducedList;
        }
        PrintList(newLists[0]);
        return newLists[0];
    }

    ListNode MergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        ListNode tipOfMergedLists = head;

        while(l1 != null && l2 != null) {
            if(l1.val < l2.val) {
                tipOfMergedLists.next = l1;
                l1 = l1.next;
            } else {
                tipOfMergedLists.next = l2;
                l2 = l2.next;
            }
            tipOfMergedLists = tipOfMergedLists.next;
        }

        if(l1 != null) {
            tipOfMergedLists.next = l1;
        } else if(l2!= null) {
            tipOfMergedLists.next = l2;
        }
        return head.next;
    }

    void PrintList(ListNode l, string message = "") {
        if(message != "")
            Console.WriteLine(message);
        ListNode node = l;
        while(node != null) {
            Console.Write(node.val + " -> ");
            node = node.next;
        }
        Console.WriteLine();
    }
}