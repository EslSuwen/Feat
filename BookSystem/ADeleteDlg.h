#if !defined(AFX_ADELETEDLG_H__B8DA0E3C_B8C1_4353_975F_DFA5095824EC__INCLUDED_)
#define AFX_ADELETEDLG_H__B8DA0E3C_B8C1_4353_975F_DFA5095824EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADeleteDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CADeleteDlg dialog

class CADeleteDlg : public CDialog
{
// Construction
public:
	CADeleteDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CADeleteDlg)
	enum { IDD = IDD_ADELETEDlg };
	CString	m_A_DeleteNo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADeleteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CADeleteDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADELETEDLG_H__B8DA0E3C_B8C1_4353_975F_DFA5095824EC__INCLUDED_)
