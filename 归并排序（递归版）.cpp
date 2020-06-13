#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<float.h>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<ctype.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int a[10] = { 31,11,49,15,36,47,5,91,88,10 };
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
void msort(int low,int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;
		msort(low,mid);
		msort(mid + 1,high);
		ms(low,mid,high);
	}
}
int main()
{
	msort(0,9);
	for(int i = 0;i < 10;i++)
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
