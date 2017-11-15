#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		string res;
		while(n)
		{
			if(n % 2)
			{
				n = (n - 1) / 2;
				res.insert(0, 1, '1');
			}
			else
			{
				n = (n - 2) / 2;
				res.insert(0, 1, '2');
			}
		}
		
		cout << res << endl;
	}
	return 0;
}