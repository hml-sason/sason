#include<iostream>
using namespace std;
int sum(int n) 
{ 
    if(n > 0) 
    { 
        return  (sum(n-1) + n); 
    } 
    else 
    { 
        return 0; 
    } 
}
int main() 
{ 
      int n = 0; 
      cin >> n;
      cout << sum(n); 
      return 1; 
} 
