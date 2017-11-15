#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool is_lucky(vector<int> v)
{
	int len = v.size();
	if(len < 2)
		return false;
	long sum = 0, mul = 1;
	for(int i = 0; i < len; i ++)
	{
		sum += v[i];
		mul *= v[i];
	}
	if(sum > mul)
		return true;
	else 
		return false;
}

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> nums(n, 0);
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end());
		while(nums.size() > 1)
		{
			if(is_lucky(nums))
				cnt ++;
			nums.pop_back();
		}
		cout << cnt << endl;
	}
	return 0;
}