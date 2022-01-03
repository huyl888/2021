#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <odbcss.h>
#include <stdio.h>

//SQLHENV henv;//环境句柄
//SQLHDBC hdbc;//连接句柄
//SQLHSTMT hstmt;//语句句柄
//SQLRETURN retcode;//返回值

SQLHENV henv = SQL_NULL_HENV;
SQLHDBC hdbc1 = SQL_NULL_HDBC;
SQLHSTMT hstmt1 = SQL_NULL_HSTMT;


int main()
{
	RETCODE retcode;
	SQLCHAR ConnStr[255] = "DRIVER=test;SERVER=110.100.1.150:1433;UID=sa;PWD=Hu060727;Trusted_Connection=yes;DATABASE=master;";
	SQLWCHAR outConnStr[255];
	SQLSMALLINT OutConnStrLen;

	//环境句柄
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION,
			(SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	}
	//连接句柄
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc1);
	}
	//连接数据库
	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		retcode = SQLDriverConnect(hdbc1, NULL, (SQLTCHAR*)ConnStr, SQL_NTS, outConnStr, 255, &OutConnStrLen, SQL_DRIVER_NOPROMPT);
	}
	//判断是否连接成功
	if ((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO))
		printf("连接失败");
	else
		printf("连接成功");

	printf("processes finish\n");
	system("pause");

	SQLFreeHandle(SQL_HANDLE_DBC, hdbc1);//释放连接句柄
	SQLFreeHandle(SQL_HANDLE_ENV, henv);//释放环境句柄

	

}