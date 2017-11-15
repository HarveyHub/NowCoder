#include <iostream>
#include <cstdlib>
#include <vector>
#include <exception>
#include <complex>
#include <system_error>
#include <bitset>
using namespace std;

struct int_node
{
    int val;
    int_node* next;
};

template <class Node>
struct node_wrap
{
    Node* ptr;
    node_wrap(Node* p = 0) : ptr(p) {}
    Node& operator*() const
    {
        return *ptr;
    }
    Node* operator->() const
    {
        return ptr;
    }

    node_wrap& operator++() const
    {
        ptr = ptr->next;
        return *this;
    }
    node_wrap operator++(int)
    {
        node_wrap tmp = *this;
        ++*this;
        return tmp;
    }

    bool operator == (const node_wrap& i) const
    {
        return ptr == i.ptr;
    }
    bool operator != (const node_wrap& i) const
    {
        return ptr != i.ptr;
    }

};

template<class I, class T>
void f_impl(I iter, T t)
{
    T tmp;// T是I的值类型
}

template <class I> inline void f(I iter)
{
    f_impl(iter, *iter);
}


template <class Iterator>
struct iterator_traits
{
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;

};




template <typename T>
T sum(T* ptr, unsigned len)
{
    T tmp = 0;
    for(unsigned i = 0; i < len; i++)
    {
        tmp += ptr[i];
    }
    return tmp;
}

void print (std::initializer_list<int> vals)
{
    for (auto p=vals.begin(); p!=vals.end(); ++p)   // process a list of values
    {
        std::cout << *p << "\n";
    }
}

void print ()
{
}

template <typename T, typename... Types>
void print (const T& firstArg, const Types&... args)
{
    std::cout << firstArg << std::endl; // print ﬁrst argument
    print(args...); // call print() for remaining arguments
}



template <typename T>
class MyClass
{
	private:
	T value;
	public:
	MyClass()
	{
		
	}
	template <typename U>
	MyClass(const MyClass<U>& x)
	{
		cout << "called MyClass<*>& " << endl;
		
	}
};

void throw_exception()
{
	throw std::out_of_range ("out_of_range (somewhere, somehow)");
}

int main()
{
    node_wrap<int_node> head;
    unsigned len  = 10;
    int* ptr = new int[len];
    for(unsigned i = 0; i < len; i++)
    {
        ptr[i] = i;
    }
    cout << sum(ptr, len) << endl;
    vector<vector<int>> ints;
    cout << "NULL" << NULL << endl;
    int i;
    cout << "i: " << i << endl;

    int j {};
    cout << ": " << j << endl;

    int *p;
    cout << "*p: " << p << endl;

    int *q {};
    cout << "*q: " << q << endl;

    int values[] {1,2,3};
    std::vector<int> v { 2, 3, 5, 7, 11, 13, 17 };
    std::vector<std::string> cities
    {
        "Berlin", "New York", "London", "Braunschweig", "Cairo", "Cologne"
    };
    // std::complex<double> c {4.0,3.0}; // equivalent to c(4.0,3.0)
    // std::terminate();
    // print ( {12,3,5,7,11,13,17});
    cout << "another print" << endl;
    print (7.5, "hello",  std::bitset<16>(377), 42);

    []
    {
        std::cout << "hello lambda" << std::endl;
    } ();

    auto l = []
    {
        std::cout << "hello lambda again" << std::endl;
    };

    l();//
	
	MyClass<double> xd;
	MyClass<double> xd2(xd);//copy constructor
	MyClass<int> xi(xd);//template constructor
	
	std::cout << std::hex << 3.4 << std::endl;
	
	cout <<  (unsigned)std::errc::invalid_argument << endl;
	
	try
	{
		throw_exception();
	}
	catch(exception e)
	{
		cerr << e.what() << endl;
	}
	
    return 0;
}