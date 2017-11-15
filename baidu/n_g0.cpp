#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> nums(n, 0);
		for(int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			if(tmp >= 0)
			{
				nums[tmp] = 1;
			}
		}
		for(int i = 1; i < n; i++)
		{
			if(nums[i] == 0)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}