#include <iostream>
#include <string>
using namespace std;

class Same {
public:
    bool checkSam(string stringA, string stringB) {
        // write code here
		int len_a = stringA.size(), len_b = stringB.size();
		if(len_a != len_b)
			return false;
		int a[128] = {}, b[128] = {};
		for(int i = 0; i < len_a; i++)
		{
			a[(int)stringA[i]]++;
			b[(int)stringB[i]]++;
		}
		bool flag = true;
		for(int i = 0; i < 127; i++)
		{
			if(a[i] != b[i])
			{
				flag = false;
				break;
			}
		}
		return flag;
		
    }
};

int main()
{
	
}