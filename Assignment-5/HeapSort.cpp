//Programming assignement 5
//Roll numbers : 102115004, 102115038
//Heap sort

#include <iostream>
using namespace std;

void max_heapify(int *a, int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j + 1] > a[j])
			j = j + 1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}

void heap_sort(int *a, int n)
{
	int i, temp, swap_count = 0;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		swap_count += 1;
		max_heapify(a, 1, i - 1);
	}
	cout << "Number of swaps that occured are: " << swap_count;
}

void build_maxheap(int *a, int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		max_heapify(a, i, n);
	}
}

void print(int temp_ar[], int size)
{
	for (int i = 1; i <= size; ++i)
	{
		cout << temp_ar[i] << " ";
	}
	cout << endl;
}

int main()
{
	int ar[10], n;
	cout << "Enter the array size: ";
	cin >> n;
	cout << "Enter array of size " << n << ": ";
	for (int i = 1; i <= n; i++)
		cin >> ar[i];
	cout << "Array intially: ";
	print(ar, n);
	build_maxheap(ar, n);
	heap_sort(ar, n);
	cout << "\nArray after heap sort : ";
	print(ar, n);
}

