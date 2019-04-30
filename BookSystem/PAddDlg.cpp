// PAddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "PAddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPAddDlg dialog

extern pressSet Press;

CPAddDlg::CPAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPAddDlg)
	m_P_Division = _T("");
	m_P_Intro = _T("");
	m_P_Leader = _T("");
	m_P_Name = _T("");
	m_P_No = _T("");
	//}}AFX_DATA_INIT
}


void CPAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPAddDlg)
	DDX_Text(pDX, IDC_P_Division, m_P_Division);
	DDX_Text(pDX, IDC_P_Intro, m_P_Intro);
	DDX_Text(pDX, IDC_P_Leader, m_P_Leader);
	DDX_Text(pDX, IDC_P_Name, m_P_Name);
	DDX_Text(pDX, IDC_P_No, m_P_No);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPAddDlg, CDialog)
	//{{AFX_MSG_MAP(CPAddDlg)
	ON_BN_CLICKED(IDSAVE, OnSave)
	ON_BN_CLICKED(IDC_SAVEANDGO, OnSaveandgo)
	ON_COMMAND(A_ADD, OnAAdd)
	ON_COMMAND(A_BROWSE, OnABrowse)
	ON_COMMAND(A_DISP, OnADisp)
	ON_COMMAND(A_FIND, OnAFind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPAddDlg message handlers

void CPAddDlg::OnSave() 
{
	UpdateData(true);                       //用于将屏幕上控件中的数据交换到变量中
	if(Press.locationPressNo(m_P_No))
	{
		MessageBox("该出版社编号已存在!","警告",MB_OK);
		return;
	}
	press a;	                                 //生成一个出版社对象
	a.setPress(m_P_No,m_P_Name,m_P_Leader,m_P_Division,m_P_Intro);   //用输入的数据给对象赋初值
	Press.setPressSet(Press.getNum(),a);         //将刚输入的学院对象加入到出版社集合中去，并放在对象数据的最后
	Press.setNum(Press.getNum()+1);           //记录学院个数的Num值加1
	
	CDialog::OnOK();
}

void CPAddDlg::OnSaveandgo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);                             //用于将屏幕上控件中的数据交换到变量中
	if(Press.locationPressNo(m_P_No))
	{
		MessageBox("该出版社编号已存在!","警告",MB_OK);
		return;
	}
	press a;                                    //生成一个出版社对象
	a.setPress(m_P_No,m_P_Name,m_P_Leader,m_P_Division,m_P_Intro);                //用输入的数据给出版社对象赋初值
	Press.setPressSet(Press.getNum(),a);         //将刚输入的出版社对象加入到出版社集合中去，并放在对象数据的最后
	Press.setNum(Press.getNum()+1);          //记录出版社个数的Num值加1
	//以下是将与输入文本框相联系的变量置空
	m_P_No = _T("");
	m_P_Name = _T("");
	m_P_Leader = _T("");
	m_P_Division = _T("");
	m_P_Intro = _T("");
	UpdateData(false);    
}

void CPAddDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CPAddDlg::OnAAdd() 
{
	// TODO: Add your command handler code here
	
}

void CPAddDlg::OnABrowse() 
{
	// TODO: Add your command handler code here
	
}

void CPAddDlg::OnADisp() 
{
	// TODO: Add your command handler code here
	
}

void CPAddDlg::OnAFind() 
{
	// TODO: Add your command handler code here
	
}
