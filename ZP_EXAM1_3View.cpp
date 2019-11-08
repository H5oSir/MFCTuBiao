
// ZP_EXAM1_3View.cpp : CZP_EXAM1_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ZP_EXAM1_3.h"
#endif

#include "ZP_EXAM1_3Doc.h"
#include "ZP_EXAM1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//自己的全局函数
/*
CString number2char(int number);
int Product2point(int products,int spaceY,int spaceProductY);
void DrawIco(CDC *pDC,int x,int y,int type,COLORREF color);*/
/*
CString number2char(int number)
{
	switch (number)
	{
	case 0:
		return _T("零");
	case 1:
		return _T("一");

	case 2:
		return _T("二");
	case 3:
		return _T("三");
	case 4:
		return _T("四");
	case 5:
		return _T("五");
	case 6:
		return _T("六");
	case 7:
		return _T("七");
	case 8:
		return _T("八");
	case 9:
		return _T("九");
	case 10:
		return _T("十");
	case 11:
		return _T("十一");
	case 12:
		return _T("十二");
	default:
		break;
	}
	return _T("NULL");
}

int Product2point(int products,int spaceY,int spaceProductY)
{
	return products*spaceY/spaceProductY;
}

void DrawIco(CDC *pDC,int x,int y,int type,COLORREF color)
{
	CBrush brush(color);
	brush.CreateObject();
	pDC->SelectObject(brush);
	int space=5;
	if (type==0)
	{
		pDC->Rectangle(x-space,y-space,x+space,y+space);
	}
	else if (type==1)
	{
		pDC->Ellipse(x-space,y-space,x+space,y+space);
	}
	else if (type==2)
	{
		pDC->Ellipse(x-space,y-space,x+space,y+space);
		//pDC->AngleArc(x,);
	}
}
*/



// CZP_EXAM1_3View

IMPLEMENT_DYNCREATE(CZP_EXAM1_3View, CView)

BEGIN_MESSAGE_MAP(CZP_EXAM1_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CZP_EXAM1_3View 构造/析构

CZP_EXAM1_3View::CZP_EXAM1_3View()
{
	// TODO: 在此处添加构造代码
	/*m_chart=new CChart;
	//Y宽度
	spaceY=20;
	//X宽度
	spaceX=50;
	//左下的定位角点
	left_bottom.x=220;
	left_bottom.y=220;
	//超出部分
	over=3;
	//实例化一个产品对象
	m_product1 = new CProduct();
	//初始化数据
	m_product1->m_color=RGB(255,0,0);
	m_product1->m_line=new CLine();
	m_product1->m_products[0]=40;
	m_product1->m_products[1]=37;
	m_product1->m_products[2]=23;
	m_product1->m_products[3]=23;
	m_product1->m_products[4]=40;*/
	m_control=new CControl();

}

CZP_EXAM1_3View::~CZP_EXAM1_3View()
{
	delete m_control;
}

BOOL CZP_EXAM1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CZP_EXAM1_3View 绘制

void CZP_EXAM1_3View::OnDraw(CDC* pDC)
{
	CZP_EXAM1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	
	m_control->DrawChart(pDC);
	m_control->DrawProducts(pDC);
	m_control->DrawRight(pDC);

	/*//画线的画笔
	CPen pen;
	//实线、宽度1、黑色
	pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	//画10个横线
	for (int i = 0; i < 10; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x-over,left_bottom.y-spaceY*i,left_bottom.x+spaceX*5,left_bottom.y-spaceY*i,&pen);
	}
	//画1个竖线
	m_chart->m_line->DrawSlf(pDC,left_bottom.x,left_bottom.y+over,left_bottom.x,left_bottom.y-spaceY*9,&pen);
	//画6个刻度
	for (int i = 0; i < 6; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x+spaceX*i,left_bottom.y,left_bottom.x+spaceX*i,left_bottom.y+over,&pen);
	}
	//文本
	CString str;
	//设置文本向右对齐
	pDC->SetTextAlign(TA_RIGHT);
	//画Y轴10个刻度文本数字
	for (int i = 0; i < 10; i++)
	{
		//格式化字符
		str.Format(_T("%d"),5*i);
		//绘制
		pDC->TextOut(left_bottom.x-over-1,left_bottom.y-spaceY*i-spaceY/2,str);
	}
	//设置居中显示
	pDC->SetTextAlign(TA_CENTER);
	//画title
	str="车床生产数据图";
	//绘制
	pDC->TextOut(left_bottom.x+spaceX*5/2,left_bottom.y-spaceY*10,str);
	//X轴绘制月份
	for (int i = 0; i < 5; i++)
	{
		//绘制
		pDC->TextOut(left_bottom.x+spaceX/2+spaceX*i,left_bottom.y+over+2,number2char(i+1)+_T("月"));
	}*/

	/*//实例化一个产品对象
	CProduct *m_product1 = new CProduct();
	//初始化数据
	m_product1->m_color=RGB(255,0,0);
	m_product1->m_line=new CLine();
	m_product1->m_products[0]=40;
	m_product1->m_products[1]=37;
	m_product1->m_products[2]=23;
	m_product1->m_products[3]=23;
	m_product1->m_products[4]=40;*/
	//实例化一支笔
	/*
	CPen newpen;
	//设置笔的属性
	newpen.CreatePen(PS_SOLID,2,m_product1->m_color);
	//brush.CreateSolidBrush(2,m_product1->m_color);
	//选中这只笔
	pDC->SelectObject(&newpen);
	//绘制产品曲线
	for (int i = 0; i < 5-1; i++)
	{
		int pro1=m_product1->m_products[i];
		int pro2=m_product1->m_products[i+1];
		int x1=left_bottom.x+spaceX/2+spaceX*i;
		int y1=left_bottom.y-Product2point(m_product1->m_products[i],spaceY,5);
		int x2=left_bottom.x+spaceX/2+spaceX*(i+1);
		int y2=left_bottom.y-Product2point(m_product1->m_products[i+1],spaceY,5);
		pDC->MoveTo(x1,y1);
		pDC->LineTo(x2,y2);

		DrawIco(pDC,x1,y1,0,m_product1->m_color);
		if (i==5-1-1)
		{
			DrawIco(pDC,x2,y2,0,m_product1->m_color);
		}
		//m_product1->DrawSlf(pDC);
	}
	*/
	//绘制右侧产品信息
	/*pDC->SetTextAlign(TA_LEFT);
	POINT left_top;
	left_top.x=left_bottom.x+spaceX*5+5;
	left_top.y=left_bottom.y-100;
	pDC->MoveTo(left_top);
	pDC->LineTo(left_top.x+19,left_top.y);
	DrawIco(pDC,left_top.x+10,left_top.y,0,m_product1->m_color);
	pDC->TextOut(left_top.x+20,left_top.y-8,_T("产品1"));*/

}


// CZP_EXAM1_3View 打印

BOOL CZP_EXAM1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CZP_EXAM1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CZP_EXAM1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CZP_EXAM1_3View 诊断

#ifdef _DEBUG
void CZP_EXAM1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CZP_EXAM1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZP_EXAM1_3Doc* CZP_EXAM1_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZP_EXAM1_3Doc)));
	return (CZP_EXAM1_3Doc*)m_pDocument;
}
#endif //_DEBUG


/*
//自定义区
void CZP_EXAM1_3View::DrawRight(CDC* pDC)
{
	pDC->SetTextAlign(TA_LEFT);
	POINT left_top;
	left_top.x=left_bottom.x+spaceX*5+5;
	left_top.y=left_bottom.y-100;
	pDC->MoveTo(left_top);
	pDC->LineTo(left_top.x+19,left_top.y);
	DrawIco(pDC,left_top.x+10,left_top.y,0,m_product1->m_color);
	pDC->TextOut(left_top.x+20,left_top.y-8,_T("产品1"));
}
void CZP_EXAM1_3View::DrawChart(CDC* pDC)
{
	//画线的画笔
	CPen pen;
	//实线、宽度1、黑色
	pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	//画10个横线
	for (int i = 0; i < 10; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x-over,left_bottom.y-spaceY*i,left_bottom.x+spaceX*5,left_bottom.y-spaceY*i,&pen);
	}
	//画1个竖线
	m_chart->m_line->DrawSlf(pDC,left_bottom.x,left_bottom.y+over,left_bottom.x,left_bottom.y-spaceY*9,&pen);
	//画6个刻度
	for (int i = 0; i < 6; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x+spaceX*i,left_bottom.y,left_bottom.x+spaceX*i,left_bottom.y+over,&pen);
	}
	//文本
	CString str;
	//设置文本向右对齐
	pDC->SetTextAlign(TA_RIGHT);
	//画Y轴10个刻度文本数字
	for (int i = 0; i < 10; i++)
	{
		//格式化字符
		str.Format(_T("%d"),5*i);
		//绘制
		pDC->TextOut(left_bottom.x-over-1,left_bottom.y-spaceY*i-spaceY/2,str);
	}
	//设置居中显示
	pDC->SetTextAlign(TA_CENTER);
	//画title
	str="车床生产数据图";
	//绘制
	pDC->TextOut(left_bottom.x+spaceX*5/2,left_bottom.y-spaceY*10,str);
	//X轴绘制月份
	for (int i = 0; i < 5; i++)
	{
		//绘制
		pDC->TextOut(left_bottom.x+spaceX/2+spaceX*i,left_bottom.y+over+2,number2char(i+1)+_T("月"));
	}
}

void CZP_EXAM1_3View::DrawProducts(CDC *pDC)
{
	//实例化一支笔
	CPen newpen;
	//设置笔的属性
	newpen.CreatePen(PS_SOLID,2,m_product1->m_color);
	//brush.CreateSolidBrush(2,m_product1->m_color);
	//选中这只笔
	pDC->SelectObject(&newpen);
	//绘制产品曲线
	for (int i = 0; i < 5-1; i++)
	{
		int pro1=m_product1->m_products[i];
		int pro2=m_product1->m_products[i+1];
		int x1=left_bottom.x+spaceX/2+spaceX*i;
		int y1=left_bottom.y-Product2point(m_product1->m_products[i],spaceY,5);
		int x2=left_bottom.x+spaceX/2+spaceX*(i+1);
		int y2=left_bottom.y-Product2point(m_product1->m_products[i+1],spaceY,5);
		pDC->MoveTo(x1,y1);
		pDC->LineTo(x2,y2);

		DrawIco(pDC,x1,y1,0,m_product1->m_color);
		if (i==5-1-1)
		{
			DrawIco(pDC,x2,y2,0,m_product1->m_color);
		}
		//m_product1->DrawSlf(pDC);
	}
}*/
// CZP_EXAM1_3View 消息处理程序
