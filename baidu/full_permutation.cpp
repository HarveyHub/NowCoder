#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

void full_permutation(vector<int> v, size_t index)
{
	if(index >= v.size())
	{
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
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
	int n = 4;
	vector<int> nums(n, 0);
	for(int i = 0; i < n; i++)
	{
		nums[i] = i;
	}
	
	full_permutation(nums, 0);
	
	return 0;
}