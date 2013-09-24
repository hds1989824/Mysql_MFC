#include "StdAfx.h"
#include "sqltest.h"

sqltest::sqltest(void)
{
}

sqltest::~sqltest(void)
{
}

void sqltest::mysql__init()  //��ʼ��
{
	mysql_init(&mysql);
	printf("mysql�Ѿ���ʼ��...\n");
}

HANDLE sqltest::mysql__real__connet() //mysql ���Ӳ���
{
	return mysql_real_connect(&mysql,"localhost","root","12315","wcms3",3306,0,0);
}


int sqltest::mysql__real__query(MYSQL *mysql, const char *q, unsigned long length )
{
	return mysql_real_query(mysql,q,length);
}


MYSQL_RES * sqltest::mysql__store__result( MYSQL *mysql )  //������
{	
	res=mysql_store_result(mysql);
	return res;
}

MYSQL_ROW sqltest::mysql__fetch__row( MYSQL_RES *result )  //
{
	return mysql_fetch_row(res);
}

void sqltest::mysql__free__result( MYSQL_RES *result )
{
	mysql_free_result(res);
	printf("MYSQL������Ѿ��ͷ�\n");
}

void sqltest::mysql__close( MYSQL *sock )
{
	mysql_close(sock);
	printf("MYSQL�����Ѿ��ر�\n");
}

char sqltest::GetNowTime()
{
	time_t t=time(0);
	char tmp[64];
	strftime(tmp,sizeof(tmp),"%Y/%m/%d %X %A",localtime(&t));
	puts(tmp);
	return 0;
}

void sqltest::Num2Text( char *pBuffer,int nLength )
{
	FILE *fp;
	fp=fopen("num.txt","a+");
	if (pBuffer)
	{
		fwrite(pBuffer,nLength,1,fp);
		printf("num2text");
	}
	fclose(fp);
}

void sqltest::Fwrite(MYSQL_RES *res)
{
	ofstream ofs;
	char filename[1000]="num.txt";
	ofs.open(filename,ofstream::app);
	//ofs<<mysql__fetch__row(res);
	ofs<<mysql__fetch__row(res);
	ofs.close();
	ofs.clear();
	printf("д�ļ�");
}
