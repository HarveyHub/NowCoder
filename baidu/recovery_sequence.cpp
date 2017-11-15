#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stdio.h>
using namespace std;

vector<int> res;

int count_order(vector<int> &v)
{
    int len = v.size(), cnt = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            if(v[i] < v[j])
                cnt ++;
        }
    }
    return cnt;
}

void full_permutation(vector<int> v, size_t index)
{
    if(index >= v.size())
    {
        // copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        // cout << endl;
        for(size_t i = 0; i < v.size(); i++)
            res.push_back(v[i]);
    }
    for(size_t i = index; i < v.size(); i++)
    {
        swap(v[i], v[index]);
        full_permutation(v, i+1);
        swap(v[i], v[index]);
    }
}

int main()
{
    freopen("recovery_sequence.txt", "r", stdin);
    int n, k;
    while(cin >> n >> k)
    {
        res.clear();
        vector<int> nums(n, 0), undefined(n+1, 0), pos;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            undefined[i] = i;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if(nums[i] == 0)
                pos.push_back(i);
            undefined[nums[i]] = 0;
        }
    
		sort(undefined.begin(), undefined.end());
		auto it = undefined.begin();
		for(; *it ==0; it++);
		undefined.erase(undefined.begin(), it);
			
        copy(undefined.begin(), undefined.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        copy(pos.begin(), pos.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        full_permutation(undefined, 0);

        for(size_t j = 0; j < res.size() / pos.size(); j++)
        {
            for(size_t i = 0; i < pos.size(); i++)
            {
                nums[pos[i]] = res[j*pos.size() + i];
            }
			
                copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
                cout << endl;
            if(count_order(nums) == k)
            {
                cnt ++;
            }
        }
		cout << cnt << endl << endl;
    }
    return 0;
}