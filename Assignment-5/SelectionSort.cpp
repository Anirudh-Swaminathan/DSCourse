//Programming assignement 5
//Roll numbers : 102115004, 102115038
//Selection Sort

#include <iostream>
using namespace std;

void selection_sort(int ar[], int size)
{
	int min_ele_loc, swap_count = 0;
	for (int i = 0; i < size; ++i)
	{

		min_ele_loc = i;

		for (int j = i + 1; j < size; ++j)
		{
			if (ar[j] < ar[min_ele_loc])
			{
				min_ele_loc = j;
			}
		}

		swap(ar[i], ar[min_ele_loc]);
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
	selection_sort(ar, n);
	cout << "\nArray after selection sort : ";
	print(ar, n);
	cout << "Press any key to continue: ";
}

