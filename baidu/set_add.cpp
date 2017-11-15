#include<iostream>
#include<set>
#include<algorithm>
using namespace std;




int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		set<int> result;
		int tmp;
		for(int i = 0; i < m+n; i++)
		{
			cin >> tmp;
			result.insert(tmp);
		}
		auto it = result.begin();
		for(size_t i = 0; i < result.size() - 1; i++, it++)
		{
			cout << *it << " ";
		}
		cout << *it << endl;
	}
	
	return 0;
}