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
using namespace std;
int js(int* q,int size,int key)
{
    if (q == NULL || size == 0)
        return -1;
    int low = 0;
    int high = key - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (q[mid] < key)
            low = mid + 1;
        else if (q[mid] > key)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int array[10] = { 1,2,3,4,5,6,7,8,9,0 };
    int size,x;
    cin >> x;
    cout << js(array, 10, x);
	return 0;
}