// ABrowseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "ABrowseDlg.h"
#include "AModifyDlg.h"
#include "ADeleteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CABrowseDlg dialog

extern authorSet Author;

CABrowseDlg::CABrowseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CABrowseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CABrowseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CABrowseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CABrowseDlg)
	DDX_Control(pDX, IDC_LIST, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CABrowseDlg, CDialog)
	//{{AFX_MSG_MAP(CABrowseDlg)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_NOTIFY(NM_RCLICK, IDC_LIST, OnRclickList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CABrowseDlg message handlers

BOOL CABrowseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	DWORD   dwStyle   =   m_List.GetExtendedStyle(); 
	dwStyle  |=  LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle  |=  LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	//dwStyle  |=  LVS_EX_CHECKBOXES;//item前生成checkbox控件 
	m_List.SetExtendedStyle(dwStyle);   //设置扩展风格
	
	m_List.InsertColumn( 0, "序号", LVCFMT_CENTER, 80);
	m_List.InsertColumn( 1, "编号", LVCFMT_CENTER, 80 );
	m_List.InsertColumn( 2, "姓名", LVCFMT_CENTER, 120);
	
	m_List.InsertColumn( 3, "性别", LVCFMT_CENTER, 80);
	m_List.InsertColumn( 4, "出生日期", LVCFMT_CENTER, 125);
	m_List.InsertColumn( 5, "单位", LVCFMT_CENTER, 150);
	m_List.InsertColumn( 6, "简介", LVCFMT_CENTER, 200);
	
	
	CString fillItem[7];
	
	Author.moveToFirst();
	for (int i=0;i<Author.getNum();i++)
	{
		//fillItem[0]=="";
		fillItem[0].Format("%d",i+1);
		fillItem[1]=Author.getCurrentAuthorNo();
		fillItem[2]=Author.getCurrentAuthorName();
		fillItem[3]=Author.getCurrentAuthorSex();
		fillItem[4]=Author.getCurrentAuthorBirth();
		fillItem[5]=Author.getCurrentAuthorUnit();
		fillItem[6]=Author.getCurrentAuthorIntro();
		m_List.InsertItem(i,fillItem[0]);
		
		for (int j=1;j<=6;j++)
			m_List.SetItemText(i,j,fillItem[j]);
		Author.moveToNext();
	}
	// TODO: Add extra initialization here
	
	return TRUE;
}

void CABrowseDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
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
	if (Author.locationAuthorNo(m_List.GetItemText(m_iSeled,1)))
	{
		//启动修改对话框,修改对话框结束，则返回列表框，并对列表框中显示的数据进行修改
		CAModifyDlg dlg;
		dlg.DoModal();
		//以下是将修改后的数据重新纳入到m_List中去，再重新显示
		m_List.SetItemText(m_iSeled,1,Author.getCurrentAuthorNo());
		m_List.SetItemText(m_iSeled,2,Author.getCurrentAuthorName());
		m_List.SetItemText(m_iSeled,3,Author.getCurrentAuthorSex());
		m_List.SetItemText(m_iSeled,4,Author.getCurrentAuthorBirth());
		m_List.SetItemText(m_iSeled,5,Author.getCurrentAuthorUnit());
		m_List.SetItemText(m_iSeled,6,Author.getCurrentAuthorIntro());
		m_List.SetRedraw();
	}
	else
	{
		MessageBox("没有该作者编号","警告",MB_OK);
		m_List.SetRedraw();	
	}
	
	*pResult = 0;
}

void CABrowseDlg::OnRclickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CADeleteDlg dlg;
	NMLISTVIEW* pp= (NMLISTVIEW*)pNMHDR;
	int m_iSeled=pp->iItem;
	Author.locationAuthorNo(m_List.GetItemText(m_iSeled,1));
	dlg.m_A_DeleteNo=Author.getCurrentAuthorName();
	dlg.DoModal();
	m_List.DeleteAllItems();
	CString fillItem[7];
	
	Author.moveToFirst();
	for (int i=0;i<Author.getNum();i++)
	{
		//fillItem[0]=="";
		fillItem[0].Format("%d",i+1);
		fillItem[1]=Author.getCurrentAuthorNo();
		fillItem[2]=Author.getCurrentAuthorName();
		fillItem[3]=Author.getCurrentAuthorSex();
		fillItem[4]=Author.getCurrentAuthorBirth();
		fillItem[5]=Author.getCurrentAuthorUnit();
		fillItem[6]=Author.getCurrentAuthorIntro();
		m_List.InsertItem(i,fillItem[0]);
		
		for (int j=1;j<=6;j++)
			m_List.SetItemText(i,j,fillItem[j]);
		Author.moveToNext();
	}
	*pResult = 0;
}
