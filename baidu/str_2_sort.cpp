#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool compare_len(string &s1, string &s2)
{
	return s1.size() < s2.size();
}

int main()
{
	int n;
	while(cin >> n)
	{
		vector<string> strs(n, string("")), str_lex, str_len;
		bool f_lex = true, f_len = true;
		for(int i = 0; i < n; i++)
		{
			cin >> strs[i];
		}
		str_len = str_lex = strs;
		sort(str_lex.begin(), str_lex.end());
		sort(str_len.begin(), str_len.end(), compare_len);
		for(int i = 0;i < n; i++)
		{
			if(str_len[i] != strs[i])
			{
				f_len = false;
				break;
			}
		}
		for(int i = 0; i < n; i++)
		{
			if(str_lex[i] != strs[i])
			{
				f_lex = false;
				break;
			}
		}
		if(f_len && f_lex)
			cout << "both" <<endl;
		else if(f_len)
			cout << "lenghts" << endl;
		else if(f_lex)
			cout << "lexicographically" << endl;
		else 
			cout << "none" << endl;
		
	}
	
	return 0;
}