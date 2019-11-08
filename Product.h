#pragma once
#include "Line.h"


class CProduct
{
public:
	CProduct(void);
	~CProduct(void);
	CProduct(CLine *line,COLORREF color,int *products);
	//CProduct(CLine *line,CPen *pen,int *products);
	void DrawSlf(CDC *pDC);
	int ProductToPoint(int products,int spaceY,int spaceProductY);
public:
	CLine *m_line;
	COLORREF m_color;
	CPen m_pen;
	int m_products[5];
	int m_icoType;
};

