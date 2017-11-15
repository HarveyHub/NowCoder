/*
尽管是一个CS专业的学生，小B的数学基础很好并对数值计算有着特别的兴趣，喜欢用计算机程序来解决数学问题，现在，她正在玩一个数值变换的游戏。她发现计算机中经常用不同的进制表示一个数，如十进制数123表达为16进制时只包含两位数7、11（B），用八进制表示为三位数1、7、3，按不同进制表达时，各个位数的和也不同，如上述例子中十六进制和八进制中各位数的和分别是18和11,。 小B感兴趣的是，一个数A如果按2到A-1进制表达时，各个位数之和的均值是多少？她希望你能帮她解决这个问题？ 所有的计算均基于十进制进行，结果也用十进制表示为不可约简的分数形式。
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int change_radix(int n, int radix)
{
	int cnt = 0;
	string str = "";
	while(n)
	{
		cnt += n % radix;
		str.insert(0, 1, char('0' + n % radix));
		n = n / radix;
	}
		cout << "radix: " << radix << " -> " << str << endl;
	return cnt;
}

int gcd(int a, int b)
{
	if(a < b)
		swap(a, b);
	int c = 0;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	
	return a;
}

int main()
{
	int n;
	while(cin >> n)
	{
		if(n == 2)
			continue;
		int sum = 0;
		for(int i = 2; i < n; i++)
		{
			sum += change_radix(n, i);
		}
		int g = gcd(sum, n-2);
		cout << sum/g << "/" << (n-2)/g << endl;
	}
	
	return 0;
}