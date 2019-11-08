
// ZP_EXAM1_3View.cpp : CZP_EXAM1_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ZP_EXAM1_3.h"
#endif

#include "ZP_EXAM1_3Doc.h"
#include "ZP_EXAM1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//�Լ���ȫ�ֺ���
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
		return _T("��");
	case 1:
		return _T("һ");

	case 2:
		return _T("��");
	case 3:
		return _T("��");
	case 4:
		return _T("��");
	case 5:
		return _T("��");
	case 6:
		return _T("��");
	case 7:
		return _T("��");
	case 8:
		return _T("��");
	case 9:
		return _T("��");
	case 10:
		return _T("ʮ");
	case 11:
		return _T("ʮһ");
	case 12:
		return _T("ʮ��");
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CZP_EXAM1_3View ����/����

CZP_EXAM1_3View::CZP_EXAM1_3View()
{
	// TODO: �ڴ˴���ӹ������
	/*m_chart=new CChart;
	//Y���
	spaceY=20;
	//X���
	spaceX=50;
	//���µĶ�λ�ǵ�
	left_bottom.x=220;
	left_bottom.y=220;
	//��������
	over=3;
	//ʵ����һ����Ʒ����
	m_product1 = new CProduct();
	//��ʼ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CZP_EXAM1_3View ����

void CZP_EXAM1_3View::OnDraw(CDC* pDC)
{
	CZP_EXAM1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	m_control->DrawChart(pDC);
	m_control->DrawProducts(pDC);
	m_control->DrawRight(pDC);

	/*//���ߵĻ���
	CPen pen;
	//ʵ�ߡ����1����ɫ
	pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	//��10������
	for (int i = 0; i < 10; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x-over,left_bottom.y-spaceY*i,left_bottom.x+spaceX*5,left_bottom.y-spaceY*i,&pen);
	}
	//��1������
	m_chart->m_line->DrawSlf(pDC,left_bottom.x,left_bottom.y+over,left_bottom.x,left_bottom.y-spaceY*9,&pen);
	//��6���̶�
	for (int i = 0; i < 6; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x+spaceX*i,left_bottom.y,left_bottom.x+spaceX*i,left_bottom.y+over,&pen);
	}
	//�ı�
	CString str;
	//�����ı����Ҷ���
	pDC->SetTextAlign(TA_RIGHT);
	//��Y��10���̶��ı�����
	for (int i = 0; i < 10; i++)
	{
		//��ʽ���ַ�
		str.Format(_T("%d"),5*i);
		//����
		pDC->TextOut(left_bottom.x-over-1,left_bottom.y-spaceY*i-spaceY/2,str);
	}
	//���þ�����ʾ
	pDC->SetTextAlign(TA_CENTER);
	//��title
	str="������������ͼ";
	//����
	pDC->TextOut(left_bottom.x+spaceX*5/2,left_bottom.y-spaceY*10,str);
	//X������·�
	for (int i = 0; i < 5; i++)
	{
		//����
		pDC->TextOut(left_bottom.x+spaceX/2+spaceX*i,left_bottom.y+over+2,number2char(i+1)+_T("��"));
	}*/

	/*//ʵ����һ����Ʒ����
	CProduct *m_product1 = new CProduct();
	//��ʼ������
	m_product1->m_color=RGB(255,0,0);
	m_product1->m_line=new CLine();
	m_product1->m_products[0]=40;
	m_product1->m_products[1]=37;
	m_product1->m_products[2]=23;
	m_product1->m_products[3]=23;
	m_product1->m_products[4]=40;*/
	//ʵ����һ֧��
	/*
	CPen newpen;
	//���ñʵ�����
	newpen.CreatePen(PS_SOLID,2,m_product1->m_color);
	//brush.CreateSolidBrush(2,m_product1->m_color);
	//ѡ����ֻ��
	pDC->SelectObject(&newpen);
	//���Ʋ�Ʒ����
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
	//�����Ҳ��Ʒ��Ϣ
	/*pDC->SetTextAlign(TA_LEFT);
	POINT left_top;
	left_top.x=left_bottom.x+spaceX*5+5;
	left_top.y=left_bottom.y-100;
	pDC->MoveTo(left_top);
	pDC->LineTo(left_top.x+19,left_top.y);
	DrawIco(pDC,left_top.x+10,left_top.y,0,m_product1->m_color);
	pDC->TextOut(left_top.x+20,left_top.y-8,_T("��Ʒ1"));*/

}


// CZP_EXAM1_3View ��ӡ

BOOL CZP_EXAM1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CZP_EXAM1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CZP_EXAM1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CZP_EXAM1_3View ���

#ifdef _DEBUG
void CZP_EXAM1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CZP_EXAM1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZP_EXAM1_3Doc* CZP_EXAM1_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZP_EXAM1_3Doc)));
	return (CZP_EXAM1_3Doc*)m_pDocument;
}
#endif //_DEBUG


/*
//�Զ�����
void CZP_EXAM1_3View::DrawRight(CDC* pDC)
{
	pDC->SetTextAlign(TA_LEFT);
	POINT left_top;
	left_top.x=left_bottom.x+spaceX*5+5;
	left_top.y=left_bottom.y-100;
	pDC->MoveTo(left_top);
	pDC->LineTo(left_top.x+19,left_top.y);
	DrawIco(pDC,left_top.x+10,left_top.y,0,m_product1->m_color);
	pDC->TextOut(left_top.x+20,left_top.y-8,_T("��Ʒ1"));
}
void CZP_EXAM1_3View::DrawChart(CDC* pDC)
{
	//���ߵĻ���
	CPen pen;
	//ʵ�ߡ����1����ɫ
	pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	//��10������
	for (int i = 0; i < 10; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x-over,left_bottom.y-spaceY*i,left_bottom.x+spaceX*5,left_bottom.y-spaceY*i,&pen);
	}
	//��1������
	m_chart->m_line->DrawSlf(pDC,left_bottom.x,left_bottom.y+over,left_bottom.x,left_bottom.y-spaceY*9,&pen);
	//��6���̶�
	for (int i = 0; i < 6; i++)
	{
		m_chart->m_line->DrawSlf(pDC,left_bottom.x+spaceX*i,left_bottom.y,left_bottom.x+spaceX*i,left_bottom.y+over,&pen);
	}
	//�ı�
	CString str;
	//�����ı����Ҷ���
	pDC->SetTextAlign(TA_RIGHT);
	//��Y��10���̶��ı�����
	for (int i = 0; i < 10; i++)
	{
		//��ʽ���ַ�
		str.Format(_T("%d"),5*i);
		//����
		pDC->TextOut(left_bottom.x-over-1,left_bottom.y-spaceY*i-spaceY/2,str);
	}
	//���þ�����ʾ
	pDC->SetTextAlign(TA_CENTER);
	//��title
	str="������������ͼ";
	//����
	pDC->TextOut(left_bottom.x+spaceX*5/2,left_bottom.y-spaceY*10,str);
	//X������·�
	for (int i = 0; i < 5; i++)
	{
		//����
		pDC->TextOut(left_bottom.x+spaceX/2+spaceX*i,left_bottom.y+over+2,number2char(i+1)+_T("��"));
	}
}

void CZP_EXAM1_3View::DrawProducts(CDC *pDC)
{
	//ʵ����һ֧��
	CPen newpen;
	//���ñʵ�����
	newpen.CreatePen(PS_SOLID,2,m_product1->m_color);
	//brush.CreateSolidBrush(2,m_product1->m_color);
	//ѡ����ֻ��
	pDC->SelectObject(&newpen);
	//���Ʋ�Ʒ����
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
// CZP_EXAM1_3View ��Ϣ�������
