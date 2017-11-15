#include<iostream>
#include<sstream>
#include<string>
using namespace std;

bool is_primer(int &x)
{
	if(x < 2)
		return false;
	if(x == 2)
		return true;
	for(int i = 2; i*i <= x; i++)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}

bool is_plalindrome(string &str)
{
	int len = str.size();
	for(int i = 0; i < len/2; i++)
	{
		if(str[i] != str[len - 1 -i])
			return false;
	}
	return true;
}

template <typename T>
void val2str(const T &val, std::string &str)
{
	std::stringstream ss;
	ss << val;
	str = ss.str();
}

int main()
{
	int s, e;
	while(cin >> s >> e)
	{
		int cnt = 0;
		for(int i = s; i <= e; i++)
		{
			
			if(is_primer(i))
			{
				 string str_num;
				 val2str(i, str_num);
				 if(is_plalindrome(str_num))
				 {
					 cnt++;
				 }
			}
		}
		cout << cnt << endl;
	}
	return 0;
}