// PBrowseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookSystem.h"
#include "PBrowseDlg.h"
#include "PModifyDlg.h"
#include "PDeleteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPBrowseDlg dialog

extern pressSet Press;

CPBrowseDlg::CPBrowseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPBrowseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPBrowseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPBrowseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPBrowseDlg)
	DDX_Control(pDX, IDC_LIST, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPBrowseDlg, CDialog)
	//{{AFX_MSG_MAP(CPBrowseDlg)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList1)
	ON_NOTIFY(NM_RCLICK, IDC_LIST, OnRclickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPBrowseDlg message handlers

void CPBrowseDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CPBrowseDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CPBrowseDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NMLISTVIEW* pp= (NMLISTVIEW*)pNMHDR;
	int m_iSeled;
	m_iSeled=pp->iItem;
	UpdateData(true);
	if( m_iSeled<0 )
	{
		return;
	}	
	m_List.SetRedraw(false);
	if (Press.locationPressNo(m_List.GetItemText(m_iSeled,1)))
	{
		//启动修改对话框,修改对话框结束，则返回列表框，并对列表框中显示的数据进行修改
		CPModifyDlg dlg;
		dlg.DoModal();
		//以下是将修改后的数据重新纳入到m_List中去，再重新显示
		m_List.SetItemText(m_iSeled,1,Press.getCurrentPressNo());
		m_List.SetItemText(m_iSeled,2,Press.getCurrentPressName());
		m_List.SetItemText(m_iSeled,3,Press.getCurrentPressLeader());
		m_List.SetItemText(m_iSeled,4,Press.getCurrentPressDivision());
		m_List.SetItemText(m_iSeled,5,Press.getCurrentPressIntro());
		m_List.SetRedraw();
	}
	else
	{
		MessageBox("没有该出版社编号","警告",MB_OK);
		m_List.SetRedraw();	
	}
	
	*pResult = 0;
}

void CPBrowseDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CPDeleteDlg dlg;
	NMLISTVIEW* pp= (NMLISTVIEW*)pNMHDR;
	int m_iSeled=pp->iItem;
	Press.locationPressNo(m_List.GetItemText(m_iSeled,1));
	dlg.m_P_DeleteNo=Press.getCurrentPressName();
	dlg.DoModal();
	m_List.DeleteAllItems();
	CString fillItem[6];
	
	Press.moveToFirst();
	for (int i=0;i<Press.getNum();i++)
	{
		//fillItem[0]=="";
		fillItem[0].Format("%d",i+1);
		fillItem[1]=Press.getCurrentPressNo();
		fillItem[2]=Press.getCurrentPressName();
		fillItem[3]=Press.getCurrentPressLeader();
		fillItem[4]=Press.getCurrentPressDivision();
		fillItem[5]=Press.getCurrentPressIntro();
		m_List.InsertItem(i,fillItem[0]);
		
		for (int j=1;j<=5;j++)
			m_List.SetItemText(i,j,fillItem[j]);
		Press.moveToNext();
	}
	*pResult = 0;
}

BOOL CPBrowseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	DWORD   dwStyle   =   m_List.GetExtendedStyle(); 
	dwStyle  |=  LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle  |=  LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	//dwStyle  |=  LVS_EX_CHECKBOXES;//item前生成checkbox控件 
	m_List.SetExtendedStyle(dwStyle);   //设置扩展风格
	
	m_List.InsertColumn( 0, "序号", LVCFMT_CENTER, 80);//插入"序号"列，30表示此列的宽度
	m_List.InsertColumn( 1, "编号", LVCFMT_CENTER, 80 );//插入"学院编号"列
	m_List.InsertColumn( 2, "名称", LVCFMT_CENTER, 220);
	
	m_List.InsertColumn( 3, "负责人", LVCFMT_CENTER, 130);
	m_List.InsertColumn( 4, "下设分社", LVCFMT_CENTER, 130);
	m_List.InsertColumn( 5, "简介", LVCFMT_CENTER, 200);
	
	
	CString fillItem[6];
	
	Press.moveToFirst();
	for (int i=0;i<Press.getNum();i++)
	{
		//fillItem[0]=="";
		fillItem[0].Format("%d",i+1);
		fillItem[1]=Press.getCurrentPressNo();
		fillItem[2]=Press.getCurrentPressName();
		fillItem[3]=Press.getCurrentPressLeader();
		fillItem[4]=Press.getCurrentPressDivision();
		fillItem[5]=Press.getCurrentPressIntro();
		m_List.InsertItem(i,fillItem[0]);
		
		for (int j=1;j<=5;j++)
			m_List.SetItemText(i,j,fillItem[j]);
		Press.moveToNext();
	}
	return TRUE;
}
