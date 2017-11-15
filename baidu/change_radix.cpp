#include<iostream>
#include<map>
#include<string>
#include<stdlib.h>
using namespace std;



string dec2radix(long long dec, int radix, map<int, char> radixs)
{
	string res;
	while(dec > 0)
	{
		res.insert(0, 1, radixs[dec % radix]);
		dec /= radix;
	}
	return res;
}

long long radix2dec(string s, int radix, map<char, int> radixd)
{
	long long res = 0;
	int len = s.size();
	for(int i = 0; i < len; i++)
	{
		res = res * radix + radixd[s[i]];
		// cout << radixd[s[i]] << " " << radix << " res:" << res << endl;
	}
	return res;

}

int main()
{
	int radix_s, radix_d;
	string str;
	map<int, char> radixs;
	map<char, int> radixd;
	for(int i = 0; i <= 9; i++)
	{
		radixs[i] = char(i + '0');
		radixd[i+'0'] = i;
	}
	for(char i = 'a', j = 10; i <= 'z'; i++, j++)
	{
		radixs[j] = i;
		radixd[i] = j;
	}
	for(char i = 'A', j = 36; i <= 'Z'; i++, j++)
	{
		radixs[j] = i;
		radixd[i] = j;
	}
	
	// for(auto its = radixs.begin(); its != radixs.end(); its++)
	// {
		// cout << its->first << "\t" << its->second << endl;
	// }
	// for(auto itd = radixd.begin(); itd != radixd.end(); itd++)
		// cout << itd->first << "\t" << itd->second << endl;
	// cout << dec2radix(100, 18, radixs) << endl;
	// cout << radix2dec("100", 10, radixd) << endl;
	// while(cin >> radix_s >> radix_d >> str)
	// {
		// long long dec = radix2dec(str, radix_s, radixd);
		// string des = dec2radix(dec, radix_d, radixs);
		// cout << des << endl;
	// }

	string str_input;
	cin >> str_input;
	cout << str_input << endl;
	return 0;
}