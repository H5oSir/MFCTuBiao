#include "stdafx.h"
#include "Line.h"


CLine::CLine(void)
{
}


CLine::~CLine(void)
{
}

void CLine::DrawSlf(CDC *pDC,int startx,int starty,int stopx,int stopy,CPen *pen)
{
	pDC->SelectObject(pen);
	pDC->MoveTo(startx,starty);
	pDC->LineTo(stopx,stopy);
}
/*void CLine::DrawSlf(CDC *pDC,POINT start,POINT stop,CPen *pen)
{
	pDC->SelectObject(pen);
	pDC->MoveTo(start);
	pDC->LineTo(stop);
}*/