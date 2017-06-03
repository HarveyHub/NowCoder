#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool cmp(map<string, vector<double>>::iterator iter1, map<string, vector<double>>::iterator iter2)
{
	return iter1->second[0] > iter2->second[0];
}

map<string, vector<int>> color_map = 
{
	{"black",{30, 40}},
	{"red", {31, 41}},
	{"green", {32, 42}},
};


int main()
{
	map<string, vector<double>> students;
	vector<string> names = {"harvey", "ariel", "bob"};
	srand((unsigned)time(NULL));
	unsigned cnt = 3;
	for(unsigned i = 0; i < names.size(); i++)
	{
		for(unsigned j = 0; j < cnt; j++)
			students[names[i]].push_back(rand() % 100);
		
	}
	
	for(auto iter = students.begin(); iter != students.end(); iter++)
	{
		cout << iter->first << "\t";
		for(auto item : iter->second)
			cout << item << "\t";
		cout << endl;
	}
	
	for(auto iter = color_map.begin(); iter != color_map.end(); iter++)
	{
		cout << iter->first << "\t";
		for(auto item : iter->second)
			cout << item << "\t";
		cout << endl;
	}
	return 0;
}