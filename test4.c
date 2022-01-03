#include <Windows.h>
#include "resource.h"

LRESULT CALLBACK MyWinProce(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR cmdLine,
	int nShow
){
	WCHAR * szClassName = L"Myapp";
	WNDCLASS wc;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = szClassName;
	wc.lpszMenuName = LoadIcon(hInstance, IDR_MENU1);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = MyWinProce;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	
	RegisterClass(&wc);
	HWND hm = CreateWindow(
		szClassName,
		L"我的应用程序",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		420,
		360,
		NULL,
		// 加载菜单资源
		LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1)),
		hInstance,
		NULL);
	if (hm == NULL)
		return 0;
	ShowWindow(hm, nShow);
	UpdateWindow(hm);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}


LRESULT CALLBACK MyWinProce(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	switch (msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(
			hdc,
			TEXT("你好欢迎来到炫舞的世界!"),
			-1,
			&rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER
		);
	case WM_COMMAND:
	{
		// 取出资源Id值
		// 并判断用户选择了哪个菜单项
		switch (LOWORD(wParam))
		{
		case ID_40001:
			MessageBox(hwnd, L"灰机来了。", L"提示", MB_OK);
			break;
		case ID_40002:
			MessageBox(hwnd, L"让炮弹飞。", L"提示", MB_OK);
			break;
		case ID_40003:
			MessageBox(hwnd, L"山炮欲来风满楼。", L"提示", MB_OK);
			break;
		default:
			break;
		}
	}
	return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}