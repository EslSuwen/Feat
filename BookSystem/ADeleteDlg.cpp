// ADeleteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "ADeleteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADeleteDlg dialog

extern authorSet Author;
extern bookSet Book;

CADeleteDlg::CADeleteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADeleteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADeleteDlg)
	m_A_DeleteNo = _T("");
	//}}AFX_DATA_INIT
}


void CADeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADeleteDlg)
	DDX_Text(pDX, IDC_A_DeleteNo, m_A_DeleteNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CADeleteDlg, CDialog)
	//{{AFX_MSG_MAP(CADeleteDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADeleteDlg message handlers

void CADeleteDlg::OnOK() 
{
	if(Book.ifDeleteAuthor(m_A_DeleteNo))
	{
		MessageBox("该作者下仍有图书，无法删除！","警告",MB_OK);
	}
	else
	{
		Author.deleteAuthor(m_A_DeleteNo);
		MessageBox("已删除该数据！","消息",MB_OK);
		CDialog::OnOK();
	}
	
}

void CADeleteDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
