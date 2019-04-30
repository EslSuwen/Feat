// PModifyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "PModifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPModifyDlg dialog

extern pressSet Press;

CPModifyDlg::CPModifyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPModifyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPModifyDlg)
	m_P_Division = _T("");
	m_P_Intro = _T("");
	m_P_Leader = _T("");
	m_P_Name = _T("");
	m_P_No = _T("");
	//}}AFX_DATA_INIT
}


void CPModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPModifyDlg)
	DDX_Text(pDX, IDC_P_Division, m_P_Division);
	DDX_Text(pDX, IDC_P_Intro, m_P_Intro);
	DDX_Text(pDX, IDC_P_Leader, m_P_Leader);
	DDX_Text(pDX, IDC_P_Name, m_P_Name);
	DDX_Text(pDX, IDC_P_No, m_P_No);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPModifyDlg, CDialog)
	//{{AFX_MSG_MAP(CPModifyDlg)
	ON_BN_CLICKED(IDSAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPModifyDlg message handlers

void CPModifyDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);                           
	press a;                             
	a.setPress(m_P_No,m_P_Name,m_P_Leader,m_P_Division,m_P_Intro); 
	Press.setPressSet(a);
	CDialog::OnOK();
}

BOOL CPModifyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_P_No = Press.getCurrentPressNo();
	m_P_Name = Press.getCurrentPressName();
	m_P_Leader = Press.getCurrentPressLeader();
	m_P_Division =Press.getCurrentPressDivision();
	m_P_Intro = Press.getCurrentPressIntro();
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE

}
