#include<stdio.h>
#include<conio.h>
#include<windows.h>
//����ȫ�ֱ���
HANDLE hOut;
int high,width;			//�߽� 
int bird_x,bird_y; 		//С������
int bar_y;		//��������
int bar_xTop,bar_xDown;		//���忪���������� 
int score;				//�÷� 
 
void HideCursor()		//���ع�� 
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0};
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x,int y) //����ƶ���(x,y)λ��
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void startup()			//���ݳ�ʼ�� 
{
	high=18;			//��ʼ���߽� 
	width=26;
	
	bird_x=high/2; 		//��ʼ��С������ 
	bird_y=width/2;
	
	bar_y=width;		//��������
	
	bar_xTop=high/2;			//���忪�� 
	bar_xDown=bar_xTop+4;
	
	score=0;				//�÷� 
	  
	HideCursor();		//���ع�� 
}
void show()				//��ʾ���� 
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
			if((i==bird_x)&&(j==bird_y))		//���С��@ 
				printf("@");
			else if(i==high+1)					//����±߽� 
					printf("_");
			else if(j==width) 					//����ұ߽� 
					printf("|");
			else if((j==bar_y)&&((i<=bar_xTop)||(i>=bar_xDown))) 		//������� 
					printf("|");
			else printf(" ");
		}
		printf("\n"); 
	}
	printf("�÷֣�%d\n",score);
} 
void updateWithoutInput()		//���û������޹صĸ��� 
{
	if(bird_y==bar_y-1)						 
	{
		if((bird_x>bar_xTop)&&(bird_x<bar_xDown))		//С��ͨ�����忪�ڼӷ�
		score++;
		else
		{
			printf("С������\n");						//С��ûûͨ�����忪��С������ 
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
		printf("С������\n");
		exit(0);
	}
	
	Sleep(200); 
}
void updateWithInpute()			//���û������йصĸ��� 
{
	//char input;
	
	if(kbhit())
	{
		//input=getch();
		if(GetAsyncKeyState(VK_SPACE)&&(bird_x>0)&&(bird_x<=high))	//С�������� 
			bird_x=bird_x-2;
	}
}
int main()
{
	SetConsoleTitle("flappy bird game");
	startup();			//���ݳ�ʼ�� 
	while(1)
	{
		show();				//��ʾ���� 
		updateWithoutInput();		//���û������޹صĸ���
		updateWithInpute();			//���û������йصĸ��� 
	}
} 
