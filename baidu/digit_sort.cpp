#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool compare(int a, int b)
{
    int tempa = a % 1000;
    int tempb = b % 1000;
    return tempa < tempb;
}

int getValue(vector<int> gifts, int n)
{
    // write code here
    map<int, int> res;
    for(int i = 0; i < n; i++)
    {
        if(res.find(gifts[i]) != res.end())
        {
            res[gifts[i]] ++;
        }
        else
            res[gifts[i]] = 1;
    }
    for(auto it = res.begin(); it != res.end(); it++)
    {
        if(it->second > n/2)
            return it->first;
    }
	
    return 0;

}

string dec2bin1(int n)
{
	string ret = "";
	while(n)
	{
		ret.insert(0, 1, '0' + n % 2);
		n >>= 1;
	}
	return ret;
}

string dec2bin(int n, int bit_width)
{
	string ret = "";
	for(int i = bit_width - 1; i >= 0; i--)
	{
		ret += ((n >> i) & 1) + '0';
	}
	return ret;
}

vector<string> getGray(int n)
{
    // write code here
	vector<string> res;
    int cnt = pow(2, n), gray_code;
    for(int i = 0; i < cnt; i++)
    {
        gray_code = (i >> 1) ^ i;
		cout << dec2bin(gray_code, n) << endl;
		res.push_back(dec2bin(gray_code, n));
    }
	return res;
}



int main()
{
	getGray(5);
    vector<int> nums;
    int value, k;
    while(cin>>value)
    {
        nums.push_back(value);
    }
    if(nums.size() > 0)
        k = nums[nums.size()-1];
    else
        return 1;
    sort(nums.begin(), --nums.end(), compare);
    for(size_t i=0; i<nums.size()-1; i++)
        cout << nums[i] << " ";
    cout << endl;
    cout << nums[k-1] << endl;
    return 0;
}
