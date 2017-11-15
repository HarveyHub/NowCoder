/*
判断一个字符串中是否全部都是字母（大小写均可）或者数字，如果是的话输出偶数位的字符，如果不是输出Error
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while(cin >> str)
	{
		bool flag = true;
		string s;
		int len = str.size();
		if(len > 20)
			flag = false;
		
		for(int i = 0; i < len; i++)
		{
			if(!isalnum(str[i]))
			{
				flag = false;
				break;
			}
			if(i % 2 == 0)
				s.push_back(str[i]);
		}
		if(flag)
			cout << s << endl;
		else
			cout << "ERROR!" << endl;
		
	}
	return 0;
}