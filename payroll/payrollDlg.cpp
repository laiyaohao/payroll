
// payrollDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "payroll.h"
#include "payrollDlg.h"
#include "afxdialogex.h"

#include <ctime>
#include <string>

using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CpayrollDlg dialog



CpayrollDlg::CpayrollDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAYROLL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CpayrollDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CpayrollDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(btnRun, &CpayrollDlg::OnBnClickedbtnrun)
	ON_BN_CLICKED(btnProcessIt, &CpayrollDlg::OnBnClickedbtnprocessit)
END_MESSAGE_MAP()


// CpayrollDlg message handlers

BOOL CpayrollDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CpayrollDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CpayrollDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CpayrollDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CpayrollDlg::OnBnClickedbtnrun()
{
	// TODO: Add your control notification handler code here
}


void CpayrollDlg::OnBnClickedbtnprocessit()
{
	// TODO: Add your control notification handler code here
	// employeeId
	CString textInput;
	GetDlgItemText(txtEmployeeId, textInput);
	double dEmployeeId = _ttof(textInput);

	// hourly wage
	GetDlgItemText(txtHourlyWage, textInput);
	double dHourlyWage = _ttof(textInput);

	GetDlgItemText(txtFirstWeekMonday, textInput);
	double dFirstMonday = _ttof(textInput);

	GetDlgItemText(txtFirstWeekTuesday, textInput);
	double dFirstTuesday = _ttof(textInput);

	GetDlgItemText(txtFirstWeekWednesday, textInput);
	double dFirstWednesday = _ttof(textInput);

	GetDlgItemText(txtFirstWeekThursday, textInput);
	double dFirstThursday = _ttof(textInput);

	GetDlgItemText(txtFirstWeekFriday, textInput);
	double dFirstFriday = _ttof(textInput);

	GetDlgItemText(txtFirstWeekSaturday, textInput);
	double dFirstSaturday = _ttof(textInput);

	GetDlgItemText(txtFirstWeekSunday, textInput);
	double dFirstSunday = _ttof(textInput);

	// second week

	GetDlgItemText(txtSecondWeekMonday, textInput);
	double dSecondMonday = _ttof(textInput);

	GetDlgItemText(txtSecondWeekTuesday, textInput);
	double dSecondTuesday = _ttof(textInput);

	GetDlgItemText(txtSecondWeekWednesday, textInput);
	double dSecondWednesday = _ttof(textInput);

	GetDlgItemText(txtSecondWeekThursday, textInput);
	double dSecondThursday = _ttof(textInput);

	GetDlgItemText(txtSecondWeekFriday, textInput);
	double dSecondFriday = _ttof(textInput);

	GetDlgItemText(txtSecondWeekSaturday, textInput);
	double dSecondSaturday = _ttof(textInput);

	GetDlgItemText(txtSecondWeekSunday, textInput);
	double dSecondSunday = _ttof(textInput);

	double week1hours = 0;
	double week2hours = 0;
	week1hours = dFirstMonday + dFirstTuesday + dFirstWednesday + dFirstThursday + dFirstFriday + dFirstSaturday + dFirstSunday;
	week2hours = dSecondMonday + dSecondTuesday + dSecondWednesday + dSecondThursday + dSecondFriday + dSecondSaturday + dSecondSunday;
	
	double regularhoursweek1 = 0;
	double regularhoursweek2 = 0;
	double totalhours = 0;

	double overtimehoursweek1 = 0;
	double overtimehoursweek2 = 0;

	double totalovertime = 0;

	double regularamountpay = 0;
	double overtimeamountpay = 0;
	double totalearnings = 0;

	if (week1hours > 40) {
		regularhoursweek1 = 40;
		overtimehoursweek1 = week1hours - 40;
	}
	else {
		regularhoursweek1 = week1hours;
	}

	if (week2hours > 40) {
		regularhoursweek2 = 40;
		overtimehoursweek2 = week2hours - 40;
	}
	else {
		regularhoursweek2 = week2hours;
	}
	totalhours = regularhoursweek1 + regularhoursweek2;
	totalovertime = overtimehoursweek1 + overtimehoursweek2;

	regularamountpay = dHourlyWage * totalhours;
	overtimeamountpay = (dHourlyWage * 1.5) * totalovertime;

	totalearnings = regularamountpay + overtimeamountpay;

	string strtotalhours = to_string(totalhours);
	CString totalregularhours(strtotalhours.c_str());
	SetDlgItemText(txtRegularHours, totalregularhours);

	string strtotalovertimehours = to_string(totalovertime);
	CString totalovertimehours(strtotalovertimehours.c_str());
	SetDlgItemText(txtOvertimeHours, totalovertimehours);

	string strregularamount = to_string(regularamountpay);
	CString totalregularamount(strregularamount.c_str());
	SetDlgItemText(txtRegularAmount, totalregularamount);

	string strovertimeamount = to_string(overtimeamountpay);
	CString totalovertimeamount(strovertimeamount.c_str());
	SetDlgItemText(txtOvertimeHours, totalovertimeamount);

	string strtotalearnings = to_string(totalearnings);
	CString CStotalearnings(strtotalearnings.c_str());
	SetDlgItemText(txtTotalEarnings, CStotalearnings);
}
