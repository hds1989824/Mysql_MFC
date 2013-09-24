// TestMfcDlg.cpp : ʵ���ļ�
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


// CTestMfcDlg �Ի���




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


// CTestMfcDlg ��Ϣ�������

BOOL CTestMfcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
   return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestMfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestMfcDlg::OnBnClickedButton1()  //����button
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    TestCalc testcalc;
	UpdateData();
	int sum=testcalc.TestAdd(Calc_Num1,Calc_Num2);
	Calc_Result=sum;
	UpdateData(FALSE);
}

void CTestMfcDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CTestMfcDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
void CTestMfcDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CTestMfcDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	sqltest sql;
	 MYSQL mysql;
	sql.mysql__init();//��ʼ��

 
    

 	if (sql.mysql__real__connet())
 	{}else{}
    
	/*
	 //name����ѯ
	//input��mysql ���	
	//output��0
	//time��
	*/
	const char* w;
	w="select count(*) from carinfo";
	if (sql.mysql__real__query(&sql.mysql,w,(unsigned long)strlen(w)))
	{
	}
	else
	{	
		printf("��ѯ�ɹ�\n");
	}
	
	//�洢�����
	sql.res=sql.mysql__store__result(&sql.mysql);
	if (NULL==sql.res)
	{
		printf("����ʧ��");
		//return 0;
	}
	/*
	//name��������
	//goal�����ز�ѯ���
	//input��mysql�����res
	//output��row
	//author:liuz
	*/
	while (sql.row=sql.mysql__fetch__row(sql.res))
	{
		printf("��ǰʱ��Ϊ��\n");
		sql.GetNowTime();
		cout<<"���Ĳ�ѯΪ��"<<w<<";"<<endl;
		cout<<"��ѯ�����"<<sql.row[0]<<endl;
		break;
		//cin.get();
	}
	UpdateData(TRUE);   //�ӿؼ��������
	Mysql_Query_Ruslt=sql.row[0];
	UpdateData(FALSE);
  
	/*
	//name���ͷŽ����
	//input��	
	//output��
	//time��
	*/
	sql.mysql__free__result(sql.res);
	
	/*
	//name��
	//goal��
	//input��	
	//output��
	//author:
	*/
	sql.mysql__close(&sql.mysql);



}
