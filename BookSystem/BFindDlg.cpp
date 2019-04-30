// BFindDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "BFindDlg.h"
#include "BDispDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBFindDlg dialog

extern bookSet Book;

CBFindDlg::CBFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBFindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBFindDlg)
	m_B_FindName = _T("");
	m_B_FindNo = _T("");
	//}}AFX_DATA_INIT
}


void CBFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBFindDlg)
	DDX_Text(pDX, IDC_B_FindName, m_B_FindName);
	DDX_Text(pDX, IDC_B_FindNo, m_B_FindNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBFindDlg, CDialog)
	//{{AFX_MSG_MAP(CBFindDlg)
	ON_BN_CLICKED(IDC_FINDNO, OnFindno)
	ON_BN_CLICKED(IDC_FINDNAME, OnFindname)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBFindDlg message handlers

void CBFindDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CBFindDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CBFindDlg::OnFindno() 
{
	UpdateData(true);  
	if(!Book.locationBookNo(m_B_FindNo))
		MessageBox("图书不存在！","警告",MB_OK);	
	else
	{
		CBDispDlg dlg;
		dlg.DoModal();
		
	}
}

void CBFindDlg::OnFindname() 
{
	UpdateData(true);  
	if(!Book.ifBook(m_B_FindName))
		MessageBox("图书不存在！","警告",MB_OK);	
	else
	{
		CBDispDlg dlg;
		dlg.DoModal();
		
	}	
}
