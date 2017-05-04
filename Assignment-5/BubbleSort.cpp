//Programming assignement 5
//Roll numbers : 102115004, 102115038
//Bubble Sort

#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
	int swap_count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n - i - 1; ++j)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swap_count += 1;
			}
	cout << "Number of swaps that occured are: " << swap_count;
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
	bubble_sort(ar, n);
	cout << "\nArray after bubble sort : ";
	print(ar, n);
	cout << "Press any key to continue: ";
}

