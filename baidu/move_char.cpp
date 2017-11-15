#include<iostream>
#include<string>
// #include<cstring>
#include<stdio.h>

using namespace std;

int main()
{
	//freopen("interesting_num.txt", "r", stdin);
	string str;
	while(cin >> str)
	{
		int len = str.size();
		
		for(int i = 0; i < len; i++)
		{
			if(str[i] != toupper(str[i]))
			{
				cout << str[i];
			}
		}
		for(int i = 0; i < len; i++)
		{
			if(str[i] == toupper(str[i]))
			{
				cout << str[i];
			}
		}
		cout << endl;
		
	}
	
	return 0;
}