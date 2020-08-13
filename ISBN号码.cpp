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
const int maxn=1005;
int M,N,K,L,D;
struct data  
{
	int x,y,p,q;
};
data a[2*maxn];
struct data2  
{
	int x,y,num;
};
data2 b[2*maxn];
int X[maxn],Y[maxn];  
bool cmp(data2 aa,data2 bb)
{
	return aa.num>bb.num;
}
int main()
{
	cin >> M >> N >> K >> L >> D;
	for(int i=1;i<=D;i++)
	cin >> a[i].x >> a[i].y >> a[i].p >> a[i].q;
	memset(b,0,sizeof(b));
	for(int i=1;i<=M;i++)  
	b[i].x=i;
	for(int i=1;i<=N;i++)
	b[i+M].y=i;
	for(int i=1;i<=D;i++)  
	{
		int xx=min(a[i].x,a[i].p),yy=min(a[i].y,a[i].q);  
		if(a[i].x!=a[i].p)  b[xx].num++;
		if(a[i].y!=a[i].q)  b[yy+M].num++;
	}
	sort(b+1,b+1+M+N,cmp);  
	int cnt1=0,cnt2=0;
	for(int i=1;i<=M+N;i++)  
	{
		if(cnt1<K && b[i].x>0)  X[++cnt1]=b[i].x;
		if(cnt2<L && b[i].y>0)  Y[++cnt2]=b[i].y;
		if(cnt1==K && cnt2==L)  break;
	}
	sort(X+1,X+1+K);  
	sort(Y+1,Y+1+L);
	for(int i=1;i<=K;i++)
	{
		if(i!=K)  cout << X[i];
		else  cout << X[i];
	}
	cout << endl;
	for(int i=1;i<=L;i++)
	{
		if(i!=L)  cout << Y[i] << " ";
		else  cout << Y[i];
	}
	cout << endl;
	return 0;
}
