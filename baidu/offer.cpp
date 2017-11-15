#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class PopOrder {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() ==0 || popV.size() == 0)
			return false;
		
		stack<int> s;
		int pop_index = 0;
		for(size_t i = 0; i < pushV.size(); i++)
		{
			s.push(pushV[i]);
			while(!s.empty() && s.top() == popV[pop_index])
			{
				s.pop();
				pop_index ++;
			}
		}
        return s.empty();
        
    }
};

int main()
{
	vector<int> v1 = {1, 2, 3, 4, 5}, v2 = {4, 3, 5, 1, 2};
	PopOrder p;
	cout << p.IsPopOrder(v1, v2) << endl;
	return 0;
}