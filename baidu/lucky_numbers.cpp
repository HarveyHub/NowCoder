#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int change_radix(int n, int radix)
{
	int cnt = 0;
	// string str = "";
	while(n)
	{
		cnt += n % radix;
		// str.insert(0, 1, char('0' + n % radix));
		n = n / radix;
	}
	return  cnt;
}



int main()
{
	int n;
	while(cin >> n)
	{
		int cnt = 1;
		for(int i = 2; i <=n; i++)
		{
			if(change_radix(i, 2) == change_radix(i, 10))
				cnt ++;
		}
		cout << cnt << endl;	
	}
	
	return 0;
}