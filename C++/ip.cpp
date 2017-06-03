#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
void str2val(const string &str, T &val)
{
	stringstream ss;
	
	ss << str;
	ss >> val;
}	

template <typename T>
string val2str(const T &val, string &str)
{
	stringstream ss;
	ss << val;
	str = ss.str();
	return str;
}

int &get(int *array, int index) {return array[index];}

int main()
{
	// string x = "234.5";
	// float y ;
	// str2val(x, y);
	// cout << y + 21 << endl;
	// string str;
	// val2str(y + 21, str);
	// str += " hello world";
	// cout << str << endl;
	
	int ia[10] = {};
	for(auto i : ia)
		cout << i << " ";
	cout << endl;
	
	for(int i = 0; i != 10; ++i)
		get(ia, i) = i;
	
	for(auto i : ia)
		cout << i << " ";
	

}