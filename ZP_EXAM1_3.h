
// ZP_EXAM1_3.h : ZP_EXAM1_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CZP_EXAM1_3App:
// �йش����ʵ�֣������ ZP_EXAM1_3.cpp
//

class CZP_EXAM1_3App : public CWinAppEx
{
public:
	CZP_EXAM1_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CZP_EXAM1_3App theApp;
