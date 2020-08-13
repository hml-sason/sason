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
#define inf 0x3f3f3f3f
int n,m,h[30],ans,mazz,a,minn,pos;
int main(){
	ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a;
        minn = inf;
        for(int j=1; j+a-1<=m; j++) {
        mazz=0;
            for(int k=1; k<=a; k++)
                mazz=max(mazz,h[k+j-1]);
            if(mazz<minn)minn=mazz,pos=j;
        }
        for(int i=1;i<=a;i++)h[i+pos-1]=minn+a;
    }
    for(int i=1; i<=n; i++)
        ans = max(ans,h[i]);		//¾­µä´òÀÞÌ¨ 
    cout << ans << endl;
    return 0;
}
