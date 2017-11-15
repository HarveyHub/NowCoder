/*
小易有一个长度为N的正整数数列A = {A[1], A[2], A[3]..., A[N]}。
牛博士给小易出了一个难题:
对数列A进行重新排列,使数列A满足所有的A[i] * A[i + 1](1 ≤ i ≤ N - 1)都是4的倍数。
小易现在需要判断一个数列是否可以重排之后满足牛博士的要求。 
输入描述:
输入的第一行为数列的个数t(1 ≤ t ≤ 10),
接下来每两行描述一个数列A,第一行为数列长度n(1 ≤ n ≤ 10^5)
第二行为n个正整数A[i](1 ≤ A[i] ≤ 10^9)


输出描述:
对于每个数列输出一行表示是否可以满足牛博士要求,如果可以输出Yes,否则输出No。

输入例子1:
2
3
1 10 100
4
1 2 3 4
*/

#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int main()
{
    freopen("4k.txt", "r", stdin);
    int group;
    cin >> group;

    for(int i = 0; i < group; i++)
    {
        int n, cnt_4 = 0, cnt_2 = 0;
        cin >> n;
        vector<int> nums(n, 0);
        for(int j = 0; j < n; j++)
        {
            cin >> nums[j];
            if(nums[j] % 4 == 0)
            {
                cnt_4 ++;
            }
            else if(nums[j] % 2 == 0)
            {
                cnt_2 ++;
            }
        }
        if(cnt_2 > 0)
        {
            n -= cnt_2;
            // cnt_4 -= 1;
        }
        // cout << "2: " << cnt_2 << "\t4: " << cnt_4 ;
        // cout << "\t n: " << n << endl;
        if(cnt_4 >= (n - cnt_4))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" <<endl;
    }

}