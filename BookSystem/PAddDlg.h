#if !defined(AFX_PADDDLG_H__9E03CF30_FF13_4567_B7A1_41D36392C0B8__INCLUDED_)
#define AFX_PADDDLG_H__9E03CF30_FF13_4567_B7A1_41D36392C0B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PAddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPAddDlg dialog

class CPAddDlg : public CDialog
{
// Construction
public:
	CPAddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPAddDlg)
	enum { IDD = IDD_PADDDlg };
	CString	m_P_Division;
	CString	m_P_Intro;
	CString	m_P_Leader;
	CString	m_P_Name;
	CString	m_P_No;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPAddDlg)
	afx_msg void OnSave();
	afx_msg void OnSaveandgo();
	virtual void OnCancel();
	afx_msg void OnAAdd();
	afx_msg void OnABrowse();
	afx_msg void OnADisp();
	afx_msg void OnAFind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PADDDLG_H__9E03CF30_FF13_4567_B7A1_41D36392C0B8__INCLUDED_)
