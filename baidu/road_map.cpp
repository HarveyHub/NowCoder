#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct Node
{
	int idx;
	vector<int> children;
	Node(int i):idx(i){};
	bool operator< (Node& rhs)
	{
		return rhs.children.size() > this->children.size();
	}
};


int main()
{
	freopen("road_map.txt", "r", stdin);
	int cnt_city, cnt_move;
	while(cin >> cnt_city >> cnt_move)
	{
		vector<Node> tree;
		int value;
		for(int i = 0; i < cnt_city - 1; i ++)
		{
			Node cur(i);
			cin >> value;
			cur.children.push_back(value+1);
			tree.push_back(cur);
			
		}
		sort(tree.begin(), tree.end());
	}
}