#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2;
	while(cin >> str1 >> str2)
	{
		int len1 = str1.size(), len2 = str2.size(), index = 0;
		for(int i = 0; i < len1; i++)
		{
			if(str1[i] == str2[index])
				index++;
		}
		
		if(index == len2)
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
}