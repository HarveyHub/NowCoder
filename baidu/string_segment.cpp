#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{
	string str;
	while(cin >> str)
	{
		int len = str.size(), cnt = 1;
		vector<pair<char, int>> statistics;
		for(int i = 0; i < len-1; i++)
		{
			if(str[i] == str[i+1])
			{
				cnt ++;
			}
			else 
			{
				statistics.push_back(make_pair(str[i], cnt));
				cnt = 1;
			}
		}
		if(statistics[statistics.size()-1].first != str[len-1])
		{
			statistics.push_back(make_pair(str[len-1], cnt));
		}
		cout<<setiosflags(ios::fixed);
		cout.precision(2); 
		cout << 1.0*len/statistics.size() << endl;
	}
	
	return 0;
}