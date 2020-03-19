#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<float.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
int f(int x);
int main()
{
	int x;
	cin >> x;
	cout << f(x); 
	return 0;
}
int f(int x)
{
	int n = 0;
	do
	{
		n = n + x % 10;
		x /= 10;
		n = n * 10;
	}while(x != 0);
	return n / 10;
}
