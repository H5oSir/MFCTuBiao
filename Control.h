#pragma once
#include "Product.h"
#include "Chart.h"
class CControl
{
public:
	CControl(void);
	~CControl(void);
	//��ʼ������
	void InitData();
	//����ͼ��
	void DrawChart(CDC* pDC);
	//�����Ҳ��Ʒ��Ϣ
	void DrawRight(CDC* pDC);
	//���Ʋ�Ʒ����
	void DrawProducts(CDC *pDC);
public:
	//ͼ��
	CChart *m_chart;
	//Y���
	int spaceY;
	//X���
	int spaceX;
	//���µĶ�λ�ǵ�
	POINT left_bottom;
	//��������
	int over;
	//ʵ����������Ʒ����
	CProduct *m_product[3];
	//��Ʒ����
	int m_productNum;
};

