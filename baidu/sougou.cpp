#include<iostream>
#include<vector>
#include<string>
using namespace std;

class t_classA
{
public:
    t_classA() {};
    ~t_classA() {};
};

class t_classB
{
public:
    t_classB() {};
    virtual ~t_classB() {};
};

class t_classC:public t_classA, public t_classB
{
public:
    t_classC() {};
    virtual ~t_classC() {};
};

class A
{
public:
    void funA()
    {
        cout << "func a" << endl;
    }
    virtual void funB()
    {
        cout << "func b" << endl;
    }
    static void funC()
    {
        cout << "func c" << endl;
    }
};

class B:public A
{
public:
    void funB()
    {
        cout << "func b in b" << endl;
    }
    int funD()
    {
        cout << "func d" << endl;
    }
};

bool IsPrimer(int num)
{
    if(num < 2)
        return false;
    if(num == 2)
        return true;
    for(int i = 2; i*i <= num; i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

int CountPrimer(int s, int e)
{
    int cnt = 0;
    if(s > e)
        swap(s, e);
    for(int i = s; i <= e; i++)
    {

        if(IsPrimer(i))
        {
            cnt ++;
        }
    }
    return cnt;
}

int LCS(string a, string b)
{
	vector<int> tmp(b.size()+1, 0);
	vector<vector<int>> table(a.size()+1, tmp);
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b.size(); j++)
		{
			if(a[i] == b[i])
			{
				table[i+1][j+1] = table[i][j] + 1;
				cout << i << "\t" << j << a[i] << "\t" << b[i] << endl;
			}
			else
			{
				table[i+1][j+1] = max(table[i][j+1], table[i+1][j]);
			}
		}
	}
	return table[a.size()][b.size()];
}

int main()
{
    // int nLenA = sizeof(t_classA);
    // t_classA oA;
    // int nLenAObject = sizeof(oA);
    // int nLenB = sizeof(t_classB);
    // t_classB oB;
    // int nLenBOject = sizeof(oB);
    // int nLenC = sizeof(t_classC);
    // t_classC oC;
    // int nLenCObject = sizeof(oC);

    // cout << nLenA << "\t" << nLenAObject << "\t" << nLenB << "\t" << nLenBOject << "\t" << nLenC << "\t" << nLenCObject << endl;

    // cout << sizeof(A) << endl;

    // B *b = NULL;
    // b->funA();
    // b->funB();
    // b->funC();
    // b->funD();

    cout << CountPrimer(4, 12) << endl;
    int n = 4;
    int a[4] = {2, 8, 10, 16};
    int times = n*(n-1)/2;
    int cnt = 0;

    while(cin >> n)
    {
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                cout << a[i] << " ~ " << a[j] << "\t" << CountPrimer(a[i], a[j]) << endl;
                cnt += CountPrimer(a[i], a[j]);
            }
        }
		cout << cnt << endl;
    }

	
	cout << LCS("ABCBDAB", "BDCABA");
	
	while(cin >> str)
	{
		string rstr = str;
		reverse(rstr.begin(), rstr.end());
		cout << LCS(str, rstr) / 2 << endl;
	}
    return 0;
}