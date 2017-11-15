#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	while(cin >> str)
	{
		bool negative = false;
		int result = 0;
		if(str[0] == '-')
		{
			negative = true;
			cout << str.size() - 1 << endl;
			cout << "-";
		}
		else
		{
			cout << str.size() << endl;
			str.insert(0, 1, '#');
		}
		int len = str.size();
		for(int i = 1; i < len - 1; i++)
		{
			cout << str[i] << " ";
		}
		cout << str[len - 1] << endl;
		reverse(++str.begin(), str.end());
		if(negative)
			cout << "-";
		for(int i = 1; i < len ; i++)
		{
			result = result*10 + str[i] - '0';
		}
		cout << result << endl;
		
	}
	
	return 0;
}