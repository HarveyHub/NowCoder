#include<iostream>
#include<string>
#include<set>
using namespace std;

bool is_legal(string str)
{
    int len = str.size(), cnt = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '(')
            cnt ++;
        if(str[i] == ')')
            cnt --;
        if(cnt < 0)
            return false;
    }
    return cnt == 0;
}

int main()
{
    string str;
    while(cin >> str)
    {
        set<string> res;
        int len = str.size();
        for(int i = 0; i < len; i++)
        {

            for(int j = 0; j < len - 1; j++)
            {
                string tmp = str.substr(0, i) + str.substr(i+1, len);
                tmp.insert(j, 1, str[i]);
                
                if(is_legal(tmp))
				{
					cout << tmp << endl;
                    res.insert(tmp);
				}
            }

        }
        cout << res.size() - 1 << endl;
    }

    return 0;
}