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
	dwStyle  |=  LVS_EX_FULLROWSELECT;//ѡ��ĳ��ʹ���и�����ֻ������report����listctrl�� 
	dwStyle  |=  LVS_EX_GRIDLINES;//�����ߣ�ֻ������report����listctrl�� 
	//dwStyle  |=  LVS_EX_CHECKBOXES;//itemǰ����checkbox�ؼ� 
	m_List.SetExtendedStyle(dwStyle);   //������չ���
	
	m_List.InsertColumn( 0, "���", LVCFMT_CENTER, 80);
	m_List.InsertColumn( 1, "���", LVCFMT_CENTER, 80 );
	m_List.InsertColumn( 2, "����", LVCFMT_CENTER, 120);
	
	m_List.InsertColumn( 3, "�Ա�", LVCFMT_CENTER, 80);
	m_List.InsertColumn( 4, "��������", LVCFMT_CENTER, 125);
	m_List.InsertColumn( 5, "��λ", LVCFMT_CENTER, 150);
	m_List.InsertColumn( 6, "���", LVCFMT_CENTER, 200);
	
	
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
		//�����޸ĶԻ���,�޸ĶԻ���������򷵻��б�򣬲����б������ʾ�����ݽ����޸�
		CAModifyDlg dlg;
		dlg.DoModal();
		//�����ǽ��޸ĺ�������������뵽m_List��ȥ����������ʾ
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
		MessageBox("û�и����߱��","����",MB_OK);
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
