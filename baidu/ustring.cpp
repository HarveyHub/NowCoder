#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;



int main()
{
    string str;
	while(getline(cin, str))
	{
		vector<pair<char, int>> res;
		int len = str.size();
		for(int i = 0; i < len; i++)
		{
			bool flag = false;
			for(auto it = res.begin(); it != res.end(); it++)
			{
				if(it->first == str[i])
				{
					it->second ++;
					flag = true;
					break;
				}
			}
			if(!flag)
			{
				res.push_back(make_pair(str[i], 1));
			}
		}
		for(auto it = res.begin(); it != res.end(); it++)
		{
			cout << it->first;
		}
		cout << endl;
	}
	return 0;
}