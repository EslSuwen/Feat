#if !defined(AFX_AFINDDLG_H__60EF8C51_F746_4499_9F24_5CD29E1579FB__INCLUDED_)
#define AFX_AFINDDLG_H__60EF8C51_F746_4499_9F24_5CD29E1579FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AFindDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAFindDlg dialog

class CAFindDlg : public CDialog
{
// Construction
public:
	CAFindDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAFindDlg)
	enum { IDD = IDD_AFINDDlg };
	CString	m_A_FindNo;
	CString	m_A_FindName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAFindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAFindDlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnFindno();
	afx_msg void OnFindname();
	afx_msg void OnFindno1();
	afx_msg void OnFindname1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AFINDDLG_H__60EF8C51_F746_4499_9F24_5CD29E1579FB__INCLUDED_)
