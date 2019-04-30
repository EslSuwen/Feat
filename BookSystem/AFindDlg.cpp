// AFindDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "AFindDlg.h"
#include "ADispDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAFindDlg dialog

extern authorSet Author;

CAFindDlg::CAFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAFindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAFindDlg)
	m_A_FindNo = _T("");
	m_A_FindName = _T("");
	//}}AFX_DATA_INIT
}


void CAFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAFindDlg)
	DDX_Text(pDX, IDC_A_FindName1, m_A_FindNo);
	DDX_Text(pDX, IDC_A_FindNo1, m_A_FindName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAFindDlg, CDialog)
	//{{AFX_MSG_MAP(CAFindDlg)
	ON_BN_CLICKED(IDC_FINDNO1, OnFindno1)
	ON_BN_CLICKED(IDC_FINDNAME1, OnFindname1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAFindDlg message handlers

void CAFindDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CAFindDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}


void CAFindDlg::OnFindno1() 
{
	UpdateData(true);  
	if(!Author.locationAuthorNo(m_A_FindNo))
		MessageBox("作者不存在！","警告",MB_OK);	
	else
	{
		CADispDlg dlg;
		dlg.DoModal();
		
	}
}

void CAFindDlg::OnFindname1() 
{
	UpdateData(true);  
	if(!Author.ifAuthor(m_A_FindName))
		MessageBox("作者不存在！","警告",MB_OK);	
	else
	{
		CADispDlg dlg;
		dlg.DoModal();
		
	}
}
