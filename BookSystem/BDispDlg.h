#if !defined(AFX_BDISPDLG_H__512C6022_A707_4150_808A_52B30379E918__INCLUDED_)
#define AFX_BDISPDLG_H__512C6022_A707_4150_808A_52B30379E918__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BDispDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBDispDlg dialog

class CBDispDlg : public CDialog
{
// Construction
public:
	CBDispDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBDispDlg)
	enum { IDD = IDD_BDISPDlg };
	CString	m_B_ANo;
	CString	m_B_Birth;
	CString	m_B_Intro;
	CString	m_B_Name;
	CString	m_B_No;
	CString	m_B_PNo;
	CString	m_B_Price;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBDispDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBDispDlg)
	afx_msg void OnDispfirst();
	afx_msg void OnTothenext();
	afx_msg void OnTothebefore();
	afx_msg void OnDisplast();
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BDISPDLG_H__512C6022_A707_4150_808A_52B30379E918__INCLUDED_)
