/*
如果一个01串任意两个相邻位置的字符都是不一样的,我们就叫这个01串为交错01串。例如: "1","10101","0101010"都是交错01串。
小易现在有一个01串s,小易想找出一个最长的连续子串,并且这个子串是一个交错01串。小易需要你帮帮忙求出最长的这样的子串的长度是多少
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>

using namespace std;



int main()
{
    string str;
    while(cin >> str)
    {
        int max = 1, cnt = 1, len = str.size();
        for(int i = 0; i < len-1; i++)
        {
            if(str[i] != str[i+1])
            {
                cnt++;
            }
            else
            {
                if(cnt > max)
                {
                    max = cnt;
                }
                cnt = 1;
            }
        }

        max = (cnt > max)?cnt:max;


        cout << max << endl;


    }
    return 0;
}