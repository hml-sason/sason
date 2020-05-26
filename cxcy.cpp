#include<windows.h>
#include<iostream> 
int main()
{
	int cx = GetSystemMetrics(SM_CXSCREEN);
    int cy = GetSystemMetrics(SM_CYSCREEN);
	std::cout << cx << " " << cy; 
	return 0;
 } 
