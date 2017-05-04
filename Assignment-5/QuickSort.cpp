//Programming assignement 5
//Roll numbers: 102115004, 102115038
//Quick Sort


#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    
	int i = (low - 1);  
	int swap_count = 0;

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;    
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		
		int partioning_index = partition(arr, low, high);

		quick_sort(arr, low, partioning_index - 1);
		quick_sort(arr, partioning_index + 1, high);
	}
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
	quick_sort(ar, 0, n-1);
	cout << "\nArray after quick sort : ";
	print(ar, n);
	cout << "Press any key to continue: ";
}

