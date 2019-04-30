#if !defined(AFX_AADDDLG_H__C95B2A6F_FAF5_4D25_AF31_B4F04D5F07FB__INCLUDED_)
#define AFX_AADDDLG_H__C95B2A6F_FAF5_4D25_AF31_B4F04D5F07FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AAddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAAddDlg dialog

class CAAddDlg : public CDialog
{
// Construction
public:
	CAAddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAAddDlg)
	enum { IDD = IDD_AADDDlg };
	CString	m_A_Birth;
	CString	m_A_Intro;
	CString	m_A_Name;
	CString	m_A_No;
	CString	m_A_Sex;
	CString	m_A_Unit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAAddDlg)
	afx_msg void OnSave();
	afx_msg void OnSaveandgo();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AADDDLG_H__C95B2A6F_FAF5_4D25_AF31_B4F04D5F07FB__INCLUDED_)
