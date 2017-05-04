//Programming assignement 5
//Roll numbers : 102115004, 102115038
//Insertion sort


#include <iostream>
using namespace std;

void insertion_sort(int ar[], int size)
{
	int temp, swap_count = 0;
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (ar[j] < ar[j - 1])
			{
				temp = ar[j];
				ar[j] = ar[j - 1];
				ar[j - 1] = temp;
				swap_count += 1;
			}
			else
				break;
		}
	}
	cout << "The number of swaps that occured are: " << swap_count;
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
	insertion_sort(ar, n);
	cout << "\nArray after insertion sort : ";
	print(ar, n);
	cout << "Press any key to continue: ";
}

