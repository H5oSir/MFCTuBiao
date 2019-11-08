#pragma once
class CLine
{
public:
	CLine(void);
	~CLine(void);
	void DrawSlf(CDC *pDC,int startx,int starty,int stopx,int stopy,CPen *pen);
	//void DrawSlf(CDC *pDC,POINT start,POINT stop,CPen *pen);
};

