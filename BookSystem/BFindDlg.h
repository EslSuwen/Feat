#if !defined(AFX_BFINDDLG_H__32841E65_64EB_47A1_BCE1_1C41EBAF276D__INCLUDED_)
#define AFX_BFINDDLG_H__32841E65_64EB_47A1_BCE1_1C41EBAF276D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BFindDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBFindDlg dialog

class CBFindDlg : public CDialog
{
// Construction
public:
	CBFindDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBFindDlg)
	enum { IDD = IDD_BFINDDlg };
	CString	m_B_FindName;
	CString	m_B_FindNo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBFindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBFindDlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnFindno();
	afx_msg void OnFindname();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BFINDDLG_H__32841E65_64EB_47A1_BCE1_1C41EBAF276D__INCLUDED_)
