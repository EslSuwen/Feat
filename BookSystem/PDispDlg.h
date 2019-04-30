#if !defined(AFX_PDISPDLG_H__DAD74C92_0732_4C0D_A317_A5C0BC4735AC__INCLUDED_)
#define AFX_PDISPDLG_H__DAD74C92_0732_4C0D_A317_A5C0BC4735AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PDispDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPDispDlg dialog

class CPDispDlg : public CDialog
{
// Construction
public:
	CPDispDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPDispDlg)
	enum { IDD = IDD_PDISPDlg };
	CString	m_P_No;
	CString	m_P_Name;
	CString	m_P_Leader;
	CString	m_P_Intro;
	CString	m_P_Division;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPDispDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPDispDlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnDispfirst();
	afx_msg void OnTothenext();
	afx_msg void OnTothebefore();
	afx_msg void OnDisplast();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PDISPDLG_H__DAD74C92_0732_4C0D_A317_A5C0BC4735AC__INCLUDED_)
