#include "stdafx.h"
#include "Control.h"
#include "MyFounction.h"
CString number2char(int number);
int Product2point(int products,int spaceY,int spaceProductY);
void DrawIco(CDC *pDC,int x,int y,int type,COLORREF color);

CControl::CControl(void)
{
	//初始化数据
	InitData();
}


CControl::~CControl(void)
{
	//释放内存
	delete m_chart;
	for (int i = 0; i < 3; i++)
	{
		delete m_product[i];
	}
}

void CControl::InitData()
{
	//产品数量
	m_productNum=3;
	//实例化一个图表对象
	m_chart=new CChart;
	//Y宽度
	spaceY=20;
	//X宽度
	spaceX=50;
	//左下的定位角点
	left_bottom.x=220;
	left_bottom.y=220;
	//超出部分
	over=3;
	//实例化三个产品对象
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
	//文本向左对齐
	pDC->SetTextAlign(TA_LEFT);
	//左上角坐标
	POINT left_top;
	left_top.x=left_bottom.x+spaceX*5+5;
	left_top.y=left_bottom.y-100;
	CString str;
	for (int i = 0; i < m_productNum; i++)
	{
		//产品调用自己的画笔画曲线
		m_product[i]->m_line->DrawSlf(pDC,left_top.x,left_top.y+i*15,left_top.x+19,left_top.y+i*15,&m_product[i]->m_pen);
		/*//选择该产品的画笔
		pDC->SelectObject(m_product[i]->m_pen);
		//画横线
		pDC->MoveTo(left_top.x,left_top.y+i*15);
		pDC->LineTo(left_top.x+19,left_top.y+i*15);*/
		//画ICO图案
		DrawIco(pDC,left_top.x+10,left_top.y+i*15,m_product[i]->m_icoType,m_product[i]->m_color);
		//格式化文本信息
		str.Format(_T("产品%d"),i+1);
		//画文本
		pDC->TextOut(left_top.x+20,left_top.y-8+i*15,str);
	}
}

void CControl::DrawChart(CDC* pDC)
{
	//画线的画笔
	CPen pen;
	//实线、宽度1、黑色
	pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	//画十个横线（包含X轴）和Y轴刻度
	for (int i = 0; i < 10; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x-over,left_bottom.y-spaceY*i,left_bottom.x+spaceX*5,left_bottom.y-spaceY*i,&pen);
	}
	//画Y轴
	m_chart->m_line->DrawSlf(pDC,left_bottom.x,left_bottom.y+over,left_bottom.x,left_bottom.y-spaceY*9,&pen);
	//画X轴的六个刻度
	for (int i = 0; i < 6; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x+spaceX*i,left_bottom.y,left_bottom.x+spaceX*i,left_bottom.y+over,&pen);
	}
	//文本
	CString str;
	//设置文本向右对齐
	pDC->SetTextAlign(TA_RIGHT);
	//画Y轴十个刻度数字
	for (int i = 0; i < 10; i++)
	{
		//格式化字符
		str.Format(_T("%d"),5*i);
		//绘制
		pDC->TextOut(left_bottom.x-over-1,left_bottom.y-spaceY*i-spaceY/2,str);
	}

	//设置居中显示
	pDC->SetTextAlign(TA_CENTER);
	//初始化title
	str="车床生产数据图";
	//绘制title
	pDC->TextOut(left_bottom.x+spaceX*5/2,left_bottom.y-spaceY*10,str);
	//X轴绘制月份
	for (int i = 0; i < 5; i++)
	{
		//绘制
		pDC->TextOut(left_bottom.x+spaceX/2+spaceX*i,left_bottom.y+over+2,number2char(i+1)+_T("月"));
	}
}

void CControl::DrawProducts(CDC *pDC)
{
	//实例化一支笔
	//CPen newpen;
	//设置笔的属性
	//newpen.CreatePen(PS_SOLID,2,m_product1->m_color);
	//brush.CreateSolidBrush(2,m_product1->m_color);
	//选中这只笔
	//画产品
	for (int j = 0; j < m_productNum; j++)
	{
		//选中该产品的画笔
		pDC->SelectObject(&m_product[j]->m_pen);
		//画四个曲线
		for (int i = 0; i < 5-1; i++)
			{
				//获取两个产品数量
				int pro1=m_product[j]->m_products[i];
				int pro2=m_product[j]->m_products[i+1];
				//获取对应的坐标
				int x1=left_bottom.x+spaceX/2+spaceX*i;
				int y1=left_bottom.y-Product2point(m_product[j]->m_products[i],spaceY,5);
				int x2=left_bottom.x+spaceX/2+spaceX*(i+1);
				int y2=left_bottom.y-Product2point(m_product[j]->m_products[i+1],spaceY,5);
				/*//画曲线（两个点连线）
				pDC->MoveTo(x1,y1);
				pDC->LineTo(x2,y2);*/
				//产品调用自己画笔的方法画曲线
				m_product[j]->m_line->DrawSlf(pDC,x1,y1,x2,y2,&m_product[j]->m_pen);
				//画ICO
				DrawIco(pDC,x1,y1,m_product[j]->m_icoType,m_product[j]->m_color);
				//当画最后一根曲线的时候，需要画最后一个点
				if (i==5-1-1)
				{
					DrawIco(pDC,x2,y2,m_product[j]->m_icoType,m_product[j]->m_color);
				}
			}
	}
}