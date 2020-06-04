#include<iostream>
#include<cstring>
using namespace std;
int a[10] = { 31,11,49,15,36,47,5,91,88,10 };
void qsort(int l, int r)
{
	int mid = a[(l + r) / 2];
	int i = l, j = r;
	while (i <= j)
	{
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;

		if (i <= j)
		{
			swap(a[i++], a[j--]);
		}
	}
	if (l < j) qsort(l, j);
	if (i < r) qsort(i, r);
}
int main()
{
	qsort(0, 9);
	for (int i = 0; i < 9; i++) cout << a[i] << ' '; 
	return 0;
}
