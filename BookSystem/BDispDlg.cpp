// BDispDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "BDispDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBDispDlg dialog

extern bookSet Book;

CBDispDlg::CBDispDlg(CWnd* pParent /*=NULL*/)
: CDialog(CBDispDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBDispDlg)
	m_B_ANo = _T("");
	m_B_Birth = _T("");
	m_B_Intro = _T("");
	m_B_Name = _T("");
	m_B_No = _T("");
	m_B_PNo = _T("");
	m_B_Price = _T("");
	//}}AFX_DATA_INIT
}


void CBDispDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBDispDlg)
	DDX_Text(pDX, IDC_B_ANo, m_B_ANo);
	DDX_Text(pDX, IDC_B_Birth, m_B_Birth);
	DDX_Text(pDX, IDC_B_Intro, m_B_Intro);
	DDX_Text(pDX, IDC_B_Name, m_B_Name);
	DDX_Text(pDX, IDC_B_No, m_B_No);
	DDX_Text(pDX, IDC_B_PNo, m_B_PNo);
	DDX_Text(pDX, IDC_B_Price2, m_B_Price);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBDispDlg, CDialog)
//{{AFX_MSG_MAP(CBDispDlg)
ON_BN_CLICKED(IDC_DISPFIRST, OnDispfirst)
ON_BN_CLICKED(IDC_TOTHENEXT, OnTothenext)
ON_BN_CLICKED(IDC_TOTHEBEFORE, OnTothebefore)
ON_BN_CLICKED(IDC_DISPLAST, OnDisplast)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBDispDlg message handlers

void CBDispDlg::OnDispfirst() 
{
	if (Book.moveToFirst())
	{
		m_B_ANo = Book.getCurrentBookANo();
		m_B_Birth = Book.getCurrentBookBirth();
		m_B_Intro = Book.getCurrentBookIntro();
		m_B_Name = Book.getCurrentBookName();
		m_B_No = Book.getCurrentBookNo();
		m_B_PNo = Book.getCurrentBookPNo();
		m_B_Price = Book.getCurrentBookPrice();
		UpdateData(false);
	}
	else
		MessageBox("图书不存在！","警告",MB_OK);
}

void CBDispDlg::OnTothenext() 
{
	if (Book.moveToNext())
	{
		m_B_ANo = Book.getCurrentBookANo();
		m_B_Birth = Book.getCurrentBookBirth();
		m_B_Intro = Book.getCurrentBookIntro();
		m_B_Name = Book.getCurrentBookName();
		m_B_No = Book.getCurrentBookNo();
		m_B_PNo = Book.getCurrentBookPNo();
		m_B_Price = Book.getCurrentBookPrice();
		UpdateData(false);
	}
	else
		MessageBox("图书不存在！","警告",MB_OK);
}

void CBDispDlg::OnTothebefore() 
{
	if (Book.moveToBefore())
	{
		m_B_ANo = Book.getCurrentBookANo();
		m_B_Birth = Book.getCurrentBookBirth();
		m_B_Intro = Book.getCurrentBookIntro();
		m_B_Name = Book.getCurrentBookName();
		m_B_No = Book.getCurrentBookNo();
		m_B_PNo = Book.getCurrentBookPNo();
		m_B_Price = Book.getCurrentBookPrice();
		UpdateData(false);
	}
	else
		MessageBox("图书不存在！","警告",MB_OK);
}

void CBDispDlg::OnDisplast() 
{
	if (Book.moveToEnd())
	{
		m_B_ANo = Book.getCurrentBookANo();
		m_B_Birth = Book.getCurrentBookBirth();
		m_B_Intro = Book.getCurrentBookIntro();
		m_B_Name = Book.getCurrentBookName();
		m_B_No = Book.getCurrentBookNo();
		m_B_PNo = Book.getCurrentBookPNo();
		m_B_Price = Book.getCurrentBookPrice();
		UpdateData(false);
	}
	else
		MessageBox("图书不存在！","警告",MB_OK);
}

void CBDispDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CBDispDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

BOOL CBDispDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if(Book.getNum()==0)
		return TRUE;
	else
	{
		m_B_ANo = Book.getCurrentBookANo();
		m_B_Birth = Book.getCurrentBookBirth();
		m_B_Intro = Book.getCurrentBookIntro();
		m_B_Name = Book.getCurrentBookName();
		m_B_No = Book.getCurrentBookNo();
		m_B_PNo = Book.getCurrentBookPNo();
		m_B_Price = Book.getCurrentBookPrice();
		UpdateData(false);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
