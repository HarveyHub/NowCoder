/*
有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？ 
*/

#include<iostream>
using namespace std;

int count(int n)
{
	if(n <= 1)
		return 0;
	if(n == 2)
		return 1;
	return n/3 + count(n/3 + n%3);
}

int main()
{

    int n;
    // while(cin >> n && n)
    // {
		// int cnt = 0;
        // while(n>2)
		// {
			// cnt += n/3;
			// n = n/3 + n % 3;
		// }
		// if(n == 2)
			// cnt ++;
		// cout << cnt << endl;
    // }

    while(cin >> n && n)
    {
        cout << (n>>1) << endl;
    }
	
	ios::sync_with_stdio(false);
    string s="abcdefg";

    //s.substr(pos1,n)返回字符串位置为pos1后面的n个字符组成的串
    string s2=s.substr(1,5);//bcdef
	cout << "s2:\t" << s2 << endl;
    //s.substr(pos)//得到一个pos到结尾的串
    string s3=s.substr(4);//efg
	cout << "s3:\t" << s3 << endl;
	string result;
	result.insert(0, string(1, 'c'));
	result.insert(1, 2, '+');
	cout << result << endl;
    return 0;
}