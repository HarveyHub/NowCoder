#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <time.h>
using namespace std;

int main()
{
    int myints[] = {10, 20, 30, 40, 50, 60, 70};
    vector<int> myvector;
    vector<int>::iterator it;

    myvector.resize(7); // 为容器myvector分配空间
    copy(myints, myints + 7, ostream_iterator<int>(cout, " "));
    //copy用法一：
    //将数组myints中的七个元素复制到myvector容器中
    copy(myints, myints + 7, myvector.begin());

    cout << "myvector contains: ";
    for (it = myvector.begin(); it != myvector.end(); ++it)
    {
        cout << " " << *it;
    }
    cout << endl;

    //copy用法二:
    //将数组myints中的元素向左移动一位
    copy(myints + 1, myints + 7, myints);

    cout << "myints contains: ";
    for (size_t i = 0; i < 7; ++i)
    {
        cout << " " << myints[i];
    }
    cout << endl;

    typedef vector<int> IntVector;
    typedef istream_iterator<int> IstreamItr;
    typedef ostream_iterator<int> OstreamItr;
    typedef back_insert_iterator<IntVector> BackInsItr;

    // IntVector myvector;

    // 从标准输入设备读入整数
    // 直到输入的是非整型数据为止 请输入整数序列，按任意非数字键并回车结束输入
    // cout << "Please input element: " << endl;
    // copy(IstreamItr(cin), IstreamItr(), BackInsItr(myvector));

    //输出容器里的所有元素，元素之间用空格隔开
    cout << "Output : " << endl;
    copy(myvector.begin(), myvector.end(), OstreamItr(cout, " "));
    cout << endl;

    int *space = new int[10];
    for (int i = 0; i < 10; i++)
    {
        cout << space[i] << " ";
    }
    cout << endl;
    int *p, *q;
    p = q = space;
    ++q;
    *p = 5;
    for (int i = 0; i < 10; i++)
    {
        cout << space[i] << " ";
    }
    cout << endl;

    srand(time(NULL));
    unsigned len = 100;
    int *ints = new int[len];
    for (unsigned i = 0; i < len; i++)
    {
        ints[i] = rand() % 100 - 50;
    }
    copy(ints, ints + len, ostream_iterator<int>(cout, " "));
    return 0;
}