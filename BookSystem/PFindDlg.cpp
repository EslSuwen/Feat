// PFindDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "PFindDlg.h"
#include "PDispDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPFindDlg dialog

extern pressSet Press;

CPFindDlg::CPFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPFindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPFindDlg)
	m_P_FindName = _T("");
	m_P_FindNo = _T("");
	//}}AFX_DATA_INIT
}


void CPFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPFindDlg)
	DDX_Text(pDX, IDC_P_FindName, m_P_FindName);
	DDX_Text(pDX, IDC_P_FindNo, m_P_FindNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPFindDlg, CDialog)
	//{{AFX_MSG_MAP(CPFindDlg)
	ON_BN_CLICKED(IDC_FINDNO, OnFindno)
	ON_BN_CLICKED(IDC_FINDNAME, OnFindname)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPFindDlg message handlers

void CPFindDlg::OnFindno() 
{
	UpdateData(true);  
	if(!Press.locationPressNo(m_P_FindNo))
		MessageBox("出版社不存在！","警告",MB_OK);	
	else
	{
		CPDispDlg dlg;
		dlg.DoModal();	
	}
}

void CPFindDlg::OnFindname() 
{
	UpdateData(true);  
	if(!Press.ifPress(m_P_FindName))
		MessageBox("出版社不存在！","警告",MB_OK);	
	else
	{
		CPDispDlg dlg;
		dlg.DoModal();	
	}
}
