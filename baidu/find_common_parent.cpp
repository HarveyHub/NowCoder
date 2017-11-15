#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
	int k;
	freopen("find_common_parent.txt", "r", stdin);
	while(cin >> k)
	{
		vector<int> nodes(3, 0);
		for(int i = 0; i < 3; i++)
			cin >> nodes[i];
		
		vector<vector<int>> roads;
		int max = pow(2, k) - 1;
		int root = (1 + max) >> 1;
		int id = 1;
		for(int i = 0; i < 3; i++)
		{
			id = 1;
			int cur = root;
			vector<int> r(1, cur);
			while(cur != nodes[i])
			{
				if(nodes[i] > cur)
				{
					if(cur >= root)
						cur = (r[id - 1] + 1 + r[id - 1]) >> 1;
					else 
						cur = (r[id - 1] + 1 + root) >> 1;
				}
				else if(nodes[i] < cur)
				{
					if(cur >= root)
						cur = (r[id - 1] + root) >> 1;
					else 
						cur = (r[id - 1] + 1) >> 1;
				}
				cout << cur << " ";
				r.push_back(cur);
				id ++;
			}
			cout << endl;
			roads.push_back(r);
			
		}
		
		// for(auto v : roads)
		// {
			// for(auto i : v)
				// cout << i << " ";
			// cout << endl;
		// }
		int res = root;
		for(int i = 1; i < id; i++)
		{
			if(roads[0][i] == roads[1][i] && roads[1][i] == roads[2][i])
			{
				res = roads[0][i];
			}
			else
				break;
		}
		cout << res << endl;
		
	}
	return 0;
}