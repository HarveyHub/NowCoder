#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Student
{
	int ability;
	int pos;
	bool taken;
	Student(){}
	Student(int a, int p):ability(a), pos(p), taken(false){}
	// bool operator<(Student &a)
	// {
		// if(this->ability == a.ability)
			// return this->pos < a.pos;
		// else 
			// return this->ability < a.ability;
	// }
};

int main()
{
	int n;
	while(cin >> n)
	{
		vector<Student> s;
		int ability;
		for(int i = 0; i < n; i++)
		{
			cin >> ability;
			s.push_back(Student(ability, i));
		}
		sort(s.begin(), s.end());
		for(int i = 0; i < n; i++)
		{
			cout << s[i].ability << "\t" << s[i].pos << endl;
		}
		int k, d;
		cin >> k >> d;
	
		
	}
	
	return 0;
}