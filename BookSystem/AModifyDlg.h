#if !defined(AFX_AMODIFYDLG_H__9D504C67_52B5_4CB0_8C09_E8CBA7AAD9C3__INCLUDED_)
#define AFX_AMODIFYDLG_H__9D504C67_52B5_4CB0_8C09_E8CBA7AAD9C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AModifyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAModifyDlg dialog

class CAModifyDlg : public CDialog
{
// Construction
public:
	CAModifyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAModifyDlg)
	enum { IDD = IDD_AMODIFYDlg };
	CString	m_A_Birth;
	CString	m_A_Intro;
	CString	m_A_Name;
	CString	m_A_No;
	CString	m_A_Sex;
	CString	m_A_Unit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAModifyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAModifyDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AMODIFYDLG_H__9D504C67_52B5_4CB0_8C09_E8CBA7AAD9C3__INCLUDED_)
