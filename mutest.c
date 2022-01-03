#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <odbcss.h>
#include <stdio.h>

//SQLHENV henv;//�������
//SQLHDBC hdbc;//���Ӿ��
//SQLHSTMT hstmt;//�����
//SQLRETURN retcode;//����ֵ

SQLHENV henv = SQL_NULL_HENV;
SQLHDBC hdbc1 = SQL_NULL_HDBC;
SQLHSTMT hstmt1 = SQL_NULL_HSTMT;


int main()
{
	RETCODE retcode;
	SQLCHAR ConnStr[255] = "DRIVER=test;SERVER=110.100.1.150:1433;UID=sa;PWD=Hu060727;Trusted_Connection=yes;DATABASE=master;";
	SQLWCHAR outConnStr[255];
	SQLSMALLINT OutConnStrLen;

	//�������
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION,
			(SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	}
	//���Ӿ��
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc1);
	}
	//�������ݿ�
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode = SQLDriverConnect(hdbc1, NULL, (SQLTCHAR*)ConnStr, SQL_NTS, outConnStr, 255, &OutConnStrLen, SQL_DRIVER_NOPROMPT);
	}
	//�ж��Ƿ����ӳɹ�
	if ((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO))
		printf("����ʧ��");
	else
		printf("���ӳɹ�");

	printf("processes finish\n");
	system("pause");

	SQLFreeHandle(SQL_HANDLE_DBC, hdbc1);//�ͷ����Ӿ��
	SQLFreeHandle(SQL_HANDLE_ENV, henv);//�ͷŻ������

	

}