#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	long long n = 0,m = 0,sum = 0,k = 0;
	long long a[100001];
	cin >> n;
	memset(a,0,sizeof(a));
	for(int i = 1;i <= n+1;i++)
	{
		cin >> a[i];
	}
	m = a[n+1];
	for(int i = 1;i <= n;i++)
	{
		if(m == a[i]) sum++;
		if(sum == 1) k = i;
	} 
	cout << k << " " << sum;
	return 0;
}
