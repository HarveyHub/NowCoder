#include <iostream>
using namespace std;

void heapify(int a[], int i, int size)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int max = i;
	if(left < size && a[max] < a[left])
		max = left;
	if(right < size && a[max] < a[right])
		max = right;
	if(max != i)
	{
		swap(a[i], a[max]);
		heapify(a, max, size);
	}
}

void build_heap(int a[], int size)
{
	for(int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(a, i, size);
	}
}

void heap_sort(int a[], int size)
{
	while(size != 1)
	{
		swap(a[0], a[size - 1]);
		heapify(a, 0, --size);
	}
}

int main()
{
	int a[] = {5, 2, 9, 4, 7, 6, 1, 3, 8};
	int len = sizeof(a) / sizeof(int);
	build_heap(a, len);
	heap_sort(a, len);
	for(int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	
}