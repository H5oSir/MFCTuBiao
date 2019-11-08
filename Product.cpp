#include "stdafx.h"
#include "Product.h"


CProduct::CProduct(void)
{
}


CProduct::~CProduct(void)
{
	delete m_line;
}

CProduct::CProduct(CLine *line,COLORREF color,int *products)
{
	m_color=color;
	m_pen.CreatePen(PS_SOLID,1,m_color);
	m_line= new CLine;
	for (int i = 0; i < 5; i++)
	{
		m_products[i]=products[i];
	}
}

void CProduct::DrawSlf(CDC *pDC)
{
	
}
/*
int ProductToPoint(int products,int spaceY,int spaceProductY)
{
	return products*spaceY/spaceProductY;
}*/