#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
    string str;
    while(cin >> str)
    {
        int n;
        cin >> n;
		int i = 0;
        for(int j = 0; j < n; j++)
        {
            int len = str.size();
            for(; i < len - 1; i++)
            {
                if(str[i] < str[i+1])
				{
                    str.erase(str.begin()+i);
					break;
				}
            }
			if(i == len-1)
				str.erase(str.end() - 1);
			i--;
        }
        
        cout << str << endl;
    }
}