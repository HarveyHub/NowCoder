#include <iostream>
#include <vector>
#include <iterator>
// #include <algorithm>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void InsertSort(vector<int> &a)
{
    int len = a.size();
    for(int i = 1; i < len; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(a[j] < a[j-1])
            {
                swap(a[j], a[j-1]);
            }

        }
    }
}

void SelectSort(vector<int> &a)
{
    int len = a.size(), i, j, min, index;
    for(i = 0; i < len; i++)
    {
        min = a[i];
        // cout << "i: " << i << " min: " <<  min << endl;
        for(j = i; j < len; j++)
        {
            if(min > a[j])
            {
                min = a[j];
                index = j;
            }
        }

        swap(a[i], a[index]);
    }
}

void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个记录作为枢轴*/

    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }

        a[first] = a[last];/*将比第一个小的移到低端*/

        while(first < last && a[first] <= key)
        {
            ++first;
        }

        a[last] = a[first];
        /*将比第一个大的移到高端*/
    }
    a[first] = key;/*枢轴记录到位*/
    // Qsort(a, low, first-1);
    // Qsort(a, first+1, high);
}

int main()
{
    vector<int> a = {21, 51, 96, 15, 91, 23, 37, 10, 76, 12};
	int b[] = {21, 51, 96, 15, 91, 23, 37, 10, 76, 12};
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // InsertSort(a);
    // SelectSort(a);
	
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
	
	Qsort(b,0, a.size()-1);
	copy(b, b+a.size(), ostream_iterator<int>(cout, " "));
    return 0;

}