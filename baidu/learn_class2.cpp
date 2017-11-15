#include<iostream>
using namespace std;

struct Base
{
    Base()
    {
        cout << "Base:Base()" << endl;
    }
    virtual void f()
    {
        cout << "Base:f()" << endl;
    }
    void g()
    {
        cout << "Base:g()" << endl;
    }
    static int cnt;//static int cnt = 1;是错误的写法
    static void dec()
    {
        cnt--;
        cout << "Base:dec() " << cnt << endl;
		// cout << cnt1 << endl;//调用错误，静态成员函数不能访问非静态成员变量
    }
    int cnt1;

};
int Base::cnt = 1;//正确赋初值方法
struct Derive:Base
{
    Derive()
    {
        cout << "Derive:Derive()" << endl;
    }
    void f()
    {
        cout << "Derive:f()" << endl;
    }
    virtual void g()
    {
        cout << "Derive:g()" << endl;
    }
    void dec()
    {
        cnt--;
        cout << "Derive:dec() " << cnt << endl;
    }
};

int main()
{
    Base *ptr_b = new Derive();
    ptr_b->f();
    ptr_b->g();
    ptr_b->dec();
	Base::dec();
	cout << "out of class: " << Base::cnt << endl;
    cout << string(10, '=') << endl;
    Derive *ptr_d = new Derive();
    ptr_d->f();
    ptr_d->g();
    ptr_d->dec();
    cout << string(10, '=') << endl;
    Base *ptr_test = new Base();
    ptr_test->f();
    ptr_test->g();
    ptr_test->dec();
    return 0;
}