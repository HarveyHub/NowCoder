#include<iostream>
using namespace std;

struct Base
{
	int i;
	virtual int f()
	{
		cout << "a";
		return 1;
	}
	virtual const Base &f() const
	{
		cout << "b";
		return *this;
	}
	int g()
	{
		cout << "c";
		return 3;
	}
};

struct Derive:Base
{
	int i;
	int f()
	{
		cout << "d";
		return 4;
	}
	const Base &f()const
	{
		cout << "e";
		return *this;
	}
	int f(int = 0)
	{
		cout << "f";
		return 6;
	}
	virtual int g()
	{
		cout << "g";
		return 7;
	}
};

int main()
{
	Derive d;
	Base b, *p = &d;
	b.f();
	p->f();
	p->g();
	
	return 0;
}