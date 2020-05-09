#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<float.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<stack> 
using namespace std;
class f
{
public:
	void g_n1();
private:
	void g_n(char mode)
	{
		while (1)
		{
			cout << "请输入游戏难度(低：E；中：M；高：H；地狱：A)：" << endl;
			cin >> mode;
			int n, x;
			if (mode == 'E')
			{
				cout << "猜数字开始了" << endl;
				n = randrange(0, 100);
				while (1)
				{
					cin >> x;
					if (x == 0)
					{
						cout << "See you next time." << endl;
						break;
					}
					else if (x > n) cout << "你猜的有点大了" << endl;
					else if (x == n)
					{
						cout << "Congratulations,you are right!" << endl;
						break;
					}
					else if (x < n) cout << "你猜的有点小了" << endl;
				}
			}
			else if (mode == 'M')
			{
				cout << "猜数字开始了" << endl;
				n = randrange(0, 150);
				while (1)
				{
					cin >> x;
					if (x == 0)
					{
						cout << "See you next time." << endl;
						break;
					}
					else if (x > n) cout << "你猜的有点大了" << endl;
					else if (x == n)
					{
						cout << "Congratulations,you are right!" << endl;
						break;
					}
					else if (x < n) cout << "你猜的有点小了" << endl;
				}
			}
			else if (mode == 'H')
			{
				cout << "猜数字开始了" << endl;
				n = randrange(0, 300);
				while (1)
				{
					cin >> x;
					if (x == 0)
					{
						cout << "See you next time." << endl;
						break;
					}
					else if (x > n) cout << "你猜的有点大了" << endl;
					else if (x == n)
					{
						cout << "Congratulations,you are right!" << endl;
						break;
					}
					else if (x < n) cout << "你猜的有点小了" << endl;
				}
			}
			else if (mode == 'A')
			{
				cout << "猜数字开始了" << endl;
				n = randrange(0, 500);
				while (1)
				{
					cin >> x;
					if (x == 0)
					{
						cout << "See you next time." << endl;
						break;
					}
					else if (x > n) cout << "你猜的有点大了" << endl;
					else if (x == n)
					{
						cout << "Congratulations,you are right!" << endl;
						break;
					}
					else if (x < n) cout << "你猜的有点小了" << endl;
				}
			}
			else if (mode == 'V')
			{
				cout << "猜数字开始了" << endl;
				cout << "Congratulations,you are find the painted eggshell!!!" << endl;
				cout << "Let's go,it's EASY and funny" << endl;
				cout << "But you don't have any tips" << endl;
				cout << "If you want to cheat,you can input the cheat code:8366" << endl;
				n = randrange(0, 1000);
				while (1)
				{
					cin >> x;
					if (x == 8366)
					{
						cout << "You are win,but you NOT a good boy" << endl;
						break;
					}
					if (x != n) cout << "Continue,please" << endl;
					else if (x == n)
					{
						cout << "Congratulations,you are right!" << endl;
						break;
					}
				}
			}
			else
			{
				cout << "您输入的模式不符合定义规则" << endl;
				cout << "请输入一次" << endl;
				continue;
			}
			break;
		}
	}
	int randrange(int a, int b)
	{
		srand(time(NULL));
		return rand() % (b - a + 1) + a;
	}
};
f st;
char mode;
int main()
{
	f& test = st;
	st.g_n1();
	return 0;
}
void f::g_n1()
{
	g_n(mode);
}