// BookSystemDoc.h : interface of the CBookSystemDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOOKSYSTEMDOC_H__BBC466A8_64E6_46C0_8D23_A5F1FBF824B7__INCLUDED_)
#define AFX_BOOKSYSTEMDOC_H__BBC466A8_64E6_46C0_8D23_A5F1FBF824B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBookSystemDoc : public CDocument
{
protected: // create from serialization only
	CBookSystemDoc();
	DECLARE_DYNCREATE(CBookSystemDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookSystemDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBookSystemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBookSystemDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKSYSTEMDOC_H__BBC466A8_64E6_46C0_8D23_A5F1FBF824B7__INCLUDED_)
