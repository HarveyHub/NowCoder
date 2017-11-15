#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;



int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> h(n, 0);
		for(int i = 0; i < n; i++)
		{
			cin >> h[i];
		}
		sort(h.begin(), h.end());
		int d = h[1] - h[0], i;
		for(i = 2; i < n; i++)
		{
			if(h[i] - h[i-1] != d)
			{
				cout << "Impossible" << endl;
				break;
			}
		}
		if(i == n)
			cout << "Possible" << endl;
		
			

    }
    return 0;
}