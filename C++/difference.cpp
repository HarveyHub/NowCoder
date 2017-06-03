#include <iostream>
#include <string>

using namespace std;

class Different {
public:
    bool checkDifferent(string iniString) {
        // write code here
        bool flag = true;
        for(int i = 0; i < iniString.size() - 1; i++)
        {
            for(int j = i + 1; j < iniString.size(); j++)
			{
                if(iniString[i] == iniString[j])
                {
                    flag = false;
                    break;
                }   
				
			}
            
        }
        return flag;
    }
};

int main()
{
	Different d;
	string s = "D-5H0F6T%Z?QM9,\72:[A8X! ;YJ#";
	cout << d.checkDifferent(s) << endl;
}