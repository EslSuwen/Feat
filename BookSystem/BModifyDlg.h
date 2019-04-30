#if !defined(AFX_BMODIFYDLG_H__C73ECE0B_1B7A_4665_A092_29583967CB43__INCLUDED_)
#define AFX_BMODIFYDLG_H__C73ECE0B_1B7A_4665_A092_29583967CB43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BModifyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBModifyDlg dialog

class CBModifyDlg : public CDialog
{
// Construction
public:
	CBModifyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBModifyDlg)
	enum { IDD = IDD_BMODIFYDlg };
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
	//{{AFX_VIRTUAL(CBModifyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBModifyDlg)
	afx_msg void OnSave();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMODIFYDLG_H__C73ECE0B_1B7A_4665_A092_29583967CB43__INCLUDED_)
