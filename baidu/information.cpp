#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;

int main()
{
	string charactors;
	// freopen("information.txt", "r", stdin);
	while(cin >> charactors)
	{
		vector<string> res;
		int len = charactors.size(), cnt = 0, max = 0, idx = 0;
		for(int i = 0; i < len; i++)
		{
			if(charactors[i] == 'c')
			{
				string tmp_res(len, 'U');
				tmp_res[i] = 'I';
				if(i - 1 >= 0)
					tmp_res[i - 1] = 'I';
				if(i - 2 >= 0)
					tmp_res[i - 2] = 'I';
				if(i + 1 <= len - 1)
					tmp_res[i + 1] = 'I';
				if(i + 2 <= len - 1)
					tmp_res[i + 2] = 'I';
				
				//left to i - 1
				int tmp_cnt = 0;
				for(int j = i - 1; j > 1; j--)
				{
					if(charactors[j] == 'c')
					{
						tmp_res[j] = 'I';
						tmp_res[j - 1] = 'I';
						tmp_res[j - 2] = 'I';
						tmp_cnt = 0;
					}
					else
					{
						tmp_cnt ++;
						if(tmp_cnt == 2)
							break;
					}
				}
				// i + 1 to right
				tmp_cnt = 0;
				for(int j = i + 1; j < len - 2; j++)
				{
					if(charactors[j] == 'c')
					{
						tmp_res[j] = 'I';
						tmp_res[j + 1] = 'I';
						tmp_res[j + 2] = 'I';
						tmp_cnt = 0;
					}
					else
					{
						tmp_cnt ++;
						if(tmp_cnt == 2)
							break;
					}
				}
			
				res.push_back(tmp_res);
			}
		}
		
		for(size_t i = 0; i < res.size(); i++)
		{
			cnt = 0;
			for(int j = 0; j < len; j++)
			{
				if(res[i][j] == 'I')
					cnt++;
			}
			if(cnt > max)
			{
				max = cnt;
				idx = i;
			}
		}
		if(res.size() > 0)
			cout << res[idx] << endl;
		else
			cout << string(len, 'U') << endl;
		
	}
	
	return 0;
}