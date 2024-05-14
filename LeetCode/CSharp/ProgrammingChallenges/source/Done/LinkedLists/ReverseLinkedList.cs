/**
https://leetcode.com/problems/reverse-linked-list/description/

Given the head of a singly linked list, reverse the list, and return the reversed list.

 * Definition for singly-linked list.
 */
 public class ListNode {
     public int val;
     public ListNode next;
     public ListNode(int val=0, ListNode next=null) {
         this.val = val;
         this.next = next;
     }
 }
 
public class LinkedListReversal {
    public ListNode ReverseList(ListNode head) {

        ListNode prev = null;
        ListNode current = head;
        while (current != null) {
            ListNode nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    /*
    esto fue lo que yo implemente
        Stack<ListNode> s = new();
        PrintList(head);
        if(head == null)
            return null;
        ListNode current = head;
        while(current != null) {   
            s.Push(current);
            current = current.next;
        }

        ListNode newHead = s.Pop();
        ListNode tipOfList = newHead;

        while(s.Count != 0) {      
            tipOfList.next = s.Pop();
            tipOfList = tipOfList.next;    
        }
        tipOfList.next = null; // esto es importante sino se queda en un ciclo infinito sabra el putas porque
        PrintList(newHead);

        return newHead;*/
    }

    void PrintList(ListNode n) {
        Console.WriteLine("List: ");
        var currNode = n;
        while(currNode != null) {
            Console.Write(currNode.val + " ");
            currNode = currNode.next;
        }
        Console.WriteLine();
    }
    
}