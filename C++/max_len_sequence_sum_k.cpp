/*
序列中任意个连续的元素组成的子序列称为该序列的子串。
现在给你一个序列P和一个整数K，询问元素和是K的倍数的子串的最大长度。
比如序列【1,2,3,4,5】，给定的整数K为 5，其中满足条件的子串为{5}、{2,3}、{1,2,3,4}、{1,2,3,4,5}，
那么答案就为 5，因为最长的子串为{1,2,3,4,5}；如果满足条件的子串不存在，就输出 0。
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int sum(vector<int> &ns, int s, int e)
{
	int res = 0;
	for(int i = s; i <= e; i++)
	{
		res += ns[i];
	}
	return res;
}

int main()
{
	freopen("max_len_sequence_sum_k.txt", "r", stdin);
	int n;
	while(cin >> n)
	{
		vector<int> nums(n, 0);
		for(int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		int max = 0, k;
		cin >> k;
		for(int i = 0; i < n; i++ )
		{
			int s = 0;
			for(int j = i; j < n; j++)
			{
				s += nums[j];
				if(s % k == 0)
				{
					cout << "sum: " << s << " i: " <<  i << " j: " << j<< endl;
					if(j - i + 1 > max)
						max = j - i + 1;
				}
			}
		}
		
		cout << max << endl;
	}
	return 0;
}
