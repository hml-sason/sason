#include<stdio.h>
#include<conio.h>
#include<windows.h>
//定义全局变量
HANDLE hOut;
int high,width;			//边界 
int bird_x,bird_y; 		//小鸟坐标
int bar_y;		//挡板坐标
int bar_xTop,bar_xDown;		//挡板开口上下坐标 
int score;				//得分 
 
void HideCursor()		//隐藏光标 
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0};
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x,int y) //光标移动到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void startup()			//数据初始化 
{
	high=18;			//初始化边界 
	width=26;
	
	bird_x=high/2; 		//初始化小鸟坐标 
	bird_y=width/2;
	
	bar_y=width;		//挡板坐标
	
	bar_xTop=high/2;			//挡板开口 
	bar_xDown=bar_xTop+4;
	
	score=0;				//得分 
	  
	HideCursor();		//隐藏光标 
}
void show()				//显示界面 
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
                            FOREGROUND_RED | 
                            FOREGROUND_GREEN |
                            FOREGROUND_INTENSITY);
	int i,j;
	gotoxy(0,0); 
	for(i=0;i<=high+1;i++)
	{
		for(j=0;j<=width;j++)
		{
			if((i==bird_x)&&(j==bird_y))		//输出小鸟@ 
				printf("@");
			else if(i==high+1)					//输出下边界 
					printf("_");
			else if(j==width) 					//输出右边界 
					printf("|");
			else if((j==bar_y)&&((i<=bar_xTop)||(i>=bar_xDown))) 		//输出挡板 
					printf("|");
			else printf(" ");
		}
		printf("\n"); 
	}
	printf("得分：%d\n",score);
} 
void updateWithoutInput()		//与用户输入无关的更新 
{
	if(bird_y==bar_y-1)						 
	{
		if((bird_x>bar_xTop)&&(bird_x<bar_xDown))		//小鸟通过挡板开口加分
		score++;
		else
		{
			printf("小鸟死亡\n");						//小鸟没没通过挡板开口小鸟死亡 
			exit(0);
		}
	}
		
	if(bar_y>0)
		bar_y--;
	else
	{
		bar_y=width;
		bar_xTop=rand()%(high-4);
		bar_xDown=bar_xTop+4;
	}
	if(bird_x<high+1)
		bird_x++;
	else
	{
		printf("小鸟死亡\n");
		exit(0);
	}
	
	Sleep(200); 
}
void updateWithInpute()			//与用户输入有关的更新 
{
	//char input;
	
	if(kbhit())
	{
		//input=getch();
		if(GetAsyncKeyState(VK_SPACE)&&(bird_x>0)&&(bird_x<=high))	//小鸟向上跳 
			bird_x=bird_x-2;
	}
}
int main()
{
	SetConsoleTitle("flappy bird game");
	startup();			//数据初始化 
	while(1)
	{
		show();				//显示界面 
		updateWithoutInput();		//与用户输入无关的更新
		updateWithInpute();			//与用户输入有关的更新 
	}
} 
