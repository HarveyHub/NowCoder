#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iterator>
using namespace std;

int main()
{
    int N;
	freopen("bear_go_home.txt", "r", stdin);
    while(cin>>N)
    {
        
        vector<int> positions(N, 0);
		int min_steps = 0, cur_steps = 0;
		
        for(int i = 0; i < N; i++)
        {
            cin >> positions[i];
        }
		
        for(int i = 1; i < N-1; i++)
		{
			vector<int> tmp = positions;
			tmp.erase(tmp.begin() + i);
			copy(tmp.begin(), tmp.end(), ostream_iterator<int>(cout, " "));
			cout << "\t|\t";
			cur_steps = 0;
			for(int j = 1; j < N-1; j++)
			{
				cur_steps += abs(tmp[j] - tmp[j-1]);
			}
			if(i == 1)
				min_steps = cur_steps;
			if(min_steps > cur_steps)
				min_steps = cur_steps;
		}
		cout << min_steps << endl;

    }

    return 0;

}