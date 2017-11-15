#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
	freopen("middle_position.txt", "r", stdin);
	int len;
	while(cin >> len)
	{
		int tmp;
		vector<int> nums;
		for(int i = 0; i < len; i++)
		{
			cin >> tmp;
			nums.push_back(tmp);
		}
		cin >> len;
		for(int i = 0; i < len; i++)
		{
			cin >> tmp;
			nums.push_back(tmp);
		}
		sort(nums.begin(), nums.end());
		
		len = nums.size();
		if(len % 2 == 0)
		{
			cout << (nums[len/2] + nums[len/2 -1]) * 0.5 << endl;
		}
		else
		{
			cout << nums[len/2] << endl;
		}
	}
	
	return 0;
	
}