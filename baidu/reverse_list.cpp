#include <iostream>
#include <cstdlib>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == NULL)
            return pHead;
		ListNode *p, *start, *tmp;
		start = new ListNode(0);
		start->next = pHead;
		p = pHead->next; 
		pHead->next = NULL;
		while(p != NULL)
		{
			tmp = p->next;
			p->next = start->next;
			start->next = p;
			p = tmp;
		}
		
		return start->next;

    }
};

int check_loop(ListNode* pHead)
{
	int loop_len = 1;
	ListNode *pStep1, *pStep2;
	pStep1 = pStep2 = pHead;
	while(pStep2 != NULL && pStep1 != pStep2)
	{
		pStep1 = pStep1->next;
		pStep2 = pStep2->next->next;
	}
	if(pStep2 != NULL)
	{
		pStep1 = pStep1->next;
		while(pStep1 != pStep2)
		{
			loop_len ++; 
		}
	}
	else
	{
		loop_len = 0;
	}
	
	return loop_len;
}


ListNode* find_value(ListNode* pHead, int value)
{
	ListNode* s = pHead;
	while(s != NULL)
	{
		
	}
}
int main()
{
	int len = 10;
	ListNode h = ListNode(len);
	ListNode* pHead = &h;
	ListNode* s = pHead;
	for(int i = 0; i < len; i++)
	{
		ListNode *n = new ListNode(i);
		s->next = n;
		s = s->next;
		
	}
	s = pHead->next;
	while(s != NULL)
	{
		cout << s->val << " ";
		s = s->next;
	}
	cout << endl;
	Solution res;
	s = pHead->next;
	ListNode* r = res.ReverseList(s);
	s = r;
	while(s != NULL)
	{
		cout << s->val << " ";
		s = s->next;
	}
	cout << endl;
	return 0;
	
}