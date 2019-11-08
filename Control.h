#pragma once
#include "Product.h"
#include "Chart.h"
class CControl
{
public:
	CControl(void);
	~CControl(void);
	//初始化数据
	void InitData();
	//绘制图表
	void DrawChart(CDC* pDC);
	//绘制右侧产品信息
	void DrawRight(CDC* pDC);
	//绘制产品曲线
	void DrawProducts(CDC *pDC);
public:
	//图表
	CChart *m_chart;
	//Y宽度
	int spaceY;
	//X宽度
	int spaceX;
	//左下的定位角点
	POINT left_bottom;
	//超出部分
	int over;
	//实例化三个产品对象
	CProduct *m_product[3];
	//产品数量
	int m_productNum;
};

