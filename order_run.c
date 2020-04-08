#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    fflush(stdout);
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void saisir(char suite[256])
{
    strcpy(suite,"");
    int k =65;
    int i=0,c=0;
    gotoxy(k,5);
    c = getche();
    suite[i] = c;
    i++;

         while (c != 13 && suite[0] != 8)
         {
              system("color 0C");
              system("color 07");
               c = getche();

              if (c == 8)
              {
                  while ( c == 8 && i!= 0)
                 {
                     gotoxy(k,5);printf(" ");gotoxy(k,5);
                     c = getche();
                     suite[i-1] = c;
                     i = i-1;
                     k = k-1;

                  }

             }
             else
             {
                    suite[i] = c;
             }


          i+=1;
          k+=1;
         }
         suite[i-1] = '\0';

}




void rectangle(int x, int y, int l, int h)
{
        int i;
    gotoxy(x,y);printf("%c",218);
    gotoxy(x+l,y);printf("%c",191);
    gotoxy(x,y+h);printf("%c",192);
    gotoxy(x+l,y+h);printf("%c",217);
    for(i=1;i<l;i++){gotoxy(x+i,y);printf("%c",196);gotoxy(x+i,y+h);printf("%c",196);}
    for(i=1;i<h;i++){gotoxy(x,y+i);printf("%c",179);gotoxy(x+l,y+i);printf("%c",179);}
}
void rextange_rectangle()
{
    rectangle(50,2,50,30);
    rectangle(52,4,45,5);
    rectangle(52,12,45,19);

    rectangle(60,14,5,2); gotoxy(62,15);printf("-");
     rectangle(73,14,5,2); gotoxy(75,15);printf("0");
     rectangle(85,14,5,2); gotoxy(87,15);printf("+");
     //rectangle(87,14,5,2);

      rectangle(57,19,5,2); gotoxy(59,20);printf("1");
      rectangle(67,19,5,2); gotoxy(69,20);printf("2");
     rectangle(77,19,5,2); gotoxy(79,20);printf("3");
     rectangle(87,19,5,2); gotoxy(89,20);printf("^");

      rectangle(57,22,5,2); gotoxy(59,23);printf("4");
      rectangle(67,22,5,2); gotoxy(69,23);printf("5");
     rectangle(77,22,5,2); gotoxy(79,23);printf("6");
     rectangle(87,22,5,2); gotoxy(89,23);printf("/");

     rectangle(57,25,5,2); gotoxy(59,26);printf("7");
      rectangle(67,25,5,2); gotoxy(69,26);printf("8");
     rectangle(77,25,5,2); gotoxy(79,26);printf("9");
     rectangle(87,25,5,2); gotoxy(89,26);printf("*");
     gotoxy(59,29);printf("Coded by Elwis SOVIGUIDI (SAMPAY2.0)");



}
