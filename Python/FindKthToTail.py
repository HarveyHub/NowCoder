# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
		ahead = head;
		behind = head;
		for i in range(k-1):
			if(ahead.next != None):
				ahead = ahead.next;
			else:
				return ListNode({});
				
		while(ahead.next != None):
			ahead = ahead.next;
			behind = behind.next;
		
		return behind;
		
if __name__ == "__main__":
	n = 0;
	head = ListNode(n);
	s = head;
	while(n):
		n -= 1;
		node = ListNode(n);
		s.next = node;
		s = s.next;
		
	s = head;
	while(s != None):
		print(s.val),;
		s = s.next;
	print("");
	
	sol = Solution();
	res = sol.FindKthToTail(head, 100);
	
	print(res.val);
		