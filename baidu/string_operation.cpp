#include<iostream>
#include<string>
#include<algorithm>

using namespace std;



int main()
{
	string s("test");
	s.erase(2, 3);
	cout << s << endl;
	s.insert(2,  "harvey");
	cout << s << endl;
	s.insert(2, 3, 'c');
	cout << s << endl;
	s.erase(2);
	cout << s << endl;
	
	return 0;
	
}