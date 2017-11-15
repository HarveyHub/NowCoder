#include<iostream>
using namespace std;

class Person
{
public:
    Person():name(""), address("") {}
    Person(const string &n):name(n) {}
    string getName() const
    {
        return this->name;
    }
    void setName(const string& n)
    {
        this->name = n;
    }
    // virtual ~Person();
private:
    string name;
    string address;

};

class Student: public Person
{
public:
    Student(const string& sn):schoolName(sn) {}
    string getName() const
    {
        return this->schoolName;
    }
private:
    string schoolName;
    string schoolAddress;
};


int gcd(int a, int b)
{
	if(a < b)
		swap(a, b);
	while(b != 0)
	{
		int r = b;
		b = a % b;
		a = r;
		
	}
	
	return a;
}

class Rational
{
public:
    Rational(int numerator = 0, int denominator = 1):n(numerator),d(denominator) {}
	friend const Rational operator*(const Rational& lhs, const Rational& rhs);
	void showValue()
	{
		cout << this->n << "/" << this->d << endl;
	}
	int& setn() {return this->n;}
private:
    int n, d;
};
//0x0x6afee8
const Rational operator*(const Rational&lhs, const Rational &rhs)
{
	return Rational (lhs.n * rhs.n, lhs.d * rhs.d);
	 
}
int main()
{
    Rational a(1, 3), b(2, 7);
	Rational c = a*b;
	c.showValue();
	cout << hex << "0x" << &c << endl;
	cout << dec;
	c.setn() = 3;
	c.showValue();
	c = 3 * a;
	c.showValue();
	c = a * 3;
	c.showValue();
}