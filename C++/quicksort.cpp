#include <iostream>
using namespace std;

int partition(int a[], int left, int right)
{
	int pivot = a[right];
	int tail = left - 1;
	for(int i = left; i < right; i++)
	{
		if(a[i] <= pivot)
			swap(a[i], a[++tail]);
	}
	swap(a[right], a[tail+1]);
	return tail+1;
}

void quick_sort(int a[], int left, int right)
{
	if(left >= right)
		return;
	int pivot = partition(a, left, right);
	quick_sort(a, left, pivot-1);
	quick_sort(a, pivot+1, right);
	
}

int main()
{
	int a[] = {5, 2, 9, 4, 7, 6, 1, 3, 8};
	int len = sizeof(a) / sizeof(int);
	quick_sort(a, 0, len - 1);
	for(int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
}