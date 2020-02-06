// LinearDiophantineEqDlg.h : header file
//

#if !defined(AFX_LINEARDIOPHANTINEEQDLG_H__A75BFFF3_362F_42CE_9AC7_E02DA04FE273__INCLUDED_)
#define AFX_LINEARDIOPHANTINEEQDLG_H__A75BFFF3_362F_42CE_9AC7_E02DA04FE273__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLinearDiophantineEqDlg dialog

class CLinearDiophantineEqDlg : public CDialog
{
// Construction
public:
	CLinearDiophantineEqDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLinearDiophantineEqDlg)
	enum { IDD = IDD_LINEARDIOPHANTINEEQ_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinearDiophantineEqDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLinearDiophantineEqDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEARDIOPHANTINEEQDLG_H__A75BFFF3_362F_42CE_9AC7_E02DA04FE273__INCLUDED_)
