#include<iostream>
// #include<unordered_map>
// #include<algorithm>
#include<string>
using namespace std;



int main()
{
    string str;
	while(getline(cin, str))
	{
		string res = "";
		int len = str.size();
		for(int i = 0; i < len; i++)
		{
			if(res.find(str[i]) == res.npos)
			{
				res += str[i];
			}
			
		}
		cout << res << endl;
	}
	return 0;
}