#if !defined(AFX_ADISPDLG_H__62D936D2_D3C4_4BE3_B32B_ADC498AA3E79__INCLUDED_)
#define AFX_ADISPDLG_H__62D936D2_D3C4_4BE3_B32B_ADC498AA3E79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADispDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CADispDlg dialog

class CADispDlg : public CDialog
{
// Construction
public:
	CADispDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CADispDlg)
	enum { IDD = IDD_ADISPDlg };
	CString	m_A_Birth;
	CString	m_A_Intro;
	CString	m_A_Name;
	CString	m_A_No;
	CString	m_A_Sex;
	CString	m_A_Unit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADispDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CADispDlg)
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

#endif // !defined(AFX_ADISPDLG_H__62D936D2_D3C4_4BE3_B32B_ADC498AA3E79__INCLUDED_)
