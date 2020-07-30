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
#include<windows.h> 
using namespace std;
void EnableDebugPriv() {
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, NULL, NULL);
	CloseHandle(hToken);
}
int main()
{
	EnableDebugPriv(); 
	HWND window = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(window,false);
	HMENU hMenu1 = GetMenu(window);
	DestroyMenu(hMenu1);
	//DrawMenuBar(window);
	DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
	DrawMenuBar(window);
	CloseHandle(GetStdHandle(STD_INPUT_HANDLE));
	CloseHandle(GetStdHandle(STD_OUTPUT_HANDLE));
	while(1){
	}
	return 0;
}

