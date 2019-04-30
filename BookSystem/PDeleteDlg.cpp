// PDeleteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "PDeleteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPDeleteDlg dialog

extern pressSet Press;
extern bookSet Book;

CPDeleteDlg::CPDeleteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPDeleteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPDeleteDlg)
	m_P_DeleteNo = _T("");
	//}}AFX_DATA_INIT
}


void CPDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPDeleteDlg)
	DDX_Text(pDX, IDC_P_DeleteNo, m_P_DeleteNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPDeleteDlg, CDialog)
	//{{AFX_MSG_MAP(CPDeleteDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPDeleteDlg message handlers

void CPDeleteDlg::OnOK() 
{
	if(Book.ifDeletePress(m_P_DeleteNo))
	{
		MessageBox("�ó�����������ͼ�飬�޷�ɾ����","����",MB_OK);
	}
	else
	{
		Press.deletePress(m_P_DeleteNo);
		MessageBox("��ɾ�������ݣ�","��Ϣ",MB_OK);
		CDialog::OnOK();
	}
}

void CPDeleteDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
