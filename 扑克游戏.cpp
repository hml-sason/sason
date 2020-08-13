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
int h[4],a[10000] = {0};
int n,k,l,t,ans;
int main()
{
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n - i;j++)
		{
			k = n - i - j;
			t = floor(i / 2) + floor(j / 2) + floor(k / 2);
			if(k % 2 == 1) a[t] = (a[t] + k + 1) % 10007;
			else 
			{
				a[t] = ((a[t] + k) / (2 + 1)) % 10007;
				a[t - 1] = ((a[t - 1] + k) / 2) % 10007;	
			} 
		}
	}
	for(int i = n / 2;i >= 2;i--) a[i - 1] = (a[i - 1] + a[i]) % 10007;
	for(int i = 1;i <= n / 2;i++)
	{
		cout << a[i];
	}
	return 0;
}
