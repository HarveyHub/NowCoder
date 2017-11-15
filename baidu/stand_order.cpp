#include<iostream>
#include<list>
using namespace std;

struct Person
{
	int order;
	int no;
	Person(int i):order(i),no(i){};
};

int main()
{
	int M;
	while(cin >> M)
	{
		list<Person> ps;
		for(int i = 1; i <= 100; i++)
		{
			ps.push_back(Person(i));
		}
		// int left = 100;
		int pos = 0;
		while(ps.size() >= M)
		{
			pos = (pos + M - 1) % ps.size();
			pos.erase(Person(pos));
		}
	}
}