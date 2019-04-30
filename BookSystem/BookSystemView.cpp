// BookSystemView.cpp : implementation of the CBookSystemView class
//

#include "stdafx.h"
#include "BookSystem.h"

#include "BookSystemDoc.h"
#include "BookSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView

IMPLEMENT_DYNCREATE(CBookSystemView, CView)

BEGIN_MESSAGE_MAP(CBookSystemView, CView)
	//{{AFX_MSG_MAP(CBookSystemView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView construction/destruction

CBookSystemView::CBookSystemView()
{
	// TODO: add construction code here

}

CBookSystemView::~CBookSystemView()
{
}

BOOL CBookSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView drawing

void CBookSystemView::OnDraw(CDC* pDC)
{
	CBookSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView printing

BOOL CBookSystemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBookSystemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBookSystemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView diagnostics

#ifdef _DEBUG
void CBookSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CBookSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBookSystemDoc* CBookSystemView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBookSystemDoc)));
	return (CBookSystemDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBookSystemView message handlers
