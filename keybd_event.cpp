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
#include<windows.h>
using namespace std;
int main()
{
	char a;
	keybd_event(96,0,0,0);
	keybd_event(13,0,0,0);
	keybd_event(13,0,KEYEVENTF_KEYUP,0);
	keybd_event(96,0,KEYEVENTF_KEYUP,0);
	cin >> a;
	if(a == '0') 
	{
		cout << "right" << endl;
	}
	return 0;
}
