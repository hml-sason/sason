#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<float.h>
using namespace std;
int main()
{
	int yw[301],sx[301],yy[301],xh[301];
	int z[301];
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> yw[i] >> sx[i] >> yy[i];
		xh[i] = i;
		z[i] = yw[i] + sx[i] + yy[i];
	}
	for(int j = 1;j <=n-1;j++){
		for(int i = 1;i <= n-1;i++)
		{
			if(z[i]<z[i+1]){
				swap(z[i],z[i+1]);
				swap(yw[i],yw[i+1]);
				swap(xh[i],xh[i+1]);
		    }
		    if(z[i]==z[i+1]&&yw[i]<yw[i+1]){
		    	swap(z[i],z[i+1]);
				swap(yw[i],yw[i+1]);
				swap(xh[i],xh[i+1]);
			}
			if(z[i]==z[i+1]&&yw[i]==yw[i+1]&&xh[i]>xh[i+1])
			{
				swap(z[i],z[i+1]);
				swap(yw[i],yw[i+1]);
				swap(xh[i],xh[i+1]);
			}
    }
    } 
	for(int i = 1;i <= 5;i++)
	{
		cout << z[i] << " " << xh[i] <<endl;
	}
	return 0;
}
/*��ѧ��
��������
ĳСѧ����õ���һ��������
�����ó�����һ����Ϊѧϰ�ɼ������ǰ5��ѧ������ѧ��
��ĩ��ÿ��ѧ������3�ſεĳɼ�:���ġ���ѧ��Ӣ�
�Ȱ��ִܷӸߵ��������������ͬѧ�ܷ���ͬ���ٰ����ĳɼ��Ӹߵ�������
�������ͬѧ�ֺܷ����ĳɼ�����ͬ����ô�涨ѧ��С��ͬѧ ����ǰ�棬
������ÿ��ѧ����������Ψһȷ���ġ�
����
�ȸ��������3�ſεĳɼ������ܷ֣�
Ȼ��������������
�������˳�����ǰ������ѧ����ѧ�ź��ܷ֡�
ע�⣬��ǰ5��ͬѧ�У�ÿ���˵Ľ�ѧ�𶼲���ͬ��
��ˣ�������ϸ�������������
���磬��ĳ����ȷ���У�
���ǰ���е��������(ÿ�����������:ѧ�š��ܷ�) ��:
*/
