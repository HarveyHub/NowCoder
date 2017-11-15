#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int line_num;
	cin >> line_num;
	int grass_cnt;
	while(cin >> grass_cnt)
	{
		int k = 0;
		bool flag = true;
		for(; pow(4, k) < grass_cnt; ++k);
		if(pow(4, k) == grass_cnt)
		{
			cout << "niuniu" << endl;
		}
			
	}
}