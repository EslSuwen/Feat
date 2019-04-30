#if !defined(AFX_PMODIFYDLG_H__B34AF23F_FD8F_4BF6_91A2_243B947CC6EE__INCLUDED_)
#define AFX_PMODIFYDLG_H__B34AF23F_FD8F_4BF6_91A2_243B947CC6EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PModifyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPModifyDlg dialog

class CPModifyDlg : public CDialog
{
// Construction
public:
	CPModifyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPModifyDlg)
	enum { IDD = IDD_PMODIFYDlg };
	CString	m_P_Division;
	CString	m_P_Intro;
	CString	m_P_Leader;
	CString	m_P_Name;
	CString	m_P_No;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPModifyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPModifyDlg)
	afx_msg void OnSave();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PMODIFYDLG_H__B34AF23F_FD8F_4BF6_91A2_243B947CC6EE__INCLUDED_)
