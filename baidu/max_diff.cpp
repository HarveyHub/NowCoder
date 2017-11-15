#include<iostream>
/*
小易老师是非常严厉的,它会要求所有学生在进入教室前都排成一列,并且他要求学生按照身高不递减的顺序排列。有一次,n个学生在列队的时候,小易老师正好去卫生间了。学生们终于有机会反击了,于是学生们决定来一次疯狂的队列,他们定义一个队列的疯狂值为每对相邻排列学生身高差的绝对值总和。由于按照身高顺序排列的队列的疯狂值是最小的,他们当然决定按照疯狂值最大的顺序来进行列队。现在给出n个学生的身高,请计算出这些学生列队的最大可能的疯狂值。小易老师回来一定会气得半死。
*/
#include<vector>
#include<algorithm>
#include<iterator>
#include<deque>
using namespace std;



int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> h(n, 0);
        deque<int> q;
        int diff = 0, cnt = 0, i = 0, j = n-1;
        for(int i = 0; i < n; i++)
            cin >> h[i];
        sort(h.begin(), h.end());
        while(i < j)
        {
            if(cnt % 2 == 0)
            {
                q.push_back(h[j--]);
                q.push_front(h[i++]);

            }
            else
            {
                q.push_back(h[i++]);
                q.push_front(h[j--]);
            }

            cnt ++;
        }
        if(i == j)
        {
            if(h[i] - q[n-2] > h[i] - q[0])
                q.push_back(h[i]);
            else
                q.push_front(h[i]);

        }

        for(int i = 0; i < n - 1; i++)
        {
            diff += abs(q[i] - q[i+1]);
        }
        copy(h.begin(), h.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        copy(q.begin(), q.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        cout << diff << endl;




    }
    return 0;
}