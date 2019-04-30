// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "BookSystem.h"

#include "PAddDlg.h"
#include "PDispDlg.h"
#include "PBrowseDlg.h"
#include "PFindDlg.h"

#include "AAddDlg.h"
#include "ADispDlg.h"
#include "ABrowseDlg.h"
#include "AFindDlg.h"

#include "BAddDlg.h"
#include "BDispDlg.h"
#include "BBrowseDlg.h"
#include "BFindDlg.h"


#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(P_ADD, OnPAdd)
	ON_COMMAND(P_BROWSE, OnPBrowse)
	ON_COMMAND(P_DISP, OnPDisp)
	ON_COMMAND(P_FIND, OnPFIND)
	ON_COMMAND(A_ADD, OnAAdd)
	ON_COMMAND(A_DISP, OnADisp)
	ON_COMMAND(A_BROWSE, OnABrowse)
	ON_COMMAND(B_ADD, OnBAdd)
	ON_COMMAND(B_BROWSE, OnBBrowse)
	ON_COMMAND(B_DISP, OnBDisp)
	ON_COMMAND(B_FIND, OnBFind)
	ON_COMMAND(A_FIND, OnAFind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

pressSet Press;
authorSet Author;
bookSet Book;

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnPAdd() 
{
	// TODO: Add your command handler code here
	CPAddDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;
}

void CMainFrame::OnPBrowse() 
{
	// TODO: Add your command handler code here
	CPBrowseDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;
}

void CMainFrame::OnPDisp() 
{
	// TODO: Add your command handler code here
	CPDispDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;
}

void CMainFrame::OnPFIND() 
{
	// TODO: Add your command handler code here
	CPFindDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;
}

void CMainFrame::OnAAdd() 
{
	// TODO: Add your command handler code here
	CAAddDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;
}

void CMainFrame::OnADisp() 
{
	CADispDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;	
}

void CMainFrame::OnABrowse() 
{
	CABrowseDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;	
}

void CMainFrame::OnBAdd() 
{
	CBAddDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;	
}

void CMainFrame::OnBBrowse() 
{
	CBBrowseDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;		
}

void CMainFrame::OnBDisp() 
{
	CBDispDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;		
}

void CMainFrame::OnBFind() 
{
	CBFindDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;		
}

void CMainFrame::OnAFind() 
{
	CAFindDlg dlg;
	if(dlg.DoModal()==IDOK)
		return;		
}
