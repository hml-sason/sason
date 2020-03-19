#include<iostream>
using std::cout;
using std::cin;
int main(){    
	int n,x,y;    
	int m = -1;    
	cin >> n >> x >> y;  
	if(y <= n * x) 
    {        
	   if(y % x > 0)            
	   m = n - (y / x + 1);        
	else            
	   m  = n - (y / x);    
	}    
	cout << m; 
	cout.good();
	return 0;
}

