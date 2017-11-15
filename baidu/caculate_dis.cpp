#include<iostream>
#include<vector>
using namespace std;

struct S
{
	S(double h):height(h), dis(0), cnt(0){};
	double height;
	double dis;
	int cnt;
};
void dis(S &s)
{
	if(s.height < 1)
	{
		s.height = 0;
		s.dis += 1;
		return ;
	}
	s.dis += s.height + s.height / 2;
	s.cnt ++;
	cout << "cnt: " << s.cnt << " dis: " << s.dis << " height: " << s.height << endl;
	s.height /= 2;
	
	return dis(s);
}

int main()
{
	int n;
	// while(cin >> n)
	// {
		// vector<double> nums(n, 0);
		// unsigned sum = 0;
		// for(int i = 0; i < n; i++)
		// {
			// cin >> nums[i];
			// S s(nums[i]);
			// dis(s);
			// cout << "cnt: " << s.cnt << " dis: " << s.dis << " height: " << s.height << endl;
			// sum += s.dis;
		// }
		// cout << sum << endl;
	// }
	cout << char(25) << endl;
	
	return 0;
}