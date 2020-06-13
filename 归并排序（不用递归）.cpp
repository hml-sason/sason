#include<iostream>
using namespace std;
int a[10] = { 31,11,49,15,36,47,5,91,88,10 };
void ms(int low, int mid, int high);
void msort(int n);
int main()
{
	msort(10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for(int i = 9;i >= 0;i--)
	{
		cout << a[i] << " ";
	}
	return 0;
}
void ms(int low, int mid, int high)
{
	int i = low, j = mid + 1, k = 0;
	int* temp = new int[high - low + 1];
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= high)
	{
		temp[k++] = a[j++];
	}
	for (i = low, k = 0; i <= high; i++, k++)
	{
		a[i] = temp[k];
	}
	delete[] temp;
}

void msort(int n)
{
	int size = 1, low, mid, high;
	while (size <= n - 1)
	{
		low = 0;
		while (low + size <= n - 1)
		{
			mid = low + size - 1;
			high = mid + size;

			if (high > n - 1)
			{
				high = n - 1;
			}
			ms(low, mid, high);
			low = high + 1;
		}
		size *= 2;
	}
}
