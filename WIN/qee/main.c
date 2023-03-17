#include <stdio.h>
#include <stdlib.h>

#define _WIN64_WINNT 0x0A00

#include <windows.h>

int main()
{
    char c[1024];
    HWND hwnd = GetConsoleWindow();
      //  HWND hwnd = GetDesktopWindow();

int i=0, r=0;
do
{
    i++;
    HDC dc = GetDC(hwnd);
    SelectObject(dc, GetStockObject(DC_BRUSH));
    SetDCBrushColor(dc, RGB(255,255,255));
    SelectObject(dc, GetStockObject(DC_PEN));
    SetDCPenColor(dc, RGB(255,255,255));
    Rectangle(dc, 0, 0, 1100, 600);

    SelectObject(dc, GetStockObject(DC_BRUSH));
    SetDCBrushColor(dc, RGB(0,255,0));
    Rectangle(dc, 0,60, 40,100);

    for(int j=1100;j>0;j--)
    {

    SelectObject(dc, GetStockObject(DC_BRUSH));
    SetDCBrushColor(dc, RGB(0,255,0));
    Rectangle(dc, 0+j,0, 50+j,50);

    if (GetKeyState(VK_SPACE)>=0)  r=0;
    else r=1;
    if (r==1){
            for(int f=0;f<10;f++){
    SelectObject(dc, GetStockObject(DC_BRUSH));
    SetDCBrushColor(dc, RGB(0,255,0));
    Rectangle(dc, 0,60-f, 40,100-f);
    Sleep(10);
     }
     for(int f=10;f>0;f--){
    SelectObject(dc, GetStockObject(DC_BRUSH));
    SetDCBrushColor(dc, RGB(0,255,0));
    Rectangle(dc, 0,60-f, 40,100-f);

            }
            r=0;

    }
    Sleep(10);
    sprintf(c, "wwwwww");
    TextOutA(dc, 20,50, c, strlen(c)+1);
    }




   // Sleep(1);
} while (GetKeyState(VK_ESCAPE)>=0);
    return 0;

}
