#include<iostream>
#include<string>
using namespace std;



int main()
{
    string str;
    while(cin >> str)
    {
        int cnt = 0, len = str.size();
        str.append("$");
        // str.push_front("$");
        // deal with the head and tail
        if(len == 1)
        {
            cout << 1 << endl;
            break;
        }
        if(str[0] == '?')
        {

            if(str[1] == '?')
                str[0] = (str[2]=='A'? 'A':'B');

            else
                str[0] = (str[1]=='A'? 'B':'A');

        }


        for(int i = 1; i < len; i++)
        {

            if(str[i] == '?')
            {
                if(str[i+1] == '?')
                {
                    str[i] = (str[i-1] == 'A' ? 'B':'A');
                    str[i+1] = (str[i-1] == 'A' ? 'A':'B');
                    // cout << i << "\t" << str[i-1] << "\t" << str[i] << "\t" << str[i+1] << endl;
                }
                if(str[i - 1] != str[i+1])
                {
                    str[i] = str[i - 1];
                    // cout << i << "\t" << str[i-1] << "\t" << str[i] << "\t" << str[i+1] << endl;
                }
                str[i] = (str[i-1] == 'A' ? 'B':'A');
            }
            if(str[i] == str[i-1])
                cnt ++;
        }

        cout << cnt ;
        cout << "\t" << str << endl;
    }

    return 0;
}