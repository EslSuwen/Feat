#if !defined(AFX_BADDDLG_H__ED3B16F9_6F86_4845_9DC8_5836328B02FC__INCLUDED_)
#define AFX_BADDDLG_H__ED3B16F9_6F86_4845_9DC8_5836328B02FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BAddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBAddDlg dialog

class CBAddDlg : public CDialog
{
// Construction
public:
	CBAddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBAddDlg)
	enum { IDD = IDD_BADDDlg };
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
	//{{AFX_VIRTUAL(CBAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBAddDlg)
	afx_msg void OnSave();
	afx_msg void OnSaveandgo();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BADDDLG_H__ED3B16F9_6F86_4845_9DC8_5836328B02FC__INCLUDED_)
