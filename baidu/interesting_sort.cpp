#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	freopen("interesting_sort.txt", "r", stdin);
	int N;
	while(cin >> N)
	{
		int cnt = 0, index = N;
		vector<int> nums(N, 0);
		map<int, int> v_i;
		for(int i = 0; i < N; i++)
		{
			cin >> nums[i];
			v_i[nums[i]] = i;
		}
		sort(nums.begin(), nums.end());
		for(int i = 0; i < N-1; i++)
		{
			if(v_i[nums[i]] > v_i[nums[i+1]])
			{
				v_i[nums[i+1]] = index++;
				cnt ++;
			}
		}
		
		
		cout << cnt << endl;
	}
	return 0;
}