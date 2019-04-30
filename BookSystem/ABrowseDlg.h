#if !defined(AFX_ABROWSEDLG_H__20CC03CA_92BB_4472_B4A3_BF3F1331B0A0__INCLUDED_)
#define AFX_ABROWSEDLG_H__20CC03CA_92BB_4472_B4A3_BF3F1331B0A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ABrowseDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CABrowseDlg dialog

class CABrowseDlg : public CDialog
{
// Construction
public:
	CABrowseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CABrowseDlg)
	enum { IDD = IDD_ABROWSEDlg };
	CListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CABrowseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CABrowseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ABROWSEDLG_H__20CC03CA_92BB_4472_B4A3_BF3F1331B0A0__INCLUDED_)
