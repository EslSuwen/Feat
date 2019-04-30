// ADispDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "ADispDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADispDlg dialog

extern authorSet Author;

CADispDlg::CADispDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADispDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADispDlg)
	m_A_Birth = _T("");
	m_A_Intro = _T("");
	m_A_Name = _T("");
	m_A_No = _T("");
	m_A_Sex = _T("");
	m_A_Unit = _T("");
	//}}AFX_DATA_INIT
}


void CADispDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADispDlg)
	DDX_Text(pDX, IDC_A_Birth, m_A_Birth);
	DDX_Text(pDX, IDC_A_Intro, m_A_Intro);
	DDX_Text(pDX, IDC_A_Name, m_A_Name);
	DDX_Text(pDX, IDC_A_No, m_A_No);
	DDX_Text(pDX, IDC_A_Sex, m_A_Sex);
	DDX_Text(pDX, IDC_A_Unit2, m_A_Unit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CADispDlg, CDialog)
	//{{AFX_MSG_MAP(CADispDlg)
	ON_BN_CLICKED(IDC_DISPFIRST, OnDispfirst)
	ON_BN_CLICKED(IDC_TOTHENEXT, OnTothenext)
	ON_BN_CLICKED(IDC_TOTHEBEFORE, OnTothebefore)
	ON_BN_CLICKED(IDC_DISPLAST, OnDisplast)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADispDlg message handlers

void CADispDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CADispDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CADispDlg::OnDispfirst() 
{
	if (Author.moveToFirst())
	{
		m_A_Birth = Author.getCurrentAuthorBirth();
		m_A_Intro = Author.getCurrentAuthorIntro();
		m_A_Name = Author.getCurrentAuthorName();
		m_A_No = Author.getCurrentAuthorNo();
		m_A_Sex = Author.getCurrentAuthorSex ();
		m_A_Unit = Author.getCurrentAuthorUnit();
		UpdateData(false);
	}
	else
		MessageBox("出版社不存在！","警告",MB_OK);
}

void CADispDlg::OnTothenext() 
{
	if (Author.moveToNext())
	{
		m_A_Birth = Author.getCurrentAuthorBirth();
		m_A_Intro = Author.getCurrentAuthorIntro();
		m_A_Name = Author.getCurrentAuthorName();
		m_A_No = Author.getCurrentAuthorNo();
		m_A_Sex = Author.getCurrentAuthorSex ();
		m_A_Unit = Author.getCurrentAuthorUnit();
		UpdateData(false);
	}
	else
		MessageBox("出版社不存在！","警告",MB_OK);
}

void CADispDlg::OnTothebefore() 
{
	if (Author.moveToBefore())
	{
		m_A_Birth = Author.getCurrentAuthorBirth();
		m_A_Intro = Author.getCurrentAuthorIntro();
		m_A_Name = Author.getCurrentAuthorName();
		m_A_No = Author.getCurrentAuthorNo();
		m_A_Sex = Author.getCurrentAuthorSex ();
		m_A_Unit = Author.getCurrentAuthorUnit();
		UpdateData(false);
	}
	else
		MessageBox("出版社不存在！","警告",MB_OK);
}
void CADispDlg::OnDisplast() 
{
	if (Author.moveToEnd())
	{
		m_A_Birth = Author.getCurrentAuthorBirth();
		m_A_Intro = Author.getCurrentAuthorIntro();
		m_A_Name = Author.getCurrentAuthorName();
		m_A_No = Author.getCurrentAuthorNo();
		m_A_Sex = Author.getCurrentAuthorSex ();
		m_A_Unit = Author.getCurrentAuthorUnit();
		UpdateData(false);
	}
	else
		MessageBox("出版社不存在！","警告",MB_OK);
}

BOOL CADispDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if(Author.getNum()==0)
		return TRUE;
	else
	{
		m_A_Birth = Author.getCurrentAuthorBirth();
		m_A_Intro = Author.getCurrentAuthorIntro();
		m_A_Name = Author.getCurrentAuthorName();
		m_A_No = Author.getCurrentAuthorNo();
		m_A_Sex = Author.getCurrentAuthorSex ();
		m_A_Unit = Author.getCurrentAuthorUnit();
		UpdateData(false);
		return TRUE;
	}
}
