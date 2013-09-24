// TestMfcDlg.cpp : 实现文件
//
#pragma comment(lib,"libmysql.lib")
#include "stdafx.h"
#include "TestMfc.h"
#include "TestMfcDlg.h"
#include "TestCalc.h"
#include "sqltest.h"
#include <WinSock2.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMfcDlg 对话框




CTestMfcDlg::CTestMfcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestMfcDlg::IDD, pParent)
	, Calc_Result(0)
	, Calc_Num1(0)
	, Calc_Num2(0)
	, Mysql_Ip(_T(""))
	, Mysql_UserName(_T(""))
	, Mysql_Pwd(_T(""))
	, Mysql_Query_Ruslt(_T(""))
	, Mysql_Db(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Calc_Result);
	DDX_Control(pDX, IDC_BUTTON1, Calc_Button);
	DDX_Text(pDX, IDC_EDIT2, Calc_Num1);
	DDX_Text(pDX, IDC_EDIT3, Calc_Num2);
	DDX_Text(pDX, IDC_EDIT4, Mysql_Ip);
	DDX_Text(pDX, IDC_EDIT5, Mysql_UserName);
	DDX_Text(pDX, IDC_EDIT6, Mysql_Pwd);
	DDX_Text(pDX, IDC_EDIT7, Mysql_Query_Ruslt);
	DDX_Text(pDX, IDC_EDIT8, Mysql_Db);
}

BEGIN_MESSAGE_MAP(CTestMfcDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CTestMfcDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CTestMfcDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CTestMfcDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CTestMfcDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestMfcDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTestMfcDlg 消息处理程序

BOOL CTestMfcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
   return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestMfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestMfcDlg::OnBnClickedButton1()  //计算button
{
	// TODO: 在此添加控件通知处理程序代码
    TestCalc testcalc;
	UpdateData();
	int sum=testcalc.TestAdd(Calc_Num1,Calc_Num2);
	Calc_Result=sum;
	UpdateData(FALSE);
}

void CTestMfcDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTestMfcDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
void CTestMfcDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CTestMfcDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	sqltest sql;
	 MYSQL mysql;
	sql.mysql__init();//初始化

 
    

 	if (sql.mysql__real__connet())
 	{}else{}
    
	/*
	 //name：查询
	//input：mysql 语句	
	//output：0
	//time：
	*/
	const char* w;
	w="select count(*) from carinfo";
	if (sql.mysql__real__query(&sql.mysql,w,(unsigned long)strlen(w)))
	{
	}
	else
	{	
		printf("查询成功\n");
	}
	
	//存储结果集
	sql.res=sql.mysql__store__result(&sql.mysql);
	if (NULL==sql.res)
	{
		printf("保存失败");
		//return 0;
	}
	/*
	//name：输出结果
	//goal：返回查询结果
	//input：mysql对象的res
	//output：row
	//author:liuz
	*/
	while (sql.row=sql.mysql__fetch__row(sql.res))
	{
		printf("当前时间为：\n");
		sql.GetNowTime();
		cout<<"您的查询为："<<w<<";"<<endl;
		cout<<"查询结果："<<sql.row[0]<<endl;
		break;
		//cin.get();
	}
	UpdateData(TRUE);   //从控件读入参数
	Mysql_Query_Ruslt=sql.row[0];
	UpdateData(FALSE);
  
	/*
	//name：释放结果集
	//input：	
	//output：
	//time：
	*/
	sql.mysql__free__result(sql.res);
	
	/*
	//name：
	//goal：
	//input：	
	//output：
	//author:
	*/
	sql.mysql__close(&sql.mysql);



}
