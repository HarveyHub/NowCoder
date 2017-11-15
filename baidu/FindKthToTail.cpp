#include<iostream>
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if(pListHead == NULL)
            return NULL;
        // if(k == 0)
        // return NULL;
        ListNode *p1, *p2;
        p1 = p2 = pListHead;
        unsigned step = 0;
        while(p1 != NULL && step < k)
        {
            p1 = p1->next;
            step ++;
        }
        if(step != k)
            return NULL;

        while(p1 != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;


    }
};

int main()
{
    int n = 10, k = 3;
    while(cin >> n >> k)
    {
        ListNode* p1 = new ListNode(n);
        ListNode *p = p1;
        for(int i = 0; i < n; i++)
        {
            ListNode* n = new ListNode(i + 1);
            p->next = n;
            p = n;
        }
        Solution solution;
        ListNode* r = solution.FindKthToTail(p1->next, k);
        if(r != NULL)
            cout << r->val << endl;
        else
            cout << "ERROR!" << endl;

    }
}