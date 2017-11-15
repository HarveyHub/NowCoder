/*
小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
1、将a_i放入b序列的末尾
2、逆置b序列
小易需要你计算输出操作n次之后的b序列
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;



int main()
{
    int n;
	// int a = 3, b = 4;
	// cin >> a >> b;
	// int c[a][b] = {};
	// for(int i = 0; i < a; i++)
	// {
		// for(int j = 0; j < b; j++)
			// cout << c[i][j] << " ";
		// cout << endl;
	// }
	// return 0;
	
    while(cin >> n)
    {
        vector<int> nums(n, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
		
		if(n == 1)
		{
			cout << nums[0];
			continue;
		}

        for(int i = n-1; i >= 0; i -= 2)
            cout << nums[i] << " ";
        for(int i = 0; i < n - 3; i += 2)
            cout << nums[i] << " ";
        cout << nums[n-2];

    }
    return 0;
}