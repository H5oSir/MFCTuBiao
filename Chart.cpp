#include "stdafx.h"
#include "Chart.h"


CChart::CChart(void)
{
	m_line= new CLine;
}


CChart::~CChart(void)
{
	delete m_line;
}
