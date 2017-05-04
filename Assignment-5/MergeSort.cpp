//Programming assignement 5
//Roll numbers: 102115004, 102115038
//Merge sort


#include <iostream>
using namespace std;

void merge(int *a, int low, int high, int mid)
{
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)
	{
		a[i] = c[i];
	}
}

void merge_sort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merge(a, low, high, mid);
	}
	return;
}

void print(int temp_ar[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << temp_ar[i] << " ";
	}
	cout << endl;
}

int main()
{
	int ar[10], n, swap_count = 0;
	cout << "Enter the array size: ";
	cin >> n;
	cout << "Enter array of size " << n << ": ";
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	cout << "Array intially: ";
	print(ar, n);
	merge_sort(ar, 0, n - 1);
	cout << "Number of sorts that occured are: " << swap_count;
	cout << "\nArray after merge sort : ";
	print(ar, n);
	cout << "Press any key to continue: ";
}

