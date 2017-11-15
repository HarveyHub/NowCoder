#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n_chocolate, n_child;
	freopen("chocolate.txt", "r", stdin);
	while(cin >> n_child)
	{
		int cnt = 0;
		vector<int> v_child(n_child, 0);
		for(int i = 0; i < n_child; i++)
		{
			cin >> v_child[i];
		}
		cin >> n_chocolate;
		vector<int> v_chocolate(n_chocolate, 0);
		for(int i = 0; i < n_chocolate; i++)
		{
			cin >> v_chocolate[i];
		}
		
		sort(v_child.begin(), v_child.end());
		sort(v_chocolate.begin(), v_chocolate.end());
		for(int i = 0, j = 0; i < n_chocolate && j < n_child; i++)
		{
			//cout << "cho: " << v_chocolate[i] << "\tchild: " << v_child[j]<<endl;
			if(v_chocolate[i] >= v_child[j])
			{
				cnt ++;
				j++;
			}
		}
		
		cout << cnt << endl;
	}
}