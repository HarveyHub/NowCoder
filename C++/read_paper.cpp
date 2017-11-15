/*
在上小学的时候，我们经常碰到这样的事：考完试后老师懒得改试卷，于是让我们同桌相互交换试卷后为对方批改。但是后来老师发现这样作容易出现作弊，于是他想了一个新办法。老师将同学分成了 n 个组，其中编号为𝑖的组中有𝑠𝑖 个人。然后老师会按某种顺序依次访问这些组。
对于他访问的第一个组，他会将这组内的所有试卷都收走，放置在桌上；对于他后续访问的每一个组，首先他会从桌上的试卷最上方拿出该组对应人数数量的试卷，随机分配给该组每个人一张试卷让他们进行批改，而后再将这组学生自己考的试卷收走放置在桌面试卷的最下方。当他访问完所有的组后他会将桌面上剩余的所有试卷随机分配给他第一个访问的组的学生进行批改。
但他发现这种方法有时候也会出现问题：有可能在中途访问到某个组的时候桌面上的试卷不够分配给这组学生每人一张；也有可能最后会有学生分配到批改自己的试卷，而且这两种情况是否出现是与他访问每个组的顺序有关的。现在他想知道是否存在一种访问顺序能够使以上两种情况都不出现，顺利完成试卷批改呢？ 
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct PaperOnDes
{
	int num;
	deque<int> gs;
};

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> group(n, 0);
		for(int i = 0; i < n; i++)
		{
			cin >> group[i];
		}
		sort(group.begin(), group.end());
		reverse(group.begin(), group.end());
		PaperOnDes ps;
		ps.num = group[0];
		ps.gs.push_back(0);
		for(int i = 1; i < n - 1; i++)
		{
			ps.num -= group[i];
			if(ps.num <= 0)
				ps.gs.pop_front();
			else
				ps.gs.push_back(i);
			ps.num += group[i];
			
		}
		if(find(ps.gs.begin(), ps.gs.end(), 0) != ps.gs.end())
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
		
	}
	
	return 0;
}