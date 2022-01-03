#include "test2.h"

//窗口过程前导声明
LRESULT CALLBACK MyWndProc(HWND, UINT, WPARAM, LPARAM);

//程序入口点
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR szCmdLine,
	int iCmdShow
) {
	//窗口类名
	static TCHAR szClassName[] = TEXT("欢迎");
	//窗口句柄
	HWND	main_hwnd;
	//消息
	MSG		msg;
	//窗口类
	WNDCLASS main_wndcls = {sizeof(szClassName)};
	//窗口风格
	main_wndcls.style = CS_HREDRAW | CS_VREDRAW;
	//窗口背景画刷
	main_wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//窗口过程
	main_wndcls.lpfnWndProc = MyWndProc;
	//当前窗口句柄
	main_wndcls.hInstance = hInstance;
	//窗口图标
	main_wndcls.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	//鼠标样式
	main_wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	//窗口类名
	main_wndcls.lpszClassName = szClassName;

	//注册窗口
	RegisterClass(&main_wndcls);
	
	main_hwnd = CreateWindow(
		szClassName,
		L"欢迎光临",
		WS_OVERLAPPEDWINDOW,
		50, 50,
		1024, 768,
		LoadIcon(NULL, IDI_ICON1),
		LoadIcon(hInstance, MAKEINTRESOURCE(IDR_MENU1)),
		hInstance,
		NULL
	);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK MyWndProc(HWND main_hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	switch (msg)
	{
	case WM_PAINT:
			hdc = BeginPaint(main_hwnd, &ps);
			GetClientRect(main_hwnd, &rect);
			EndPaint(main_hwnd, &ps);
	}
	return 0;
}