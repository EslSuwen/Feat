// BBrowseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "BBrowseDlg.h"
#include "BModifyDlg.h"
#include "BDeleteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBBrowseDlg dialog

extern bookSet Book;

CBBrowseDlg::CBBrowseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBBrowseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBBrowseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBBrowseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBBrowseDlg)
	DDX_Control(pDX, IDC_LIST, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBBrowseDlg, CDialog)
	//{{AFX_MSG_MAP(CBBrowseDlg)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_NOTIFY(NM_RCLICK, IDC_LIST, OnRclickList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBBrowseDlg message handlers

void CBBrowseDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CBBrowseDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CBBrowseDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NMLISTVIEW* pp= (NMLISTVIEW*)pNMHDR;
	int m_iSeled;
	m_iSeled=pp->iItem;
	UpdateData(true);
	if( m_iSeled<0 )
	{
		return;
	}	
	m_List.SetRedraw(false);
	if (Book.locationBookNo(m_List.GetItemText(m_iSeled,1)))
	{
		//启动修改对话框,修改对话框结束，则返回列表框，并对列表框中显示的数据进行修改
		CBModifyDlg dlg;
		dlg.DoModal();
		//以下是将修改后的数据重新纳入到m_List中去，再重新显示
		m_List.SetItemText(m_iSeled,1,Book.getCurrentBookNo());
		m_List.SetItemText(m_iSeled,2,Book.getCurrentBookName());
		m_List.SetItemText(m_iSeled,3,Book.getCurrentBookANo());
		m_List.SetItemText(m_iSeled,4,Book.getCurrentBookPNo());
		m_List.SetItemText(m_iSeled,5,Book.getCurrentBookBirth());
		m_List.SetItemText(m_iSeled,6,Book.getCurrentBookPrice());
		m_List.SetItemText(m_iSeled,7,Book.getCurrentBookIntro());
		m_List.SetRedraw();
	}
	else
	{
		MessageBox("没有该图书编号","警告",MB_OK);
		m_List.SetRedraw();	
	}
	
	*pResult = 0;
}

void CBBrowseDlg::OnRclickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CBDeleteDlg dlg;
	NMLISTVIEW* pp= (NMLISTVIEW*)pNMHDR;
	int m_iSeled=pp->iItem;
	Book.locationBookNo(m_List.GetItemText(m_iSeled,1));
	dlg.m_B_DeleteNo=Book.getCurrentBookNo();
	dlg.DoModal();
	m_List.DeleteAllItems();

	CString fillItem[8];
	Book.moveToFirst();
	for (int i=0;i<Book.getNum();i++)
	{
		//fillItem[0]=="";
		fillItem[0].Format("%d",i+1);
		fillItem[1]=Book.getCurrentBookNo();
		fillItem[2]=Book.getCurrentBookName();
		fillItem[3]=Book.getCurrentBookANo();
		fillItem[4]=Book.getCurrentBookPNo();
		fillItem[5]=Book.getCurrentBookPrice();
		fillItem[6]=Book.getCurrentBookIntro();
		m_List.InsertItem(i,fillItem[0]);
		
		for (int j=1;j<=7;j++)
			m_List.SetItemText(i,j,fillItem[j]);
		Book.moveToNext();
	}
	*pResult = 0;
}

BOOL CBBrowseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	DWORD   dwStyle   =   m_List.GetExtendedStyle(); 
	dwStyle  |=  LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle  |=  LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	//dwStyle  |=  LVS_EX_CHECKBOXES;//item前生成checkbox控件 
	m_List.SetExtendedStyle(dwStyle);   //设置扩展风格
	
	m_List.InsertColumn( 0, "序号", LVCFMT_CENTER, 80);
	m_List.InsertColumn( 1, "编号", LVCFMT_CENTER, 80 );
	m_List.InsertColumn( 2, "名称", LVCFMT_CENTER, 120);
	
	m_List.InsertColumn( 3, "作者", LVCFMT_CENTER, 80);
	m_List.InsertColumn( 4, "出版社", LVCFMT_CENTER, 125);
	m_List.InsertColumn( 5, "出版日期", LVCFMT_CENTER, 125);
	m_List.InsertColumn( 6, "价格", LVCFMT_CENTER, 150);
	m_List.InsertColumn( 7, "简介", LVCFMT_CENTER, 200);
	
	
	CString fillItem[8];
	
	Book.moveToFirst();
	for (int i=0;i<Book.getNum();i++)
	{
		//fillItem[0]=="";
		fillItem[0].Format("%d",i+1);
		fillItem[1]=Book.getCurrentBookNo();
		fillItem[2]=Book.getCurrentBookName();
		fillItem[3]=Book.getCurrentBookANo();
		fillItem[4]=Book.getCurrentBookPNo();
		fillItem[5]=Book.getCurrentBookBirth();
		fillItem[6]=Book.getCurrentBookPrice();
		fillItem[7]=Book.getCurrentBookIntro();
		m_List.InsertItem(i,fillItem[0]);
		
		for (int j=1;j<=7;j++)
			m_List.SetItemText(i,j,fillItem[j]);
		Book.moveToNext();
	}
	// TODO: Add extra initialization here
	
	return TRUE;
}
