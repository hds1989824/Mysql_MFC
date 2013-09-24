/*
#pragma once

class sqltest
{
public:
	sqltest(void);
	~sqltest(void);
};
*/

#include "StdAfx.h"
#include <iostream>
#include <stdlib.h>
#include <WinSock2.h>
#include "mysql.h"
#include <time.h>
#include <fstream>

using namespace std;

class sqltest
{
public:
	sqltest(void);
	~sqltest(void);
	//初始化对象，变量
	MYSQL mysql;
	MYSQL *Pmysql;
	MYSQL_RES *res;
	MYSQL_ROW row;

	void mysql__init();
	HANDLE mysql__real__connet();
	//HANDLE mysql__real__connet(MYSQL mysql,CString MysqlIP,CString MysqlUserName,CString MysqlPwd,CString MysqlDb);
	int mysql__real__query(MYSQL *mysql, const char *q,unsigned long length);
	MYSQL_RES * mysql__store__result(MYSQL *mysql);
	MYSQL_ROW mysql__fetch__row(MYSQL_RES *result);
	void mysql__free__result(MYSQL_RES *result);
	void mysql__close(MYSQL *sock);

	//获得当前时间
	char GetNowTime();
	//保存到文件
	void Num2Text(char *pBuffer,int nLength);
	void Fwrite(MYSQL_RES *res);
};

