// TestMfcDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CTestMfcDlg 对话框
class CTestMfcDlg : public CDialog
{
// 构造
public:
	CTestMfcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 132
	int Calc_Result;
	// 123123
	CButton Calc_Button;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	int Calc_Num1;
	int Calc_Num2;
	afx_msg void OnEnChangeEdit3();
	// mysql 服务器地址ip
	CString Mysql_Ip;
	CString Mysql_UserName;
	CString Mysql_Pwd;
	CString Mysql_Db;
	afx_msg void OnBnClickedButton2();
	CString Mysql_Query_Ruslt;
	
};
