#include <time.h>
#include <graphics.h>

#include "fireworks.h"

#define NUM_FIREWORKS 12	//�̻�������12���ұȽϺã�����̫�ܼ�

int main()
{
	initgraph(896, 896, INIT_RENDERMANUAL);

	srand((unsigned)time(NULL));

	//�̻�
	Fireworks* fireworks = new Fireworks[NUM_FIREWORKS];

	//����ͼ��896 x 896)
	PIMAGE bgPimg = newimage();
	getimage(bgPimg, "privateinvestocat.jpg");
	//�Ȼ���һ�£���Ȼǰ���пհ���
	putimage(0, 0, bgPimg);
	delay_ms(0);

	//��������
	MUSIC bgMusic;
	bgMusic.OpenFile("Michael Jackson - We Are the World (Demo).mp3");
	bgMusic.SetVolume(1.0f);
	if (bgMusic.IsOpen()) {
		bgMusic.Play(0);
	}

	
	//ͼ�񻺴�, ��ΪҪ�ӱ���ͼ��ֱ�Ӽ�ģ���˾���ѱ���ͼģ����
	//��������һ��ͼ�񻺴��������̻�����ģ���˾����ٻ��Ƶ�����
	PIMAGE cachePimg = newimage(896, 896);
	
	//��ʱ�ã���Ҫ������ʱ������ֲ���
	int timeCount = 0;

	for (; is_run(); delay_fps(60))
	{
		//��1����һ�£�����������ˣ����²���
		if ((++timeCount % 60 == 0) && (bgMusic.GetPlayStatus() == MUSIC_MODE_STOP)) {
			bgMusic.Play(0);
		}
		//����λ��
		for (int i = 0; i < NUM_FIREWORKS; i++) {
			fireworks[i].update();
		}

		//���Ʊ���
		putimage(0, 0, bgPimg);

		//�����̻���ͼ�񻺴���
		for (int i = 0; i < NUM_FIREWORKS; i++) {
			fireworks[i].draw(cachePimg);
		}

		//ģ���˾�����βЧ��
		//�ڶ���������ģ���ȣ�Խ��Խģ��������Ҳ��Խ��
		//���������������ȣ�Խ����βԽ��
		//��������һ�������������䣬�������¼��飺
		//0x03, 0xff
		//0x0b, 0xe0
		//0xff, 0xff
		imagefilter_blurring(cachePimg, 0x0a, 0xff);

		//������Ƶ����ڣ�ģʽΪ��������ɫ = ����������ɫ Or ͼ��������ɫ), ������ɫ���������
		putimage(0, 0, cachePimg, SRCPAINT);

	}

	delete[] fireworks;

	delimage(bgPimg);
	delimage(cachePimg);

	bgMusic.Close();

	closegraph();

	return 0;
}

