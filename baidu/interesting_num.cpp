#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("interesting_num.txt", "r", stdin);
	int num, N;
	while(cin >> N)
	{
		int min_cnt = 0, max_cnt = 0, min_value;
		map<int, int> m_nums;
		vector<int> v_nums;
		for(int i = 0; i < N; i++)
		{
			cin >> num;
			if(m_nums.find(num) != m_nums.end())
			{
				m_nums[num]++;
			}
			else
			{
				v_nums.push_back(num);
				m_nums[num] = 1;
			}
		}
		sort(v_nums.begin(), v_nums.end());
		if(m_nums.size() == N)//the min substract value is 1
		{
			min_value = v_nums[1] - v_nums[0];
			for(int i = 1; i < N; i++)
			{
				if(v_nums[i] - v_nums[i-1] == min_value)
					min_cnt ++;
				else
				{
					if(min_value > v_nums[i] - v_nums[i-1])
					{
						min_cnt = 1;
						min_value = v_nums[i] - v_nums[i-1];
					}
				}
			}
			
		}
		else
		{
			for(auto it = m_nums.begin(); it != m_nums.end(); it++)
			{
				if(it->second > 1)
					min_cnt += it->second * (it->second - 1) / 2 ;
			}
		}
		
		max_cnt = m_nums[v_nums[m_nums.size()-1]]*m_nums[v_nums[0]];
		
		// for(auto it = m_nums.begin(); it != m_nums.end(); it++)
		// {
			// cout << it->first << "\t" << it->second << endl;
			
		// }
		cout << min_cnt << " " << max_cnt << endl;
		
	}
	
	return 0;
}