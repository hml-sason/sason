#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int sum(int n);
int main()
{
    int n;
    cin >> n;
    cout << sum(n);
	return 0;
}
int sum(int n)
{
    if (n > 0)
    {
        return  (sum(n - 1) + n);
    }
    else
    {
        return 0;
    }
}