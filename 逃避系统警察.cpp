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
int n;
int ax,bx,ay,by,x,y;
int js(int x1,int y1);
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> ax >> ay;
		cin >> bx >> by;
		x = abs(ax - bx);
		y = abs(ay - by);			//�ؼ�����ʽ����ͬһ�������У���abs(ax-bx)��abs(ay-by)��һ����Լ����������������ֱ���Ͼͻ��������㡣 
		if(js(x,y) == 1) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
int js(int x1,int y1)
{
	if(y1 != 0) return js(y,x1 % y1);
	else return x1;
}
