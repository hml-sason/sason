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
/*奖学金
问题描述
某小学最近得到了一笔赞助，
打算拿出其中一部分为学习成绩优秀的前5名学生发奖学金。
期末，每个学生都有3门课的成绩:语文、数学、英语。
先按总分从高到低排序，如果两个同学总分相同，再按语文成绩从高到低排序，
如果两个同学总分和语文成绩都相同，那么规定学号小的同学 排在前面，
这样，每个学生的排序是唯一确定的。
任务：
先根据输入的3门课的成绩计算总分，
然后按上述规则排序，
最后按排名顺序输出前五名名学生的学号和总分。
注意，在前5名同学中，每个人的奖学金都不相同，
因此，你必须严格按上述规则排序。
例如，在某个正确答案中，
如果前两行的输出数据(每行输出两个数:学号、总分) 是:
*/
