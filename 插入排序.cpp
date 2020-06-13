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
void insertsort(int n);
int main()
{
	insertsort(10);
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

void insertsort(int n)
{
	for(int i = 1;i < n;i++)
	{
		for(int j = i - 1;j >= 0&&a[j + 1] < a[j];j--)
		{
			swap(a[j],a[j + 1]);
		}
	}
}
