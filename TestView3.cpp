// TestView3.cpp: 구현 파일
//

#include "pch.h"
#include "MFCSplitTest.h"
#include "TestView3.h"


// TestView3

IMPLEMENT_DYNCREATE(TestView3, CView)

TestView3::TestView3()
{

}

TestView3::~TestView3()
{
}

BEGIN_MESSAGE_MAP(TestView3, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// TestView3 그리기

void TestView3::OnDraw(CDC* pDC)
{
	CMFCSplitTestDoc* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
	if (pDoc->m_pSelectedView == this) {
		CRect rect;
		GetClientRect(rect);
		CPen pen(PS_SOLID, 10, RGB(255, 0, 0));
		CPen* pOldPen = pDC->SelectObject(&pen);

		pDC->Rectangle(rect);

		pDC->SelectObject(pOldPen);
	}
	pDC->TextOut(100, 100, _T("View3"));

}


// TestView3 진단

#ifdef _DEBUG
void TestView3::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void TestView3::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
CMFCSplitTestDoc* TestView3::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSplitTestDoc)));
	return (CMFCSplitTestDoc*)m_pDocument;
}
#endif //_DEBUG


// TestView3 메시지 처리기
void TestView3::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CMFCSplitTestDoc* pDoc = GetDocument();

	switch (lHint) {
	case HINT_SELECTED_VIEW:
		pDoc->m_pSelectedView = (CView*)pHint;
		break;
	}
	Invalidate();

}

void TestView3::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMFCSplitTestDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL, HINT_SELECTED_VIEW, this);

	CView::OnLButtonDown(nFlags, point);
}
