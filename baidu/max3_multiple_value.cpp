#include<iostream>
#include<stdio.h>
#include<vector>
#include<iterator>
#include<cstdlib>
using namespace std;

int main()
{
    freopen("input1.txt", "r", stdin);
    long long int n;
    while(cin >> n)
    {
        long long int result = 1;
        vector<long long int> nums(n, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        if(n <= 3)
        {
            for(int i = 0; i < n; i++)
            {
                result *= nums[i];
            }
			cout << result << endl;
			continue;
        }

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < n-1; j++)
            {
                if(nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }

        for(int i = 0; i < 3; i++)
        {
            for(int j = n-1; j > 0; j--)
            {
                if(nums[j] < nums[j-1])
                    swap(nums[j], nums[j-1]);
            }
        }
        // copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
        // cout << "\t";

        result = max(nums[0]*nums[1]*nums[n-1], nums[n-1] * nums[n-2] * nums[n-3]);

        cout<<  result << endl;


    }
}