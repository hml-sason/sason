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
class play
{
	public:
		void main_func();
	private:
		int randrange(int a, int b);
		void k(int dn,int zf);
}; 
int main()
{
	play player;
	player.main_func();
	return 0;
}
int play::randrange(int a, int b)
{
	srand(time(NULL));
	return rand()%(b-a+1)+a;
}
void play::main_func()
{
	int dn;
	double wj = 0,zf = 0;
	bool w = true;
	char yn;
	dn = randrange(15,25);
	do
	{
		wj=randrange(1,13);
		if(wj - 10 > 0){
			wj = 0.5;
		}
		else wj=wj;
		zf = zf + wj;
		cout << "��õ���" << wj << "��" << endl;
		if(zf > 21){
			cout << "�������";
			w = false;
			break;
		}
		cout << "�Ƿ����" << endl;
		cin >> yn;
	}while(yn!='n');
	if(w) k(dn,zf);
}
void play::k(int dn,int zf)
{
	cout << "���ԣ�"<< dn << endl;
	cout << "��ķ�����" << zf << endl;
	if(dn>21){ 
	cout << "���Գ�����" << endl;
	cout << "��Ӯ��" << endl;
	} 
	else{
	if(dn>zf)cout << "����:Ӯ��" << endl;
	else if(zf>dn)cout << "��:Ӯ��" << endl;
	else cout << "���Ժ��㣺ƽ����" << endl;
}
}
