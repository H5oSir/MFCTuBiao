
// ZP_EXAM1_3View.h : CZP_EXAM1_3View ��Ľӿ�
//

#pragma once
#include "Control.h"

class CZP_EXAM1_3View : public CView
{
protected: // �������л�����
	CZP_EXAM1_3View();
	DECLARE_DYNCREATE(CZP_EXAM1_3View)
	COLORREF xxx;	
	// ����
public:
	CZP_EXAM1_3Doc* GetDocument() const;

// ����
public:
//	CChart *m_chart;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CZP_EXAM1_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

/*
public:
//	void DrawRight(CDC* pDC);
//	void DrawChart(CDC* pDC);
//	void DrawProducts(CDC *pDC);*/
public:
	CControl* m_control;
/*	//Y���
	int spaceY;
	//X���
	int spaceX;
	//���µĶ�λ�ǵ�
	POINT left_bottom;
	//��������
	int over;
	//ʵ����һ����Ʒ����
	CProduct *m_product1;*/
};

#ifndef _DEBUG  // ZP_EXAM1_3View.cpp �еĵ��԰汾
inline CZP_EXAM1_3Doc* CZP_EXAM1_3View::GetDocument() const
   { return reinterpret_cast<CZP_EXAM1_3Doc*>(m_pDocument); }
#endif

