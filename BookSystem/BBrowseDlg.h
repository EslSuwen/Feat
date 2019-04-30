#if !defined(AFX_BBROWSEDLG_H__427534CA_247D_42BB_85F3_FEC06ECA07E9__INCLUDED_)
#define AFX_BBROWSEDLG_H__427534CA_247D_42BB_85F3_FEC06ECA07E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BBrowseDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBBrowseDlg dialog

class CBBrowseDlg : public CDialog
{
// Construction
public:
	CBBrowseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBBrowseDlg)
	enum { IDD = IDD_BBROWSEDlg };
	CListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBBrowseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBBrowseDlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickList(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBROWSEDLG_H__427534CA_247D_42BB_85F3_FEC06ECA07E9__INCLUDED_)
