#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

struct Digit
{
    char num;
	int final_pos;
    vector<int> pos;
    Digit(char n, int index):num(n),final_pos(0)
    {
        pos.push_back(index);
    }
    bool operator<(Digit &r)
    {
        return this->num < r.num;
    }

};


int main()
{
    string str;
    while(cin >> str)
    {
        vector<Digit> nums;
        for(size_t i = 0; i < str.size(); i++)
        {
            bool notfound = true;
            for(size_t j = 0; j < nums.size(); j++)
            {
                if(str[i] == nums[j].num)
                {
                    notfound = false;
                    nums[j].pos.push_back(i);
                    break;
                }
            }
            if(notfound)
                nums.push_back(Digit(str[i], i));
        }

        sort(nums.begin(), nums.end());

        for(size_t i = 0; i < nums.size(); i++)
        {
            cout << "digit: " << nums[i].num << "\t";
            for(size_t j = 0; j < nums[i].pos.size(); j++)
            {
                cout << nums[i].pos[j] << " ";
            }
            cout << endl;
        }
		
		
		
        // cout << res << endl;
    }
    return 0;
}