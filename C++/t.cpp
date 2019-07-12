#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


struct Coord{
    int x;
    int y;
};

double cacDist(Coord a, Coord b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y));
}

int dis_cmp(const pair<Coord, double> &lhs, const pair<Coord, double> &rhs)
{
    return lhs.second < rhs.second;
}

vector<Coord> near_by(vector<Coord> & vec, Coord e, int k)
{
    vector<pair<Coord, double>> point_distance;
    for(Coord p:vec)
    {
        point_distance.push_back(make_pair(p, cacDist(e, p))) ;
    }
    sort(point_distance.begin(), point_distance.end(), dis_cmp);
    vector<Coord> result;
    int i = 0;
    for(auto iter = point_distance.begin(); i < k && iter != point_distance.end(); i++, iter++)
    {
        result.push_back(iter->first);
    }
    return result;

}


int main()
{
    Coord a,b;
    a.x = 0;
    a.y = 0;
    b.x = 3;
    b.y = 4;
    cout << cacDist(a,b) <<endl;

    pair<Coord, double> p1 = {a, 3};
    pair<Coord, double> p2 = {b, 4};
    cout << dis_cmp(p1, p2) << endl;
    vector<Coord> vec  = {{0,0}, {1, 2}, {3, 4}, {6, 7}, {7, 8}, {2, 1}, {5, 5}, {5,6}};
    vector<Coord> res = near_by(vec, b, 3);
    return 0;
}