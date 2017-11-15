#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        
        double sum = 0;
        for(int i = 0; i < m; i++)
        {
            sum += n;
            n = sqrt(n * 1.0);
        }
        cout << setiosflags(ios::fixed);
        cout << sum << endl;
    }
    return 0;
}