#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N, p;
    while(cin>>N)
    {
        set<int> prices;

        for(int i = 0; i < N; i++)
        {
            cin >> p;
            prices.insert(p);
        }
        if(prices.size()>2)
        {
			auto it = prices.begin();
			int i = 0;
			for(i = 0; i < 2; it++, i++);
			cout << *it << endl;
			
        }
        else
            cout << -1 << endl;
    }

    return 0;

}