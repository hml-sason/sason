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
void shellsort(int n);
int main()
{
	shellsort(10);
	return 0;
}

void shellsort(int n)
{
	int i,j,gap;
	for(gap = n / 2;gap > 0;gap /= 2)
	{
		for(i = 0;i < n;i++)
		{
			for(j = i - gap;j >= 0;j -= gap)
			{
				if(a[i] > a[j])
				{
					break;
				}
			}
			int temp = a[i];
			for(int k = i;k > j;k -= gap)
			{
				a[k] = a[k - gap];
			}
			a[j + gap] = temp;
		}
	}
	for(int h = 0;h < n;h++)
	{
		cout << a[h] << " ";
	}
	cout << endl;
	for(int h = n - 1;h >= 0;h--)
	{
		cout << a[h] << " ";
	}
}
