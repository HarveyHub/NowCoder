#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;



int main()
{
    string str;
    while(cin >> str)
    {
        map<char, vector<int>> s;
        for(size_t i = 0; i < str.size(); i++)
        {
            s[str[i]].push_back(i);
        }
		
        
		auto it = s.begin();
        int last_pos = it->second[it->second.size()-1];
		string res;
		res.push_back(it->first);
		it++;
        for(auto it_s = s.begin(); it_s != s.end(); it_s++ )
        {
            vector<int> d = it_s->second;
            cout << it_s->first << ": ";
            for(auto it_d = d.begin(); it_d !=d.end(); it_d++)
            {
                cout << *it_d << " ";
            }
			cout << endl;
        }
        for(; it != s.end(); it++)
        {
            cout << "last_pos: " <<  last_pos << endl;
            bool flag = false;
            vector<int> &v = it->second;
            for(size_t i = 0; i < v.size(); i++)
            {
                if(v[i] < last_pos)
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
			{
                res.insert(0, 1, it->first);
				last_pos = v[0];
				// last_pos = v[v.size()-1];
			}
            else
			{
				
                res.push_back(it->first);
				last_pos = v[v.size()-1];
			}

        }
        // cout << res << endl;
    }
    return 0;
}