/*
n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	while(cin >> n)
	{
		// cout << sqrt(n) << endl;
		vector<int> nums(n, 0);
		int sum = 0, cnt = 0, diff = 0;
		bool flag = true;
		for(int i = 0; i < n; i++)
		{
			cin >> nums[i];
			sum += nums[i];
		}
		float average = sum * 1.0 / n;
		if((int)average != sum/n)
		{
			flag = false;
		}
		for(int i = 0; i < n; i++)
		{
			diff = nums[i] - (int)average;
			if(diff > 0)
			{
				if(diff % 2)
				{
					flag = false;
				}
				else
					cnt += diff / 2;
			}
				
		}
		if(flag)
			cout << cnt << endl;
		else
			cout << -1 << endl;
		
	}
	
	return 0;
}