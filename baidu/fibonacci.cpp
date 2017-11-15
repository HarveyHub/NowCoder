#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		int n1 = 1, n2 = 0, cur = 0;
		int min_step = 0;
		for(int i = 0; cur < n; i++)
		{
			cur = n1 + n2;
			n2 = n1;
			n1 = cur;
			
		}
		// cout << "cur: " << cur << endl;
		min_step = min(abs(cur - n), abs(n2 - n));
		cout << min_step << endl;
		
	}
	return 0;
}