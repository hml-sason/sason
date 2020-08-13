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
int a[100100];
int n,k,sum,max1,min1,ans;
double m;
int check(int x);
int try1(int l,int r); 
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> m;
		a[i] = int(m * 100);
		sum = sum + a[i];
	}
	max1 = sum / k;
	min1 = INT_MAX;
	try1(1,max1);
	if(min1 == INT_MAX) cout << "0.00" << endl;
	else
	{
		ans = ans / 100;
		cout << fixed << setprecision(2) << double(ans) << endl;
	}
	return 0;
}
int check(int x)
{
	int y;
	y = 0;
	for(int i = 1;i <= n;i++)
	{
		y = y + a[i] / x;
	}
	return y;
}
int try1(int l,int r)
{
	int mid,t;
	if(l > r) return 0;
	mid = (l + r) / 2;
	t = check(mid);
	if(t < k) try1(l,mid - 1); 
	else
	{
		if(t < min1||((t == min1)&&(ans < mid)))
		{
			min1 = t;
			ans = mid;
		}
		try1(mid + 1,r);
	}
}
