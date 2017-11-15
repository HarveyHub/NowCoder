#include <iostream>
#include <string>
#include <cstring>
#include <time.h>
#include <algorithm>

using namespace std;



class Person
{
public:
    string Name;
    unsigned Age;
    Person() {};
};

class Student
{
private:


public:
    string Name;
    unsigned Age;
    float Score;
    static const int ObjCnt = 0;
    static const int InfoLen = 50;
    char *Info;
    void show_info(ostream& os)
    {
        os << "Name: " << this->Name << " Age: " << this->Age << endl;
        os << "Infomation: " << this->Info << endl;
    }
    Student()
    {
        cout << "default constructor in student " << endl;
        this->Info = new char[InfoLen];
    }
    Student(string name, unsigned age):Name(name),Age(age)
    {

        cout << "full constructor in student" << endl;
        this->Info = new char[InfoLen];
    }
    Student(const Student& rstu)
    {

        cout << "copy constructor in student" << endl;
        this->Name = rstu.Name;
        this->Age = rstu.Age;
        this->Info = new char[InfoLen];
    }
    Student& operator=(const Student& rstu)
    {
        cout << "copy assignment overload" << endl;
        this->Name = rstu.Name;
        this->Age = rstu.Age;
        return *this;
    };
    void set_name(string name)
    {
        this->Name = name;
    }

    ~Student()
    {
        cout << "class student is destructing..." << endl;
        delete Info;
    }
};

bool is_adult(Student s)
{
    if(s.Age >= 18)
        return true;
    else
        return false;

}

class NamedObject
{
public:
    NamedObject(std::string& name):nameValue(name) {};
private:
    std::string &nameValue;

};

// class Transaction
// {
	// public:
		// Transaction();
		// void init();
		// virtual void logTransaction() const = 0;
// };


// Transaction::void init()
// {
	// cout << "init in Transaction" << endl;
// }
// Transaction::Transaction()
// {
	// cout << "constructor in Transaction" << endl;
	// init();
// }

// class BuyTransaction:public Transaction
// {
	// public:
		// virtual void logTransaction() const;
		// BuyTransaction()
		// {
			// cout << "constructor in BuyTransaction" << endl;
		// }
// };

// class SellTransaction:public Transaction
// {
	// public:
		// virtual void logTransaction() const;
// };

class Test
{
	private:
		int a,b;
	public:
		void init();
		virtual void test();
		Test();
};

Test::Test()
{
	init();
}
void  Test::init()
{
	cout << "Init in Test" << endl;
	test();
}

void Test::test()
{
	cout << "test in Test" << endl;
}

class Test_child:public Test
{
	public:
		virtual void test()
		{
			cout << "test in test_child" << endl;
		}
};


int main()
{
    // Student s1;
    // Student s2("harvey", 24);
    // memset(s2.Info, 0, 50);
    // memcpy(s2.Info, "harvey is good", 50);
    // s1 = s2;
    // s1.show_info(cout);
    // Student s3(s2);

    // cout << "is_adult " <<  is_adult(s2) << endl;
	Test_child t;


    return 0;
}