#if !defined(AFX_PFINDDLG_H__92FB0280_2C10_4333_89AB_0145D09F87AF__INCLUDED_)
#define AFX_PFINDDLG_H__92FB0280_2C10_4333_89AB_0145D09F87AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PFindDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPFindDlg dialog

class CPFindDlg : public CDialog
{
// Construction
public:
	CPFindDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPFindDlg)
	enum { IDD = IDD_PFINDDlg };
	CString	m_P_FindName;
	CString	m_P_FindNo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPFindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPFindDlg)
	afx_msg void OnFindno();
	afx_msg void OnFindname();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PFINDDLG_H__92FB0280_2C10_4333_89AB_0145D09F87AF__INCLUDED_)
