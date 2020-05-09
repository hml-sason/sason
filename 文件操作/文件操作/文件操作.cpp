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
#include<fstream>
using namespace std;
int main()
{
	int a[1001][1001];
	ofstream fout("out.txt");
	for (int i = 1; i <= 999; i++)
	{
		for (int j = 1; j <= 999; j++)
		{
			fout << 6;
		}
		fout << endl;
	}
	fout.close();
	return 0;
}
