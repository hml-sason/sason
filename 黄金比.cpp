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
const int MAX = 100;
void function();
int main()
{
	function();
	return 0;
}
void function()
{
	using namespace std;
	double n = 5.0,sum;
	sum = sqrt(n);
	sum--;
	sum = sum / 2;
	cout << setprecision(MAX);
	cout.setf(ios_base::fixed,ios_base::showpos);
	cout << sum;
}
