#if !defined(AFX_BDELETEDLG_H__D8930B59_3A05_4B56_A68C_15BAEA74B07E__INCLUDED_)
#define AFX_BDELETEDLG_H__D8930B59_3A05_4B56_A68C_15BAEA74B07E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BDeleteDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBDeleteDlg dialog

class CBDeleteDlg : public CDialog
{
// Construction
public:
	CBDeleteDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBDeleteDlg)
	enum { IDD = IDD_BDELETEDlg };
	CString	m_B_DeleteNo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBDeleteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBDeleteDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BDELETEDLG_H__D8930B59_3A05_4B56_A68C_15BAEA74B07E__INCLUDED_)
