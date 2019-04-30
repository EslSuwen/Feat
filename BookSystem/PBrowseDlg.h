#if !defined(AFX_PBROWSEDLG_H__6BE11731_496C_4A6E_8E4E_9EA57E2642ED__INCLUDED_)
#define AFX_PBROWSEDLG_H__6BE11731_496C_4A6E_8E4E_9EA57E2642ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PBrowseDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPBrowseDlg dialog

class CPBrowseDlg : public CDialog
{
// Construction
public:
	CPBrowseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPBrowseDlg)
	enum { IDD = IDD_PBROWSEDlg };
	CListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPBrowseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPBrowseDlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PBROWSEDLG_H__6BE11731_496C_4A6E_8E4E_9EA57E2642ED__INCLUDED_)
