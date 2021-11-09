#include<iostream>
using namespace std;
int partition(int* a, int p, int r)
{
	int temp;
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a[j] <= x)
		{
			i = i + 1;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;

		}

	}
	temp = a[r];
	a[r] = a[i + 1];
	a[i + 1] = temp;
	return i + 1;
}
void quicksort(int* a,int p,int r)
{
	int q;
	if (p < r)
	{
		q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

int main()
{
	int arr[10];
	cout << "enter elements of the array(10)" << endl;
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
	quicksort(arr, 0, 9);
	cout << "sorted array is:" << endl;
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";

}