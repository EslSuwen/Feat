// BModifyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "BModifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBModifyDlg dialog

extern bookSet Book;

CBModifyDlg::CBModifyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBModifyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBModifyDlg)
	m_B_ANo = _T("");
	m_B_Birth = _T("");
	m_B_Intro = _T("");
	m_B_Name = _T("");
	m_B_No = _T("");
	m_B_PNo = _T("");
	m_B_Price = _T("");
	//}}AFX_DATA_INIT
}


void CBModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBModifyDlg)
	DDX_Text(pDX, IDC_B_ANo, m_B_ANo);
	DDX_Text(pDX, IDC_B_Birth, m_B_Birth);
	DDX_Text(pDX, IDC_B_Intro, m_B_Intro);
	DDX_Text(pDX, IDC_B_Name, m_B_Name);
	DDX_Text(pDX, IDC_B_No, m_B_No);
	DDX_Text(pDX, IDC_B_PNo, m_B_PNo);
	DDX_Text(pDX, IDC_B_Price, m_B_Price);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBModifyDlg, CDialog)
	//{{AFX_MSG_MAP(CBModifyDlg)
	ON_BN_CLICKED(IDSAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBModifyDlg message handlers

void CBModifyDlg::OnSave() 
{
	CDialog::OnOK();
	UpdateData(true);
	book a;
	a.setBook(m_B_No,m_B_Name,m_B_PNo,m_B_ANo,m_B_Birth,m_B_Intro,m_B_Price);
	Book.setBookSet(a);
}

void CBModifyDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

BOOL CBModifyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_B_ANo = Book.getCurrentBookANo();
	m_B_Birth = Book.getCurrentBookBirth();
	m_B_Intro = Book.getCurrentBookIntro();
	m_B_Name = Book.getCurrentBookName();
	m_B_No = Book.getCurrentBookNo();
	m_B_PNo = Book.getCurrentBookPNo();
	m_B_Price = Book.getCurrentBookPrice();
	
	UpdateData(false);
	return TRUE; 
}
