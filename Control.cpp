#include "stdafx.h"
#include "Control.h"
#include "MyFounction.h"
CString number2char(int number);
int Product2point(int products,int spaceY,int spaceProductY);
void DrawIco(CDC *pDC,int x,int y,int type,COLORREF color);

CControl::CControl(void)
{
	//��ʼ������
	InitData();
}


CControl::~CControl(void)
{
	//�ͷ��ڴ�
	delete m_chart;
	for (int i = 0; i < 3; i++)
	{
		delete m_product[i];
	}
}

void CControl::InitData()
{
	//��Ʒ����
	m_productNum=3;
	//ʵ����һ��ͼ�����
	m_chart=new CChart;
	//Y���
	spaceY=20;
	//X���
	spaceX=50;
	//���µĶ�λ�ǵ�
	left_bottom.x=220;
	left_bottom.y=220;
	//��������
	over=3;
	//ʵ����������Ʒ����
	for (int i = 0; i < 3; i++)
	{
		m_product[i] = new CProduct();
		m_product[i]->m_line= new CLine();
		m_product[i]->m_icoType=i;
	}
	m_product[0]->m_color=RGB(255,0,0);
	m_product[0]->m_pen.CreatePen(PS_SOLID,2,RGB(255,0,0));
	m_product[0]->m_products[0]=40;
	m_product[0]->m_products[1]=37;
	m_product[0]->m_products[2]=23;
	m_product[0]->m_products[3]=23;
	m_product[0]->m_products[4]=40;
	m_product[1]->m_color=RGB(0,255,0);
	m_product[1]->m_pen.CreatePen(PS_SOLID,2,RGB(0,255,0));
	m_product[1]->m_products[0]=30;
	m_product[1]->m_products[1]=26;
	m_product[1]->m_products[2]=27;
	m_product[1]->m_products[3]=35;
	m_product[1]->m_products[4]=24;
	m_product[2]->m_color=RGB(0,0,255);
	m_product[2]->m_pen.CreatePen(PS_SOLID,2,RGB(0,0,255));
	m_product[2]->m_products[0]=28;
	m_product[2]->m_products[1]=21;
	m_product[2]->m_products[2]=38;
	m_product[2]->m_products[3]=37;
	m_product[2]->m_products[4]=21;
}

void CControl::DrawRight(CDC* pDC)
{
	//�ı��������
	pDC->SetTextAlign(TA_LEFT);
	//���Ͻ�����
	POINT left_top;
	left_top.x=left_bottom.x+spaceX*5+5;
	left_top.y=left_bottom.y-100;
	CString str;
	for (int i = 0; i < m_productNum; i++)
	{
		//��Ʒ�����Լ��Ļ��ʻ�����
		m_product[i]->m_line->DrawSlf(pDC,left_top.x,left_top.y+i*15,left_top.x+19,left_top.y+i*15,&m_product[i]->m_pen);
		/*//ѡ��ò�Ʒ�Ļ���
		pDC->SelectObject(m_product[i]->m_pen);
		//������
		pDC->MoveTo(left_top.x,left_top.y+i*15);
		pDC->LineTo(left_top.x+19,left_top.y+i*15);*/
		//��ICOͼ��
		DrawIco(pDC,left_top.x+10,left_top.y+i*15,m_product[i]->m_icoType,m_product[i]->m_color);
		//��ʽ���ı���Ϣ
		str.Format(_T("��Ʒ%d"),i+1);
		//���ı�
		pDC->TextOut(left_top.x+20,left_top.y-8+i*15,str);
	}
}

void CControl::DrawChart(CDC* pDC)
{
	//���ߵĻ���
	CPen pen;
	//ʵ�ߡ����1����ɫ
	pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	//��ʮ�����ߣ�����X�ᣩ��Y��̶�
	for (int i = 0; i < 10; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x-over,left_bottom.y-spaceY*i,left_bottom.x+spaceX*5,left_bottom.y-spaceY*i,&pen);
	}
	//��Y��
	m_chart->m_line->DrawSlf(pDC,left_bottom.x,left_bottom.y+over,left_bottom.x,left_bottom.y-spaceY*9,&pen);
	//��X��������̶�
	for (int i = 0; i < 6; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x+spaceX*i,left_bottom.y,left_bottom.x+spaceX*i,left_bottom.y+over,&pen);
	}
	//�ı�
	CString str;
	//�����ı����Ҷ���
	pDC->SetTextAlign(TA_RIGHT);
	//��Y��ʮ���̶�����
	for (int i = 0; i < 10; i++)
	{
		//��ʽ���ַ�
		str.Format(_T("%d"),5*i);
		//����
		pDC->TextOut(left_bottom.x-over-1,left_bottom.y-spaceY*i-spaceY/2,str);
	}

	//���þ�����ʾ
	pDC->SetTextAlign(TA_CENTER);
	//��ʼ��title
	str="������������ͼ";
	//����title
	pDC->TextOut(left_bottom.x+spaceX*5/2,left_bottom.y-spaceY*10,str);
	//X������·�
	for (int i = 0; i < 5; i++)
	{
		//����
		pDC->TextOut(left_bottom.x+spaceX/2+spaceX*i,left_bottom.y+over+2,number2char(i+1)+_T("��"));
	}
}

void CControl::DrawProducts(CDC *pDC)
{
	//ʵ����һ֧��
	//CPen newpen;
	//���ñʵ�����
	//newpen.CreatePen(PS_SOLID,2,m_product1->m_color);
	//brush.CreateSolidBrush(2,m_product1->m_color);
	//ѡ����ֻ��
	//����Ʒ
	for (int j = 0; j < m_productNum; j++)
	{
		//ѡ�иò�Ʒ�Ļ���
		pDC->SelectObject(&m_product[j]->m_pen);
		//���ĸ�����
		for (int i = 0; i < 5-1; i++)
			{
				//��ȡ������Ʒ����
				int pro1=m_product[j]->m_products[i];
				int pro2=m_product[j]->m_products[i+1];
				//��ȡ��Ӧ������
				int x1=left_bottom.x+spaceX/2+spaceX*i;
				int y1=left_bottom.y-Product2point(m_product[j]->m_products[i],spaceY,5);
				int x2=left_bottom.x+spaceX/2+spaceX*(i+1);
				int y2=left_bottom.y-Product2point(m_product[j]->m_products[i+1],spaceY,5);
				/*//�����ߣ����������ߣ�
				pDC->MoveTo(x1,y1);
				pDC->LineTo(x2,y2);*/
				//��Ʒ�����Լ����ʵķ���������
				m_product[j]->m_line->DrawSlf(pDC,x1,y1,x2,y2,&m_product[j]->m_pen);
				//��ICO
				DrawIco(pDC,x1,y1,m_product[j]->m_icoType,m_product[j]->m_color);
				//�������һ�����ߵ�ʱ����Ҫ�����һ����
				if (i==5-1-1)
				{
					DrawIco(pDC,x2,y2,m_product[j]->m_icoType,m_product[j]->m_color);
				}
			}
	}
}