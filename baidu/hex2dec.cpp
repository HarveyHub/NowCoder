/*
写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;
  
int main()
{
    string str;
    map<char, int> kv = {{'0',0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A',10}, {'B', 11}, {'C',12}, {'D',13}, {'E',14}, {'F',15}};
    // string nums = "0123456789ABCDEF";
    while(cin >> str)
    {
        long result = 0;
        int len = str.size();
        for(int i = 2; i < len; i++)
        {
            result = result*16 + kv[str[i]];
        }
        cout << result << endl;
    }
}