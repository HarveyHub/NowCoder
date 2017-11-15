#include <iostream>
#include <cstdlib>
using namespace std;


struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL)
    {
    }
};
class Solution
{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* start;
        if(pHead1 == NULL && pHead2 == NULL)
            return NULL;
        else if(pHead1 == NULL)
            return pHead2;
        else if(pHead2 == NULL)
            return pHead1;
        else
        {
            if(pHead1->val < pHead2->val)
            {
                start = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                start = pHead2;
                pHead2 = pHead2->next;
            }
            ListNode* p = start;
            while(pHead1 != NULL && pHead2 != NULL)
            {
                if(pHead1->val < pHead2->val)
                {
                    p->next = pHead1;
                    pHead1 = pHead1->next;
                }
                else
                {
                    p->next = pHead2;
                    pHead2 = pHead2->next;
                }
                p = p->next;
            }
            while(pHead1 != NULL)
            {
                p->next = pHead1;
                pHead1 = pHead1->next;
                p = p->next;
            }
            while(pHead2 != NULL)
            {
                p->next = pHead2;
                pHead2 = pHead2->next;
                p = p->next;
            }
            return start;

        }
    }
};

int main()
{
    ListNode* p1 = new ListNode(5);
    ListNode* p2 = new ListNode(8);
    ListNode *p = p1, *s = p2;
    for(int i = 0; i < 5; i++)
    {
        ListNode* n = new ListNode(i*2 + 1);
        p->next = n;
        p = n;
    }
    for(int i = 0; i < 8; i++)
    {
        ListNode* n = new ListNode(i*2);
        s->next = n;
        s = n;
    }
	Solution solution;
	s = solution.Merge(p1->next, p2->next);
	while(s != NULL)
	{
		cout << s->val << " ";
		s = s->next;
	}
	cout << endl;
	
    return 0;

}