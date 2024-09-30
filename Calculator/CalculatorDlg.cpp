
// CalculatorDlg.cpp : implementation file
#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"


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


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, raw_calc(_T(""))
	, str_edit2(_T(""))
{
	num1 = num2 = memory = 0;
	is_digit= true;
	first_equal = true;
	is_equal = false;
	is_edit = true;
	str_edit2 = "0";
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, raw_calc);
	DDX_Text(pDX, IDC_EDIT2, str_edit2);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_ZERO, &CCalculatorDlg::OnBnClickedZero)
	ON_BN_CLICKED(IDC_ONE, &CCalculatorDlg::OnBnClickedOne)
	ON_BN_CLICKED(IDC_TWO, &CCalculatorDlg::OnBnClickedTwo)
	ON_BN_CLICKED(IDC_THREE, &CCalculatorDlg::OnBnClickedThree)
	ON_BN_CLICKED(IDC_FOUR, &CCalculatorDlg::OnBnClickedFour)
	ON_BN_CLICKED(IDC_FIVE, &CCalculatorDlg::OnBnClickedFive)
	ON_BN_CLICKED(IDC_SIX, &CCalculatorDlg::OnBnClickedSix)
	ON_BN_CLICKED(IDC_SEVEN, &CCalculatorDlg::OnBnClickedSeven)
	ON_BN_CLICKED(IDC_EIGHT, &CCalculatorDlg::OnBnClickedEight)
	ON_BN_CLICKED(IDC_NINE, &CCalculatorDlg::OnBnClickedNine)
	ON_BN_CLICKED(IDC_PLUS, &CCalculatorDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_SUB, &CCalculatorDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &CCalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DEVIDE, &CCalculatorDlg::OnBnClickedDevide)
	ON_BN_CLICKED(IDC_POINT, &CCalculatorDlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_EQUAL, &CCalculatorDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_CLEAR, &CCalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_DELETE, &CCalculatorDlg::OnBnClickedDelete)
	ON_EN_CHANGE(IDC_EDIT2, &CCalculatorDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_CLEAR_ENTRY, &CCalculatorDlg::OnBnClickedClearEntry)
	ON_BN_CLICKED(IDC_OPPOSITE, &CCalculatorDlg::OnBnClickedOpposite)
	ON_BN_CLICKED(IDC_SQRT, &CCalculatorDlg::OnBnClickedSqrt)
	ON_BN_CLICKED(IDC_INVERSE, &CCalculatorDlg::OnBnClickedInverse)
	ON_BN_CLICKED(IDC_MC, &CCalculatorDlg::OnBnClickedMc)
	ON_BN_CLICKED(IDC_MR, &CCalculatorDlg::OnBnClickedMr)
	ON_BN_CLICKED(IDC_MS, &CCalculatorDlg::OnBnClickedMs)
	ON_BN_CLICKED(IDC_MPLUS, &CCalculatorDlg::OnBnClickedMplus)
	ON_BN_CLICKED(IDC_MSUB, &CCalculatorDlg::OnBnClickedMsub)
	ON_BN_CLICKED(IDC_PERCENT, &CCalculatorDlg::OnBnClickedPercent)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
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

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
// th15_t@5k_15_fuck1ng_d1ff1cu!t

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Calc(std::queue<char> &my_operator, std::queue<double> &my_num, double& num1, double num2) {
	num1 = my_num.front();
	my_num.pop();
	num2 = my_num.front();
	my_num.pop();
	switch (my_operator.front()) {
		case '+':
			num1 = num1 + num2;
			break;
		case '-':
			num1 = num1 - num2;
			break;
		case '*':
			num1 = num1 * num2;
			break;
		case '/':
			num1 = num1 / num2;
			break;
		default:
			break;
	}
	my_operator.pop();
	my_num.push(num1);
}

CString Formatt(double num1) {
	CString tmp;
	tmp.Format(_T("%.15g"), num1);
	return tmp;
}

void ToDoForNumber(char c, CString &str_edit2, bool &is_equal, bool &is_edit, bool &is_digit) {
	if (str_edit2[0] == '0' && str_edit2[1] != '.') str_edit2.Delete(0, 1);
	if (is_equal && !is_edit) str_edit2 = "";
	if (is_digit) str_edit2 += c;
	else {
		str_edit2 = "";
		str_edit2 += c;
		is_digit = true;
	}
	is_edit = true;
}

void ToDoForOperator(char c, std::queue<double> &my_num, std::queue<char> &my_operator, 
	CString &raw_calc, CString &str_edit2, 
	bool &is_edit, bool &is_equal, bool &is_digit, bool &first_equal, 
	double &num1, double &num2 ) {
	if (is_equal) {
		while (!my_operator.empty()) my_operator.pop();
	}
	if (is_equal && is_edit) {
		while (!my_num.empty()) my_num.pop();
	}
	if (is_digit) {
		raw_calc += str_edit2;
		raw_calc += c;
		if (is_edit) my_num.push(_tstof(str_edit2));
		my_operator.push(c);
		if (my_num.size() > 1 && my_operator.size() > 1) {
			Calc(my_operator, my_num, num1, num2);
			str_edit2 = Formatt(num1);
		}
	}
	else {
		int length = raw_calc.GetLength();
		raw_calc.Delete(length - 3, 3);
		raw_calc += c;
		my_operator.back() = c;
	}
	is_digit = false;
	first_equal = true;
	is_equal = false;
	is_edit = false;
}

void CCalculatorDlg::OnEnChangeEdit1()
{
	
}

void CCalculatorDlg::OnEnChangeEdit2()
{
	
}

void CCalculatorDlg::OnBnClickedZero()
{
	if (str_edit2 == "0") return;
	if (str_edit2 != "") {
		if (is_digit) {
			str_edit2 += '0';
		}
		else str_edit2 = "0";
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedOne()
{
	ToDoForNumber('1', str_edit2, is_equal, is_edit, is_digit);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedTwo()
{
	ToDoForNumber('2', str_edit2, is_equal, is_edit, is_digit);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedThree()
{
	ToDoForNumber('3', str_edit2, is_equal, is_edit, is_digit);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedFour()
{
	ToDoForNumber('4', str_edit2, is_equal, is_edit, is_digit);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedFive()
{
	ToDoForNumber('5', str_edit2, is_equal, is_edit, is_digit);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedSix()
{
	ToDoForNumber('6', str_edit2, is_equal, is_edit, is_digit);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedSeven()
{
	ToDoForNumber('7', str_edit2, is_equal, is_edit, is_digit);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedEight()
{
	ToDoForNumber('8', str_edit2, is_equal, is_edit, is_digit);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedNine()
{
	ToDoForNumber('9', str_edit2, is_equal, is_edit, is_digit);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedPlus()
{
	ToDoForOperator('+', my_num, my_operator, raw_calc, str_edit2, is_edit, is_equal, is_digit, first_equal, num1, num2);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedSub()
{
	ToDoForOperator('-', my_num, my_operator, raw_calc, str_edit2, is_edit, is_equal, is_digit, first_equal, num1, num2);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedMul()
{
	ToDoForOperator('*', my_num, my_operator, raw_calc, str_edit2, is_edit, is_equal, is_digit, first_equal, num1, num2);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDevide()
{
	ToDoForOperator('/', my_num, my_operator, raw_calc, str_edit2, is_edit, is_equal, is_digit, first_equal, num1, num2);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedPoint()
{
	is_digit = true;
	if (str_edit2.Find('.') != -1) return;
	else str_edit2 += '.';
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedEqual()
{
	if (my_operator.empty()) return;
	raw_calc = "";
	if (is_equal && is_edit) num1 = _tstof(str_edit2);
	else num1 = my_num.front();
	if (first_equal) num2 = _tstof(str_edit2);
	switch (my_operator.front()) {
	case '+':
		num1 = num1 + num2;
		break;
	case '-':
		num1 = num1 - num2;
		break;
	case '*':
		num1 = num1 * num2;
		break;
	case '/':
		num1 = num1 / num2;
		break;
	default:
		break;
	}
	while(!my_num.empty()) my_num.pop();
	my_num.push(num1);
	str_edit2 = Formatt(num1);
	first_equal = false;
	is_equal = true;
	is_edit = false;
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedClear()
{
	raw_calc = "";
	str_edit2 = "0";
	num1 = num2 = 0;
	is_digit = true;
	first_equal = true;
	is_equal = false;
	is_edit = true;
	while (!my_num.empty()) my_num.pop();
	while (!my_operator.empty()) my_operator.pop();
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedDelete()
{
	if (is_edit) {
		if(str_edit2.GetLength()==1 || (str_edit2.GetLength()==2 && str_edit2[0]=='-')) str_edit2 = "0";
		else str_edit2.Delete(str_edit2.GetLength() - 1, 1);
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedClearEntry()
{
	str_edit2 = "0";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedOpposite()
{
	if (str_edit2[0] == '-') str_edit2.Delete(0, 1);
	else str_edit2 = '-' + str_edit2;
	is_edit = true;
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedSqrt()
{
	double tmp = _tstof(str_edit2);
	tmp = sqrt(tmp);
	if (!my_num.empty()) my_num.front() = tmp;
	str_edit2 = Formatt(tmp);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedInverse()
{
	if (str_edit2 == "0") str_edit2 = "C4nn0t d1v1d3 by z3r0";
	else {
		double tmp = _tstof(str_edit2);
		tmp = 1.0 / tmp;
		if (!my_num.empty()) my_num.front() = tmp;
		str_edit2 = Formatt(tmp);
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedMc()
{
	memory = 0;
}


void CCalculatorDlg::OnBnClickedMr()
{
	str_edit2 = Formatt(memory);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedMs()
{
	memory = _tstof(str_edit2);
}


void CCalculatorDlg::OnBnClickedMplus()
{
	memory = memory + _tstof(str_edit2);
}


void CCalculatorDlg::OnBnClickedMsub()
{
	memory = memory - _tstof(str_edit2);
}


void CCalculatorDlg::OnBnClickedPercent()
{
	double tmp;
	if (my_num.empty()) str_edit2 = "0";
	else {
		tmp = _tstof(str_edit2);
		tmp = my_num.front() * (tmp / 100);
		str_edit2 = Formatt(tmp);
	}
	UpdateData(FALSE);
}
