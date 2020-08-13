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
#include<list>
#include<map>
using namespace std;
int n,p,m,s;
int a[201],w[201],b[201];
int main()
{
	ios::sync_with_stdio(false);
	for(int i = 0;i <= 100;i++)
	{
		a[i] = 1;
	}
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> w[i];
	}
	cin >> m; 
	for(int i = 1;i <= m;i++)
	{
		cin >> b[i];
		w[b[i]] = 0;
	}
	p = 0;
	for(int i = 1;i <= n;i++)
	{
		if(w[i] != 0)
		{
			p++;
			a[p] = w[i];
		}
	}
	int t = 0;
	for(int i = 1;i <= p - 1;i++)
	{
		t = t + a[i] * a[i + 1];
	}
	cout << t << endl;
	return 0;
}
