#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while(cin >> str)
	{
		int len = str.size(), max_len = 0, cnt = 1, end = 0;
		for(int i = 0; i < len - 1; i++)
		{
			if(isdigit(str[i]))
			{
				if(isdigit(str[i + 1]))
				{
					cnt ++;
				}
				else
				{
					if(cnt > max_len)
					{
						max_len = cnt;
						end = i + 1;
					}
					cnt = 1;
					
				}
			}
		}
		if(cnt > max_len)
		{
			end = len;
			cout << str.substr(end - cnt, cnt) << endl;
			cout << cnt << endl;
		}
		else
		{
			cout << str.substr(end - max_len, max_len) << endl;
			cout << max_len << endl;
		}
	}
	return 0;
}