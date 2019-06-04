// Question Link ---> https://leetcode.com/problems/add-two-numbers/submissions/

package main;

// Definition for singly-linked list.
class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}

public class main{
	public static void main(String args[]) {
		Solution obj = new Solution();
		ListNode l1 = new ListNode(9);
		
		ListNode l2 = new ListNode(1);
		l2.next = new ListNode(9);
		l2.next.next = new ListNode(9);
		obj.printList(obj.addTwoNumbers(l1, l2));
	}
}

class Solution {
	ListNode result = null;
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode l1_walk = l1;
		ListNode l2_walk = l2;
		int carry = 0, leftMostDigit = 0;
		leftMostDigit = (l1_walk.val + l2_walk.val)%10;
		carry = (l1_walk.val + l2_walk.val)/10;
		append(leftMostDigit);
		System.out.println("n1: " + l1_walk.val + " n2: " + l2_walk.val + " carry: " + carry);
		l1_walk = l1_walk.next;
		l2_walk = l2_walk.next;
		while(l1_walk != null || l2_walk != null) {
			int n1 = (l1_walk != null) ? l1_walk.val : 0;
			int n2 = (l2_walk != null) ? l2_walk.val : 0;
			leftMostDigit = (n1 + n2 + carry)%10;
			System.out.println("n1: " + n1 + " n2: " + n2 + " carry: " + carry);
			append(leftMostDigit);
			carry = (n1 + n2+ carry)/10;
			if(l1_walk != null) l1_walk = l1_walk.next;
			if(l2_walk != null) l2_walk = l2_walk.next;
		}
		if(carry > 0) {
			append(carry);
		}
		return result;
	}
	
	void append(int num) {
		if(result == null) {
			result = new ListNode(num);
		}
		else {
			ListNode walk = result;
			while(walk.next != null) {
				walk = walk.next;
			}
			walk.next = new ListNode(num);
		}
	}
	
	void printList(ListNode list) {
		ListNode walk = list;
		while(walk != null) {
			System.out.print(walk.val + " ");
			walk = walk.next;
		}
	}
}