#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> FindContinuousSequence(int sum)
{
    vector<vector<int>> res;
    if(sum < 3)
        return res;
    int small = 1, big = 2;
    while(small < (1+sum)/2)
    {
        cout << "small: " << small << " big: " << big << endl;
        if(sum == (small+big)*(big-small+1)/2)
        {
            vector<int> v;
            for(int i = small; i <= big; i++)
                v.push_back(i);

            res.push_back(v);
            small++;
            big++;
        }
        else if(sum > (small+big)*(big-small+1)/2)
        {
            big++;
        }
        else
        {
            small++;
        }
    }
    return res;

}

vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
    vector<int> res;
    int len = array.size();
    if(len < 2)
        return res;
    int i = 0,j = len - 1, s;
    while(i < j)
    {
        s = array[i] + array[j];
        if(s == sum)
        {
            res.push_back(array[i]);
            res.push_back(array[j]);
        }
        else if( s < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return res;
}

string LeftRotateString(string str, int n)
{
	int len = str.size();
	string result;
	if(len < 2)
		return str;
	if(len < n)
	{
		int mod = n % len;
		return str.substr(mod, len-1) + str.substr(0, mod);
	}
	return str.substr(n, len - 1) + str.substr(0, n);

}

int main()
{
    int sum = 100;
    // vector<vector<int>> vs = FindContinuousSequence(sum);
    // for(auto v : vs)
    // {
    // for(auto item : v)
    // cout << item << " ";
    // cout << endl;
    // }
	
	cout << LeftRotateString("ab", 3) << endl;
	cout << LeftRotateString("abcXYZ", 3) << endl;
    return 0;
}