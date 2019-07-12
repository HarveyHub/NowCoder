#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


string str_sub_equ(const string &str1, const string &str2)
{
	int len = str1.size(), borrow = 0, tmp;
	string result = "";
	for(int i = len - 1; i >= 0; i--)
	{
		tmp = str1[i] - str2[i] + borrow;
		if(tmp >= 0)
		{
			borrow = 0;
			result += tmp + '0' ;
		}
		else
		{
			borrow = -1;
			result += tmp + 10 + '0';
		}
	}
	
	return result;
}

string str_sub(string &str1, string &str2)
{
	int len1 = str1.size(), len2 = str2.size(), borrow = 0, tmp = 0;
	string result = "";
	if(len1 < len2)
	{ 
		str1.insert(0, (len2-len1), '0');
	}
	else
	{
		str2.insert(0, len1 - len2, '0');
		
	}
	if(str1.compare(str2) > 0)
		result = str_sub_equ(str1, str2);
	else   
	{
		result = str_sub_equ(str2, str1);
		result += "-";
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	string str1 = "98529626";
	string str2 = "5656125614151";
	
	cout << str_sub(str1, str2) << endl;
	cout << str_sub(str2, str1) << endl;
	
	
}