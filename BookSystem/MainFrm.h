// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__A3EE55D9_8217_47E5_8D93_1AE4477B3C71__INCLUDED_)
#define AFX_MAINFRM_H__A3EE55D9_8217_47E5_8D93_1AE4477B3C71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPAdd();
	afx_msg void OnPBrowse();
	afx_msg void OnPDisp();
	afx_msg void OnPFIND();
	afx_msg void OnAAdd();
	afx_msg void OnADisp();
	afx_msg void OnABrowse();
	afx_msg void OnBAdd();
	afx_msg void OnBBrowse();
	afx_msg void OnBDisp();
	afx_msg void OnBFind();
	afx_msg void OnPOpenfile();
	afx_msg void OnAFind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__A3EE55D9_8217_47E5_8D93_1AE4477B3C71__INCLUDED_)
