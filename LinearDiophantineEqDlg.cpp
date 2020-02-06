// LinearDiophantineEqDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LinearDiophantineEq.h"
#include "LinearDiophantineEqDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinearDiophantineEqDlg dialog

CLinearDiophantineEqDlg::CLinearDiophantineEqDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLinearDiophantineEqDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLinearDiophantineEqDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLinearDiophantineEqDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinearDiophantineEqDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLinearDiophantineEqDlg, CDialog)
	//{{AFX_MSG_MAP(CLinearDiophantineEqDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinearDiophantineEqDlg message handlers

BOOL CLinearDiophantineEqDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLinearDiophantineEqDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLinearDiophantineEqDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Recursive function to calculate gcd of two numbers 
// using euclid's algorithm
int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

// return gcd(a ,b)
// recursive version
int extended_gcd(int a, int b, int &x, int &y) {
    // basic case
    if (0 == b) {
        x = 1;
        y = 0;
        return a;
    }

    // recursive
    int r = extended_gcd(b, a % b, x, y);
    int t = y;
    y = x - (a / b) * y;
    x = t;
    return r;
}

void CLinearDiophantineEqDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
CString str;
GetDlgItemText(IDC_EDIT1,str);
if (str.GetLength()<=0)
return;

int a = atoi(str);
if (a==0)
return;

GetDlgItemText(IDC_EDIT2,str);
if (str.GetLength()<=0)
return;

int b = atoi(str);
if (b==0)
return;

GetDlgItemText(IDC_EDIT3,str);
if (str.GetLength()<=0)
return;

int c = atoi(str);
if (c==0)
return;

int d = gcd(a, b);
char buffer[1000];

		SetDlgItemText(IDC_EDIT5, "");
		SetDlgItemText(IDC_EDIT6, "");
		SetDlgItemText(IDC_EDIT7, "");

		sprintf(buffer, "%d", d);
		SetDlgItemText(IDC_EDIT8, buffer);


		if (!(d % c == 0))
		{
			SetDlgItemText(IDC_EDIT4, "Infinite solutions");
		}
		
		else 
		{
			SetDlgItemText(IDC_EDIT4, "No solutions");
			return;
		}


		int a1 = a / d;
		int b1 = b / d;
		int c1 = c / d;


		sprintf(buffer, "%ds + %dt = %d\n", a1, b1, c1);  // reduced equation
		SetDlgItemText(IDC_EDIT5, buffer);
		int s, t;
		int result = extended_gcd(a1, b1, s, t);

		int x0 = (c / d) * s;
		int y0 = (c / d) * t;

		sprintf(buffer, "x = %d + %dk\n", x0, b / d);  // general solution for x
		SetDlgItemText(IDC_EDIT6, buffer);
		sprintf(buffer, "y = %d - %dk", y0, a / d);  // general solution for y
		SetDlgItemText(IDC_EDIT7, buffer);
}
