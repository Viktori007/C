#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

LRESULT WndProc(HWND hwnd, UINT mesg, WPARAM wparam, LPARAM lparam)
{
    if (mesg == WM_DESTROY)
        PostQuitMessage(0);

    else if (mesg == WM_KEYDOWN)
        printf("code = %d\n", wparam);

    else if (mesg == WM_CHAR)
        printf("%c\n", wparam);

    else if (mesg == WM_MOUSEMOVE)
    {
        int xPos = LOWORD(lparam);
        int yPos = HIWORD(lparam);
        printf("mouse [%d %d]\n", xPos, yPos);
    }

    else if (mesg == WM_LBUTTONDOWN)
        printf("mouse Left Button Down\n");

        else return DefWindowProcA(hwnd, mesg, wparam, lparam);
}

int main()
{
    WNDCLASSA wcl;
        memset(&wcl, 0, sizeof(WNDCLASSA));
        wcl.lpszClassName = "My Window";
        wcl.lpfnWndProc = WndProc; //обрабатывает все сообщения окна
    RegisterClassA(&wcl);

    HWND hwnd;
    hwnd = CreateWindow("my Window", "Window Name", WS_OVERLAPPEDWINDOW, 10,10, 640,480, NULL, NULL, NULL, NULL);
    ShowWindow(hwnd, SW_SHOWNORMAL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0,0))
    {
        TranslateMessage(&msg);
      DispatchMessage(&msg);
      //printf("%d %d\n", msg.message, msg.wParam);
      //if (( msg.message == 275) && (msg.wParam == 1));
    }

    return 0;
}
