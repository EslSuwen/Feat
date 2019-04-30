// AAddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "AAddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAAddDlg dialog

extern authorSet Author;

CAAddDlg::CAAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAAddDlg)
	m_A_Birth = _T("");
	m_A_Intro = _T("");
	m_A_Name = _T("");
	m_A_No = _T("");
	m_A_Sex = _T("");
	m_A_Unit = _T("");
	//}}AFX_DATA_INIT
}


void CAAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAAddDlg)
	DDX_Text(pDX, IDC_A_Birth, m_A_Birth);
	DDX_Text(pDX, IDC_A_Intro, m_A_Intro);
	DDX_Text(pDX, IDC_A_Name, m_A_Name);
	DDX_Text(pDX, IDC_A_No, m_A_No);
	DDX_Text(pDX, IDC_A_Sex, m_A_Sex);
	DDX_Text(pDX, IDC_A_Unit, m_A_Unit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAAddDlg, CDialog)
	//{{AFX_MSG_MAP(CAAddDlg)
	ON_BN_CLICKED(IDSAVE, OnSave)
	ON_BN_CLICKED(IDC_SAVEANDGO, OnSaveandgo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAAddDlg message handlers

void CAAddDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(Author.locationAuthorNo(m_A_No))
	{
		MessageBox("该作者编号已存在!","警告",MB_OK);
		return;
	}
	author a;
	a.setAuthor(m_A_No,m_A_Name,m_A_Sex,m_A_Birth,m_A_Intro,m_A_Unit);
	Author.setAuthorSet(Author.getNum(),a);
	Author.setNum(Author.getNum()+1);
	
	CDialog::OnOK();
}

void CAAddDlg::OnSaveandgo() 
{
	UpdateData(true);
	if(Author.locationAuthorNo(m_A_No))
	{
		MessageBox("该作者编号已存在!","警告",MB_OK);
		return;
	}
	author a;
	a.setAuthor(m_A_No,m_A_Name,m_A_Sex,m_A_Birth,m_A_Intro,m_A_Unit);
	Author.setAuthorSet(Author.getNum(),a);
	Author.setNum(Author.getNum()+1);
	m_A_Birth = _T("");
	m_A_Intro = _T("");
	m_A_Name = _T("");
	m_A_No = _T("");
	m_A_Sex = _T("");
	m_A_Unit = _T("");
	UpdateData(false);   
}

void CAAddDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
