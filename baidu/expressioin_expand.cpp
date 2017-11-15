#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
/*
abc3[a]
3[abc]
*/


int main()
{
	freopen("expressioin_expand.txt", "r", stdin);
    string str;
    while(cin >> str)
    {
		cout << "str:\t" << str << endl;
		vector<string> res;
		int index = str.size() - 1;
		res.push_back("");
		int count = 0;
		while(index >= 0)
		{
			
			if(str[index] == ']')
			{
				res.push_back("");
				count ++;
				index --;
				
			}
			else if(str[index] == '[')
			{
				index --;
				int time = 0;
				string t = "";
				while(index >= 0 && str[index] >= '0' && str[index] <= '9')
				{
					t.insert(0, string(1, str[index]));
					index--;
				}
				for(size_t j = 0; j < t.size(); j++)
					time = time*10 + t[j] - '0';
				cout << "time[" << count << "]:\t" << time << endl;
				string tmp = "";
				for(int j = 0; j < time; j++)
					tmp += res[count];
				cout << "tmp[" << count << "]: " << tmp << endl;
				res[count-1].insert(0, tmp);
				res[count] = "";
				count --;
			}
			else
			{
				res[count] = str[index]+ res[count];
				cout << "res["<< count <<"]:\t" << res[count] << endl;
				index --;
			}
				
		}
		
		cout << res[0] << endl;
    }

    return 0;
}