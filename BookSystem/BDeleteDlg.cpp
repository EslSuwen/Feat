// BDeleteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "BDeleteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBDeleteDlg dialog

extern bookSet Book;

CBDeleteDlg::CBDeleteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBDeleteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBDeleteDlg)
	m_B_DeleteNo = _T("");
	//}}AFX_DATA_INIT
}


void CBDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBDeleteDlg)
	DDX_Text(pDX, IDC_B_DeleteNo, m_B_DeleteNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBDeleteDlg, CDialog)
	//{{AFX_MSG_MAP(CBDeleteDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBDeleteDlg message handlers

void CBDeleteDlg::OnOK() 
{
	Book.deleteBook(m_B_DeleteNo);
	MessageBox("已删除该数据！","消息",MB_OK);
	CDialog::OnOK();
}

void CBDeleteDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
