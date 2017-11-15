#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
using namespace std;

template <typename T>
void str2val(const std::string &str, T &val)
{
	std::stringstream ss;
	ss << str;
	ss >> val;
}

template <typename T>
void val2str(const T &val, std::string &str)
{
	std::stringstream ss;
	ss << val;
	str += ss.str();
}

int main()
{
	double d = 0;
	str2val("3.1415", d);
	string str("hello world");
	cout << d << endl;
	val2str(d, str);
	
	cout << str << endl;
	cout.precision(2);
	cout << setiosflags(ios::fixed) << d << endl;
}
