#include <cmath>
#define SHOW_CONSOLE
#include "fireworks.h"

const double Fireworks::particleSpeed = 3.0f;

Fireworks::Fireworks()
{
	init();
}

void Fireworks::init()
{
	delayTime = rand() % 300 + 20;
	riseTime = rand() % 80 + 160;
	bloomTime = 160;

	risePos.x = rand() % 450 + 300.0f;
	risePos.y = GROUND;

	riseSpeed.y = myrand(1.0f) - 3.0f;	//�����ٶȣ���������ϵ��Ҫ�Ǹ���
	riseSpeed.x = myrand(0.4f) - 0.2f;	//����΢��б

	//�����ɫ
	color = HSVtoRGB(myrand(360.0f), 1.0f, 1.0f);

	//��ÿһ���������ó�ʼ�ٶ�
	for (int i = 0; i < NUM_PARTICLE - 1; i += 2)
	{
		//Ϊ����״ɢ�������ʼ�ٶȴ�С���
		//��ʼ����ٶ�ˮƽ�ǶȺʹ�ֱ�Ƕȣ���Ϊ������ƽ��ģ�������x, y���ٶ�
		double levelAngle = randomf() * 360;
		double verticalAngle = randomf() * 360;

		//�ٶ�ͶӰ��xOyƽ��
		double xySpeed = particleSpeed * cos(verticalAngle);

		//��x, y���ٶ�
		p[i].speed.x = xySpeed * cos(levelAngle);
		p[i].speed.y = xySpeed * sin(levelAngle);

		//�����غ㣬ÿ���ٶȷ���
		if (i + 1 < NUM_PARTICLE) {
			p[i + 1].speed.x = -p[i].speed.x;
			p[i + 1].speed.y = -p[i].speed.y;
		}
	}
}

void Fireworks::draw(PIMAGE pimg)
{
	//δ��ʼ
	if (delayTime > 0)
		return;
	//�̻������׶�
	else if (riseTime > 0) {
		setfillcolor(color, pimg);
		//���ĸ��㣬������һЩ
		bar(risePos.x, risePos.y, risePos.x + 2, risePos.y + 2, pimg);
	}
	//�̻����Ž׶�
	else {
		setfillcolor(color, pimg);
		for (int i = 0; i < NUM_PARTICLE; i++) {
			bar(p[i].pos.x, p[i].pos.y, p[i].pos.x + 2, p[i].pos.y + 2, pimg);
		}
	}
}

//����λ�õ��������
void Fireworks::update()
{
	if (delayTime-- > 0)
		return;
	//���������׶Σ�ֻ�����̻�λ��
	else if (riseTime > 0) {
		risePos.x += riseSpeed.x;
		risePos.y += riseSpeed.y;

		//��������
		riseSpeed.y += 0.005;

		//������ϣ����ﱬը�׶�
		if (--riseTime <= 0) {
			//�����ӳ�ʼλ��Ϊ�̻���ǰλ��
			for (int i = 0; i < NUM_PARTICLE; i++) {
				p[i].pos.x = risePos.x;
				p[i].pos.y = risePos.y;
			}
		}
	}
	//�̻����Ž׶�
	else if (bloomTime-- > 0) {
		//����ɢ������������λ��
		for (int i = 0; i < NUM_PARTICLE; i++) {
			p[i].pos.x += p[i].speed.x;
			p[i].pos.y += p[i].speed.y;

			//��������
			p[i].speed.y += 0.005;

			//�ٶȼ���
			p[i].speed.x *= 0.982;
			p[i].speed.y *= 0.982;
		}
	}
	else {
		//�̻����¿�ʼ
		init();
	}
}
