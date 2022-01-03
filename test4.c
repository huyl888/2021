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
		L"�ҵ�Ӧ�ó���",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		420,
		360,
		NULL,
		// ���ز˵���Դ
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
			TEXT("��û�ӭ�������������!"),
			-1,
			&rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER
		);
	case WM_COMMAND:
	{
		// ȡ����ԴIdֵ
		// ���ж��û�ѡ�����ĸ��˵���
		switch (LOWORD(wParam))
		{
		case ID_40001:
			MessageBox(hwnd, L"�һ����ˡ�", L"��ʾ", MB_OK);
			break;
		case ID_40002:
			MessageBox(hwnd, L"���ڵ��ɡ�", L"��ʾ", MB_OK);
			break;
		case ID_40003:
			MessageBox(hwnd, L"ɽ����������¥��", L"��ʾ", MB_OK);
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