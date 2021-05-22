#include<iostream>
#include<cstdlib>
using namespace std;
void merge(int* a, int p, int q, int r) {
	int i, j;
	int n1 = q - p + 1;
	int n2 = r - q;
	int* l, * m;
	l = (int*)malloc(sizeof(int) * (n1 + 1));
	m = (int*)malloc(sizeof(int) * (n2 + 1));
	for (i = 0; i < n1; i++)
		l[i] = a[p + i];
	for (j = 0; j < n2; j++)
		m[j] = a[q + j + 1];
	/*
	l[i] = INT_MAX;
	m[j] = INT_MAX;
	*/
	i = j = 0;
	for (int k = p; k <= r; k++) {
		if (l[i] < m[j]) {
			a[k] = l[i];
			
			if (i == n1-1) {
				while (j <n2) {
					a[k+1] = m[j];
					j++;
					k++;
				}
			}
			i++;
		}
		else {
			a[k] = m[j];
			if (j == n2-1) {
				while (i < n1) {
					a[k+1] = l[i];
					i++;
					k++;
				}
			}
			
			j++;
		}


	}
}
void merge_sort(int* a, int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

int main()
{
	int arr[100];
	int n;
	cout << "enter number of elements of array ( max limit 100)" << endl;
	cin >> n;
	cout << "enter elements of the array" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_sort(arr, 0, n - 1);
	cout << "sorted array is: " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";

	}
}