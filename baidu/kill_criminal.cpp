#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

bool cmp(const int &lhs, const int &rhs)
{
    return lhs > rhs;
}

int main()
{
    freopen("kill_criminal.txt", "r", stdin);
    int n, s_damage, r_damage;
    while(cin >> n >> s_damage >> r_damage)
    {
        int cnt_shot = 0, tmp_shot;
        vector<int> health(n, 0);
        for(int i = 0; i < n ; i++)
        {
            cin >> health[i];
        }

        sort(health.begin(), health.end(), cmp);
        for(int i = 0; i < n;)
        {
			if(s_damage < health[i])
				tmp_shot = health[i] / s_damage;
			else
				tmp_shot = 1;
            cnt_shot += tmp_shot;
            health[i] -= tmp_shot * s_damage;
            //deal with the remain
            for(int j = i+1; j < n; j++)
            {
                health[j] -= tmp_shot * r_damage;
            }
            //find the new position of health[i]
			
            int j = 0;
			for(j = 0; j < n - 1; j++)
			{
				if(health[j] < health[j+1])
				{
					swap(health[j], health[j+1]);
				}
			}
            //find the next health[i] > 0

            for(j = 0; j < n; j++)
            {
                if(health[j] > 0)
                {
                    i = j;
                    break;
                }
            }
            if(j == n)
                break;

        }
        cout << cnt_shot << endl;
    }

    return 0;
}
