#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n = 10;
	vector<int> flags(n + 1, 1);
	int killed = 0;
	while(killed < n-1)
	{
		
		int j = 1;
		for(int i = 1; i <= n; i++)
		{
			if(flags[i] == 1)
			{
				if(j % 2 == 1)
				{
					flags[i] = 0;
					killed++;
				}
				j++;
			}
		}
		
		for(int i = 1; i <= n; i++)
		{
			if(flags[i] == 1)
			{
				cout << "flags[" << i << "] is 1" << endl;
			}
		}
		cout << endl;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(flags[i] == 1)
			cout << i << endl;
	}
	return 0;
}