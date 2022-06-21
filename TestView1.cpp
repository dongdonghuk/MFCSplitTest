// TestView1.cpp: 구현 파일
//

#include "pch.h"
#include "MFCSplitTest.h"
#include "MFCSplitTestDoc.h"
#include "TestView1.h"


// TestView1

IMPLEMENT_DYNCREATE(TestView1, CView)

TestView1::TestView1()
{

}

TestView1::~TestView1()
{
}

BEGIN_MESSAGE_MAP(TestView1, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// TestView1 그리기

void TestView1::OnDraw(CDC* pDC)
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
	pDC->TextOut(100, 100, _T("View1"));
}


// TestView1 진단

#ifdef _DEBUG
void TestView1::AssertValid() const
{
	CView::AssertValid();
}

CMFCSplitTestDoc* TestView1::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSplitTestDoc)));
	return (CMFCSplitTestDoc*)m_pDocument;
}

#ifndef _WIN32_WCE
void TestView1::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif

#endif //_DEBUG


// TestView1 메시지 처리기


void TestView1::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CMFCSplitTestDoc* pDoc = GetDocument();

	switch (lHint) {
	case HINT_SELECTED_VIEW:
		pDoc->m_pSelectedView = (CView*)pHint;
		break;
	}
	Invalidate();
}


void TestView1::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMFCSplitTestDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL, HINT_SELECTED_VIEW, this);

	CView::OnLButtonDown(nFlags, point);
}
