//Programming assignement 5
//Roll numbers: 102115004, 102115038
//Radix sort


#include <iostream>
using namespace std;

int get_max(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void count_sort(int arr[], int n, int exp)
{	
	int output[20];
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radix_sort(int arr[], int n)
{
	int m = get_max(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		count_sort(arr, n, exp);
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
	int ar[10], n;
	cout << "Enter the array size: ";
	cin >> n;
	cout << "Enter array of size " << n << ": ";
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	cout << "Array intially: ";
	print(ar, n);
	radix_sort(ar, n);
	cout << "\nArray after radix sort : ";
	print(ar, n);
	cout << "Press any key to continue: ";
}

