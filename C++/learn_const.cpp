#include<iostream>
#include<string>
using namespace std;

void msg(const string &str) 
{
	cout << str << endl;
}

class TextBlock
{
	public:
	TextBlock(string txt):text(txt){}
	const char& operator[](std::size_t position) const
	{
		//边界检查
		if(position >= text.size())
			return text[text.size()-1];
		//日志记录
		//logging...
		//检验数据完整性
		return text[position];
	}
	// char& operator [](std::size_t position)
	// {
		
		// return text[position];
	// }
	// update:增加了函数的复用率，降低代码重复率。
	char& operator[] (std::size_t position)
	{
		return const_cast<char&>(//将const版本的返回值改为non-const
		static_cast<const TextBlock&> (*this)//将自身改为const以便调用[]函数的const版本
		[position]);
	}
	private:
	string text;
};



int main()
{
	TextBlock tb("hello");
	cout << tb[0] << endl;
	tb[0] = 'j';
	cout << tb[0] << endl;
	const TextBlock ctb("world");
	cout << ctb[1] << endl;
	tb = tb;
	
	
}