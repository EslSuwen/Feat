// PDispDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "PDispDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPDispDlg dialog

extern pressSet Press;

CPDispDlg::CPDispDlg(CWnd* pParent /*=NULL*/)
: CDialog(CPDispDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPDispDlg)
	m_P_No = _T("");
	m_P_Name = _T("");
	m_P_Leader = _T("");
	m_P_Intro = _T("");
	m_P_Division = _T("");
	//}}AFX_DATA_INIT
}


void CPDispDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPDispDlg)
	DDX_Text(pDX, IDC_P_No, m_P_No);
	DDX_Text(pDX, IDC_P_Name, m_P_Name);
	DDX_Text(pDX, IDC_P_Leader, m_P_Leader);
	DDX_Text(pDX, IDC_P_Intro, m_P_Intro);
	DDX_Text(pDX, IDC_P_Division, m_P_Division);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPDispDlg, CDialog)
//{{AFX_MSG_MAP(CPDispDlg)
ON_BN_CLICKED(IDC_DISPFIRST, OnDispfirst)
ON_BN_CLICKED(IDC_TOTHENEXT, OnTothenext)
ON_BN_CLICKED(IDC_TOTHEBEFORE, OnTothebefore)
ON_BN_CLICKED(IDC_DISPLAST, OnDisplast)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPDispDlg message handlers

void CPDispDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CPDispDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CPDispDlg::OnDispfirst() 
{
	// TODO: Add your control notification handler code here
	if (Press.moveToFirst())
	{
		m_P_No = Press.getCurrentPressNo();
		m_P_Name = Press.getCurrentPressName();
		m_P_Leader = Press.getCurrentPressLeader();
		m_P_Division =Press.getCurrentPressDivision();
		m_P_Intro = Press.getCurrentPressIntro();
		UpdateData(false);
	}
	else
		MessageBox("出版社不存在！","警告",MB_OK);
}

void CPDispDlg::OnTothenext() 
{
	// TODO: Add your control notification handler code here
	if (Press.moveToNext())
	{
		m_P_No = Press.getCurrentPressNo();
		m_P_Name = Press.getCurrentPressName();
		m_P_Leader = Press.getCurrentPressLeader();
		m_P_Division =Press.getCurrentPressDivision();
		m_P_Intro = Press.getCurrentPressIntro();
		UpdateData(false);
	}
	else
		MessageBox("出版社不存在！","警告",MB_OK);
}

void CPDispDlg::OnTothebefore() 
{
	// TODO: Add your control notification handler code here
	if (Press.moveToBefore())
	{
		m_P_No = Press.getCurrentPressNo();
		m_P_Name = Press.getCurrentPressName();
		m_P_Leader = Press.getCurrentPressLeader();
		m_P_Division =Press.getCurrentPressDivision();
		m_P_Intro = Press.getCurrentPressIntro();
		UpdateData(false);
	}
	else
		MessageBox("出版社不存在！","警告",MB_OK);
}

void CPDispDlg::OnDisplast() 
{
	// TODO: Add your control notification handler code here
	if (Press.moveToEnd())
	{
		m_P_No = Press.getCurrentPressNo();
		m_P_Name = Press.getCurrentPressName();
		m_P_Leader = Press.getCurrentPressLeader();
		m_P_Division =Press.getCurrentPressDivision();
		m_P_Intro = Press.getCurrentPressIntro();
		UpdateData(false);
	}
	else
		MessageBox("出版社不存在！","警告",MB_OK);
}

BOOL CPDispDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	if(Press.getNum()==0)
		return TRUE;
	else
	{
		m_P_No = Press.getCurrentPressNo();
		m_P_Name = Press.getCurrentPressName();
		m_P_Leader = Press.getCurrentPressLeader();
		m_P_Division =Press.getCurrentPressDivision();
		m_P_Intro = Press.getCurrentPressIntro();
		UpdateData(false);
		return TRUE;
	}
}
