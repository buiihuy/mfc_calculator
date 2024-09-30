
// CalculatorDlg.h : header file
//

#pragma once
#include<queue>


// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// raw calculation when click buttons
	CString raw_calc;
	CString str_edit2;
	double num1, num2, memory;
	bool is_digit;
	bool first_equal;
	bool is_equal;
	bool is_edit;
	std::queue<double> my_num;
	std::queue<char> my_operator;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedZero();
	afx_msg void OnBnClickedOne();
	afx_msg void OnBnClickedTwo();
	afx_msg void OnBnClickedThree();
	afx_msg void OnBnClickedFour();
	afx_msg void OnBnClickedFive();
	afx_msg void OnBnClickedSix();
	afx_msg void OnBnClickedSeven();
	afx_msg void OnBnClickedEight();
	afx_msg void OnBnClickedNine();
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDevide();
	afx_msg void OnBnClickedPoint();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedClearEntry();
	afx_msg void OnBnClickedOpposite();
	afx_msg void OnBnClickedSqrt();
	afx_msg void OnBnClickedInverse();
	afx_msg void OnBnClickedMc();
	afx_msg void OnBnClickedMr();
	afx_msg void OnBnClickedMs();
	afx_msg void OnBnClickedMplus();
	afx_msg void OnBnClickedMsub();
	afx_msg void OnBnClickedPercent();
};
