#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cmp_by_key(const pair<int, int> &lhs, const pair<int, int> &rhs)
{
    return lhs.first < rhs.first;
}

int cmp_by_value(const pair<int, int> &lhs, const pair<int, int> &rhs)
{
    return lhs.second < rhs.second;
}

vector<int> find_k_small(vector<int> &vec, int k)
{
    vector<pair<int, int>> vec_map;
    int i = 0;
    for(i = 0; i < vec.size(); i ++)
    {
        vec_map.push_back(make_pair(vec[i], i));
    }
    sort(vec_map.begin(), vec_map.end(), cmp_by_key);
    vector<int> result;
    i = 0;
    sort(vec_map.begin(), vec_map.begin() + k, cmp_by_value);
    for(auto iter = vec_map.begin(); i<k; i++, iter++)
        result.push_back(iter->first);
    return result;
}

void test1()
{
    cout<< "----test 1----"<<endl;
    vector<int> input = {4,5,1,6,2,7,3,8};
    vector<int> res = find_k_small(input, 4);
    for(auto i : res)
        cout << i << " ";
    cout  << endl;
}

void test2()
{
    cout << endl << "----test 2----" <<endl;
    vector<int> input = {0, 0, 4, 4, 3, 3, 9, 9};
    vector<int> res = find_k_small(input, 4);
    for(auto i : res)
        cout << i << " ";
    cout  << endl;

}

int main()
{
    test1();
    test2();

    return 0;


}