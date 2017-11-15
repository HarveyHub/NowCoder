/*
小易非常喜欢拥有以下性质的数列:
1、数列的长度为n
2、数列中的每个数都在1到k之间(包括1和k)
3、对于位置相邻的两个数A和B(A在B前),都满足(A <= B)或(A mod B != 0)(满足其一即可)
例如,当n = 4, k = 7
那么{1,7,7,2},它的长度是4,所有数字也在1到7范围内,并且满足第三条性质,所以小易是喜欢这个数列的
但是小易不喜欢{4,4,4,2}这个数列。小易给出n和k,希望你能帮他求出有多少个是他会喜欢的数列。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

struct Complexs
{
	float* reals;
	float* imags;
};
struct Complex
{
	float real;
	float imag;
}
int main()
{
    int n, k, mod = 1000000007;
    while(cin >> n >> k)
    {
		vector<int> row(k+1, 0);
        vector<vector<int>> s(n+1, row);
        s[0][1] = 1;
		int i, j, sum;
		for(i = 1; i <= n; i++)
		{
			sum = 0;
			for(j = 1; j <= k; j++)
			{
				sum = (sum + s[i-1][j]) % mod ;
			}
			for(j = 1; j <= k; j++)
			{
				int invaild = 0;
				int p = 2;
				while(p * j <= k)
				{
					invaild = (invaild + s[i-1][p*j]) % mod;
					p ++;
				}
				s[i][j] = (sum - invaild + mod) % mod;
				
			}
		}
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= k; j++)
				cout << "s["<< i << "][" << j << "]:" << s[i][j] << endl;
		}
		sum = 0;
		for(i = 1; i <= k; i++)
		{
			sum = (sum + s[n][i]) % mod;
		}
		
		cout << sum << endl;
		
		

    }
    return 0;
}