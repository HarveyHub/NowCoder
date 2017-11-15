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
		for(; pow(4, k) < grass_cnt; ++k);
		cout << k << endl;
	}
}