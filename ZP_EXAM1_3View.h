
// ZP_EXAM1_3View.h : CZP_EXAM1_3View 类的接口
//

#pragma once
#include "Control.h"

class CZP_EXAM1_3View : public CView
{
protected: // 仅从序列化创建
	CZP_EXAM1_3View();
	DECLARE_DYNCREATE(CZP_EXAM1_3View)
	COLORREF xxx;	
	// 特性
public:
	CZP_EXAM1_3Doc* GetDocument() const;

// 操作
public:
//	CChart *m_chart;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CZP_EXAM1_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

/*
public:
//	void DrawRight(CDC* pDC);
//	void DrawChart(CDC* pDC);
//	void DrawProducts(CDC *pDC);*/
public:
	CControl* m_control;
/*	//Y宽度
	int spaceY;
	//X宽度
	int spaceX;
	//左下的定位角点
	POINT left_bottom;
	//超出部分
	int over;
	//实例化一个产品对象
	CProduct *m_product1;*/
};

#ifndef _DEBUG  // ZP_EXAM1_3View.cpp 中的调试版本
inline CZP_EXAM1_3Doc* CZP_EXAM1_3View::GetDocument() const
   { return reinterpret_cast<CZP_EXAM1_3Doc*>(m_pDocument); }
#endif

