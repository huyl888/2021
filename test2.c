#include "test2.h"

//���ڹ���ǰ������
LRESULT CALLBACK MyWndProc(HWND, UINT, WPARAM, LPARAM);

//������ڵ�
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR szCmdLine,
	int iCmdShow
) {
	//��������
	static TCHAR szClassName[] = TEXT("��ӭ");
	//���ھ��
	HWND	main_hwnd;
	//��Ϣ
	MSG		msg;
	//������
	WNDCLASS main_wndcls = {sizeof(szClassName)};
	//���ڷ��
	main_wndcls.style = CS_HREDRAW | CS_VREDRAW;
	//���ڱ�����ˢ
	main_wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//���ڹ���
	main_wndcls.lpfnWndProc = MyWndProc;
	//��ǰ���ھ��
	main_wndcls.hInstance = hInstance;
	//����ͼ��
	main_wndcls.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	//�����ʽ
	main_wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	//��������
	main_wndcls.lpszClassName = szClassName;

	//ע�ᴰ��
	RegisterClass(&main_wndcls);
	
	main_hwnd = CreateWindow(
		szClassName,
		L"��ӭ����",
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