﻿#pragma once


// TestView3 보기
#include "MFCSplitTestDoc.h"

class TestView3 : public CView
{
	DECLARE_DYNCREATE(TestView3)

protected:
	TestView3();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~TestView3();

public:
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
	CMFCSplitTestDoc* GetDocument() const;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


#ifndef _DEBUG  // MFCSplitTestView.cpp의 디버그 버전
inline CMFCSplitTestDoc* TestView3::GetDocument() const
{
	return reinterpret_cast<CMFCSplitTestDoc*>(m_pDocument);
}
#endif