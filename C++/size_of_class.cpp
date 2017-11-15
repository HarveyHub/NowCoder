#include<iostream>
using namespace std;

class Test
{
    Test() {}
    ~Test() {}
    void test() {}
    virtual void v_test(){}
private:
	double d;
	string str;
    int num;
};

int main()
{
    cout << sizeof(Test) << endl;
    return 0;
}