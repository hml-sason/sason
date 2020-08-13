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
int s,n,k;
int a[500001],b[500001],t[500001];
int main(){
	ios::sync_with_stdio(false);
    cin >> s >> n;
    for(int i = 1;i <= n;i++)
    {
    	cin >> a[i] >> b[i] >> t[i];
	}
	for(int i = 1;i <= n;i++)
	{
		if(i == 1&&a[i] != 1) k = k + a[i] - 1;
		else if(a[i] != b[i - 1]&&i != 1) k = k + a[i] - b[i - 1] - 1;
		k = k + (b[i] - a[i] + 1) * t[i];
	}
	if(b[n] != s) k = k + s - b[n];
	cout << k << endl;
    return 0;
}
