// BookSystemView.h : interface of the CBookSystemView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOOKSYSTEMVIEW_H__8F4AA6AF_51CC_4612_87C8_E24955717861__INCLUDED_)
#define AFX_BOOKSYSTEMVIEW_H__8F4AA6AF_51CC_4612_87C8_E24955717861__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBookSystemView : public CView
{
protected: // create from serialization only
	CBookSystemView();
	DECLARE_DYNCREATE(CBookSystemView)

// Attributes
public:
	CBookSystemDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookSystemView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBookSystemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBookSystemView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BookSystemView.cpp
inline CBookSystemDoc* CBookSystemView::GetDocument()
   { return (CBookSystemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKSYSTEMVIEW_H__8F4AA6AF_51CC_4612_87C8_E24955717861__INCLUDED_)
