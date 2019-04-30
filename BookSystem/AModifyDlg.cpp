// AModifyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "AModifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAModifyDlg dialog

extern authorSet Author;

CAModifyDlg::CAModifyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAModifyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAModifyDlg)
	m_A_Birth = _T("");
	m_A_Intro = _T("");
	m_A_Name = _T("");
	m_A_No = _T("");
	m_A_Sex = _T("");
	m_A_Unit = _T("");
	//}}AFX_DATA_INIT
}


void CAModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAModifyDlg)
	DDX_Text(pDX, IDC_A_Birth, m_A_Birth);
	DDX_Text(pDX, IDC_A_Intro, m_A_Intro);
	DDX_Text(pDX, IDC_A_Name, m_A_Name);
	DDX_Text(pDX, IDC_A_No, m_A_No);
	DDX_Text(pDX, IDC_A_Sex, m_A_Sex);
	DDX_Text(pDX, IDC_A_Unit, m_A_Unit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAModifyDlg, CDialog)
	//{{AFX_MSG_MAP(CAModifyDlg)
	ON_BN_CLICKED(IDSAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAModifyDlg message handlers

BOOL CAModifyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_A_Birth = Author.getCurrentAuthorBirth();
	m_A_Intro = Author.getCurrentAuthorIntro();
	m_A_Name = Author.getCurrentAuthorName();
	m_A_No = Author.getCurrentAuthorNo();
	m_A_Sex = Author.getCurrentAuthorSex ();
	m_A_Unit = Author.getCurrentAuthorUnit();
	UpdateData(false);
	return TRUE; 
}

void CAModifyDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CAModifyDlg::OnSave() 
{
	UpdateData(true);
	author a;
	a.setAuthor(m_A_No,m_A_Name,m_A_Sex,m_A_Birth,m_A_Intro,m_A_Unit);
	Author.setAuthorSet(a);
}
