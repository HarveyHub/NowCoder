#include<iostream>
using namespace std;

int partition(int a[], int left, int right)
{
	int pivot = a[right];
	int tail = left - 1;
	for(int i = left; i < right; i++)
	{
		if(a[i] < pivot)
		{
			swap(a[i], a[++tail]);
		}
	}
	swap(a[right], a[++tail]);
	return tail;
}

void quick_sort(int a[], int left, int right)
{
	if(left >= right)
		return;
	int pivot_idx = partition(a, left, right);
	quick_sort(a, left, pivot_idx - 1);
	quick_sort(a, pivot_idx + 1, right);
	
}

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
		swap(a[max], a[i]);
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
	// quick_sort(a, 0, len - 1);
	build_heap(a, len);
	heap_sort(a, len);
	for(int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
}