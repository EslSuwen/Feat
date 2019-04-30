#if !defined(AFX_PDELETEDLG_H__3DD7110D_E063_4121_85A6_DCAC7924C2FD__INCLUDED_)
#define AFX_PDELETEDLG_H__3DD7110D_E063_4121_85A6_DCAC7924C2FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PDeleteDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPDeleteDlg dialog

class CPDeleteDlg : public CDialog
{
// Construction
public:
	CPDeleteDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPDeleteDlg)
	enum { IDD = IDD_PDELETEDlg };
	CString	m_P_DeleteNo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPDeleteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPDeleteDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PDELETEDLG_H__3DD7110D_E063_4121_85A6_DCAC7924C2FD__INCLUDED_)
