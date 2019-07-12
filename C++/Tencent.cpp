#include <iostream> 
#include <assert.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

char* mystrcpy(char* strDest, char* strSrc){
    assert(strDest != NULL && strSrc != NULL);
    int cnt = strlen(strSrc);
    char* d = strDest, *s = strSrc;
    if(d<=s || d >= s+cnt){
        while(cnt){
            *d = *s;
            d++;
            s++;
            cnt--;
        }
       
    }else{
        d+= cnt-1;
        s+= cnt-1;
        while(cnt){
            *d = *s;
            d--;
            s--;
            cnt --;
        }
    }
    return strDest;

}

void test1()
{
    cout << "----test 1----"<<endl;
    char* src = "hello world";
    char* dec = (char*)malloc(sizeof(src));
    mystrcpy(dec, src);
    cout << dec << endl;
}

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

void test2()
{
    cout << endl<< "----test 2----"<<endl;
    Coord a = {3, 3};
    vector<Coord> vec  = {{0,0}, {1, 2}, {3, 4}, {6, 7}, {7, 8}, {2, 1}, {5, 5}, {5,6}};
    vector<Coord> res = near_by(vec, a, 3);
    cout << "the 3 nearest point to a in vec are " << endl;
    for(auto r:res)
        cout << "x: " << r.x << " y:" << r.y << endl;

    
}

vector<int> mystatistics(int arrA[], int arrAsize, int cnt)
{
    map<int, int> statistics;
    for(int i = 0; i < arrAsize; i++)
    {
        if(statistics.find(arrA[i]) == statistics.end())
        {
            statistics[arrA[i]] = 1;
        }
        else
        {
            statistics[arrA[i]] ++;
        }
        
    }
    vector<int> result;
    auto iter = statistics.begin();
    while(iter != statistics.end())
    {
        if(iter->second > cnt)
            result.push_back(iter->first);
        iter++;
    }
    return result;
}

void test4()
{
    cout << endl << "----test 4----" << endl;
    int a[] = {1, 3, 3, 9, 9, 8, 8, 8, 2, 2, 1, 1, 4, 4, 4};
    int len = sizeof(a)/sizeof(int);
    auto result = mystatistics(a, len, 2);
    cout << "the threadhold > 2 in array a is " ;
    for(auto r : result)
        cout << r << " ";
    cout << endl; 
}

struct ListNode
{
    int m_nkey;
    ListNode* m_pNext;
};

ListNode *find_tail_kth_node(ListNode *head, int k)
{
    ListNode *p, *q;
    int i = 0;
    p = head;
    q = head;
    while(p->m_pNext != NULL)
    {
        i ++;
        p = p->m_pNext;
        if(i == k)
            break;
    }
    if(i < k)
        return NULL;
    q = q->m_pNext;
    while(p->m_pNext != NULL)
    {
        p = p->m_pNext;
        q = q->m_pNext;
    }
    return q;
}

//数组会转化成带头节点的链表
void array2list(int a[], int len, ListNode* head)
{
    
    ListNode *p = head;
    for(int i = 0; i < len; i++)
    {
        ListNode* n = (ListNode*)malloc(sizeof(ListNode));
        n->m_nkey = a[i];
        n->m_pNext = NULL;
        p->m_pNext = n;
        p = p->m_pNext;

    }
}

void test3()
{
    cout << endl << "----test 3-----" << endl;
    int a[] = {5, 4, 3, 2, 1};
    ListNode list, *p;
    array2list(a, sizeof(a)/sizeof(int), &list);
    p = find_tail_kth_node(&list, 2);
    cout << "the tail 2nd node's value is " <<  p->m_nkey << endl;
}

struct Person
{
    string name;
    int depID;
    int cenID;
};
class Staff
{
    public:
    Staff(string filename)
    {
        ifstream infile;
        infile.open(filename);
        if(!infile.is_open())
        {
            cerr << "could not open file" << endl;
            exit(1);
        }
           
        string line;
        while(getline(infile, line))
        {
            Person p;
            stringstream ss;
            ss << line;
            ss >> p.name >> p.depID >> p.cenID;
            staffs.push_back(p);

        }
    }

    pair<int, int> getMemberInfo(string name)
    {
        for(auto s:staffs)
        {
            if(s.name == name)
                return make_pair(s.depID, s.cenID);
        }
        return make_pair(0, 0);
    }
    vector<string> getMembersOfDepart(int depart_id)
    {
        vector<string> result;
        for(auto s : staffs)
        {
            if(s.depID == depart_id)
                result.push_back(s.name);
        }
        return result;
    }
    vector<string> getMembersOfCenter(int center_id)
    {
        vector<string> result;
        for(auto s : staffs)
        {
            if(s.cenID == center_id)
                result.push_back(s.name);
        }
        return result;
    }

    private:
    vector<Person> staffs;

    
};

void test5()
{
    cout << endl << "----test 5---- " << endl;
    Staff staff = Staff("F:\\NowCoder\\C++\\tencent.txt");
    auto r = staff.getMemberInfo("harvey");
    cout << "harvey's depart_id is " << r.first << " and center_id is " << r.second << endl;
    auto members1 = staff.getMembersOfDepart(10);
    cout << "members whose depart_id is 10 are ";
    for(auto m : members1)
        cout << m << " ";
    cout << endl;
    auto members = staff.getMembersOfCenter(102);
    cout << "members whose center_id is 102 are ";
    for(auto m: members)
        cout << m << " ";
    cout << endl;
}

int main()
{
    test1();
    test2();
    test3();

    test4();

    test5();

    return 0;
}