// TestMfcDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CTestMfcDlg �Ի���
class CTestMfcDlg : public CDialog
{
// ����
public:
	CTestMfcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TESTMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	// mysql ��������ַip
	CString Mysql_Ip;
	CString Mysql_UserName;
	CString Mysql_Pwd;
	CString Mysql_Db;
	afx_msg void OnBnClickedButton2();
	CString Mysql_Query_Ruslt;
	
};
