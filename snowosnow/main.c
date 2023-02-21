#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <windows.h>

#include "line.c"
//#include "sneg1.c"

#define h1 12
#define w1 80

#define h2 15
#define w2 80
char mas1[h1][w1+1];
char mas2[h2][w2+1];

void init1()
{
    for (int i=0; i<w1;i++)
        mas1[0][i] =' ';
    mas1[0][w1] ='\0';
    for (int i=1; i<h1; i++)
    sprintf(mas1[i], mas1[0]);
}

void show1()
{
    mas1[h1-1][w1-1]='\0';
    for  (int i=0; i<h1; i++)
    printf(mas1[i]);
}

void newSnow1()
{
    for (int i=0; i<w1; i++)
        if (rand() %10 ==1)
        mas1[0][i] = '*';

}
void moveSnow1()
{
    int dx;
    for (int j=h1-1; j>=0; j--)
        for (int i=0; i<w1; i++)
        if (mas1[j][i] == '*')
    {
        mas1[j][i]=' ';
        dx=0;
        if (rand()%10<1) dx++;
        if (rand()%10<1) dx--;
        dx+=i;
        if (dx>=0 && (dx<w1) && (j+1<h1))
           mas1[j+1][dx] ='*';
    }
}

void setcur1(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}



void init2()
{
    for (int i=0; i<w2;i++)
        mas2[0][i] =' ';
    mas2[0][w2] ='\0';
    for (int i=1; i<h2; i++)
    sprintf(mas2[i], mas2[0]);
}

void show2()
{
    mas2[h2-1][w2-1]='\0';
    for  (int i=0; i<h2; i++)
    printf(mas2[i]);
}

void newSnow2()
{
    for (int i=0; i<w2; i++)
        if (rand() %10 ==1)
        mas2[0][i] = '*';

}
void moveSnow2()
{
    int dx;
    for (int j=h2-1; j>=0; j--)
        for (int i=0; i<w2; i++)
        if (mas2[j][i] == '*')
    {
        mas2[j][i]=' ';
        dx=0;
        if (rand()%10<1) dx++;
        if (rand()%10<1) dx--;
        dx+=i;
        if (dx>=0 && (dx<w2) && (j+1<h2))
           mas2[j+1][dx] ='*';
    }
}

void setcur2(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}


int main()
{
   init1();
   init2();
   lin1();


 do
   {
     setcur1(0,0);
     moveSnow1();
     newSnow1();
     show1();

     setcur2(0,20);
     moveSnow2();
     newSnow2();
     show2();

     Sleep(100);
   } while (GetKeyState(VK_ESCAPE)>=0);

    return 0;
}
