//Programming assignement 5
//Roll numbers: 102115004, 102115038
//Sorting Techniques

#include <iostream>
using namespace std;

//Selection Sort
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

//Bubble Sort
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

//Insertion Sort
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

//Heap Sort
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

//Quick Sort
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

//Merge Sort
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

//Radix Sort
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

//Printing the array
void print(int temp_ar[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << temp_ar[i] << " ";
	}
	cout << endl;
}

//Duplicating the input array
void duplicate_array(int ar[], int copy_ar[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		copy_ar[i] = ar[i];
	}
	return ;
}

int main()
{
	int ar[10], copy_ar[10], n;
	cout << "Enter the array size: ";
	cin >> n;
	cout << "Enter array of size " << n << ": ";
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	cout << "Array intially: ";
	print(ar, n);
	duplicate_array(ar, copy_ar, n);
	cout<<"\n=======================\n";
	
	duplicate_array(copy_ar, ar, n);
	selection_sort(ar, n);
	cout << "\nArray after selection sort : ";
	print(ar, n);
	cout<<"\n=======================\n";

	duplicate_array(copy_ar, ar, n);
	bubble_sort(ar, n);
	cout << "\nArray after bubble sort : ";
	print(ar, n);
	cout<<"\n=======================\n";

	duplicate_array(copy_ar, ar, n);
	insertion_sort(ar, n);
	cout << "\nArray after insertion sort : ";
	print(ar, n);
	cout<<"\n=======================\n";
	
	duplicate_array(copy_ar, ar, n);
	for(int i=1; i<=n; ++i)
		ar[i] = copy_ar[i-1];
	build_maxheap(ar, n);
	heap_sort(ar, n);
	cout << "\nArray after heap sort : ";
	//print(ar, n);
	for(int i=1; i<=n; ++i) cout<<ar[i]<<" ";
	cout<<"\n=======================\n";
	
	duplicate_array(copy_ar, ar, n);
	quick_sort(ar, 0, n-1);
	cout << "Array after quick sort : ";
	print(ar, n);
	cout<<"\n=======================\n";
	
	duplicate_array(copy_ar, ar, n);
	merge_sort(ar, 0, n - 1);
	cout << "Array after merge sort : ";
	print(ar, n);
	cout<<"\n=======================\n";

	
	duplicate_array(copy_ar, ar, n);
	radix_sort(ar, n);
	cout << "Array after radix sort : ";
	print(ar, n);
	
	return 0;
}
