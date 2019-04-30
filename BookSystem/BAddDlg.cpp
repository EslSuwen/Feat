// BAddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "BAddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBAddDlg dialog

extern bookSet Book;

CBAddDlg::CBAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBAddDlg)
	m_B_ANo = _T("");
	m_B_Birth = _T("");
	m_B_Intro = _T("");
	m_B_Name = _T("");
	m_B_No = _T("");
	m_B_PNo = _T("");
	m_B_Price = _T("");
	//}}AFX_DATA_INIT
}


void CBAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBAddDlg)
	DDX_Text(pDX, IDC_B_ANo, m_B_ANo);
	DDX_Text(pDX, IDC_B_Birth, m_B_Birth);
	DDX_Text(pDX, IDC_B_Intro, m_B_Intro);
	DDX_Text(pDX, IDC_B_Name, m_B_Name);
	DDX_Text(pDX, IDC_B_No, m_B_No);
	DDX_Text(pDX, IDC_B_PNo, m_B_PNo);
	DDX_Text(pDX, IDC_B_Price, m_B_Price);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBAddDlg, CDialog)
	//{{AFX_MSG_MAP(CBAddDlg)
	ON_BN_CLICKED(IDSAVE, OnSave)
	ON_BN_CLICKED(IDC_SAVEANDGO, OnSaveandgo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBAddDlg message handlers

void CBAddDlg::OnSave() 
{
	UpdateData(true);
	if(Book.locationBookNo(m_B_No))
	{
		MessageBox("该图书编号已存在!","警告",MB_OK);
		return;
	}
	book a;
	a.setBook(m_B_No,m_B_Name,m_B_PNo,m_B_ANo,m_B_Birth,m_B_Intro,m_B_Price);
	Book.setBookSet(Book.getNum(),a);
	Book.setNum(Book.getNum()+1);
	
	CDialog::OnOK();
}

void CBAddDlg::OnSaveandgo() 
{
	UpdateData(true);
	if(Book.locationBookNo(m_B_No))
	{
		MessageBox("该图书编号已存在!","警告",MB_OK);
		return;
	}
	book a;
	a.setBook(m_B_No,m_B_Name,m_B_PNo,m_B_ANo,m_B_Birth,m_B_Intro,m_B_Price);
	Book.setBookSet(Book.getNum(),a);
	Book.setNum(Book.getNum()+1);
	m_B_ANo = _T("");
	m_B_Birth = _T("");
	m_B_Intro = _T("");
	m_B_Name = _T("");
	m_B_No = _T("");
	m_B_PNo = _T("");
	m_B_Price = _T("");
	UpdateData(false);
}

void CBAddDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
