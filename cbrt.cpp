#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<float.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	double x;
	cin >> x;
	cout << setiosflags(ios::fixed) << setprecision(50);
	cout << cbrt(x); 
	return 0;
}

