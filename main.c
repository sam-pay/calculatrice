#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "managment.h"
#include <math.h>
#include <conio.h>

int main()
{
     double result=0;
     int lenggth_process;
     char process[256]="";
     int i = 0,c = 0;


    rextange_rectangle();
    gotoxy(53,5);
    //printf(" Welcome in calculator !!! \n \t\t\t\t\t Make your operation \n \n :)  ");
    printf(" Welcome in calculator !!! ");
    gotoxy(70,7);
    printf("Make your operation :)");
    Sleep(3000);


     do
     {


        system("cls");
        rextange_rectangle();
        gotoxy(65,5);
        saisir(process);

        if (strcmp(process,"off") == 0)
        {
            system("cls");
            rextange_rectangle();
            gotoxy(77,7);
            printf("Bye :)");
            gotoxy(1,34);
            exit(EXIT_SUCCESS);
        }

        lenggth_process=strlen(process);

        gotoxy(65,7);
        i = alphabet(process,lenggth_process);
        if (i != -1)
        {
            gotoxy(65,7);
            c = bracket_managment(process,lenggth_process);

        if(c != -1 )

        {
            if (strchr(process,'^') != NULL )
            {
                order('^',process);
                result = atof(process);
            }


            if (strchr(process,'/') != NULL || strchr(process,'*') != NULL)
            {
                gotoxy(70,7);
                i = order_multi_divise(process);
                result = atof(process);
            }

            if (strchr(process,'+') != NULL || strchr(process,'-') != NULL)
            {
                result=number_computation(process,strlen(process));
                sprintf(process,"%lf",result);
            }

        }

        }



        gotoxy(53,7);
        if(i != -1 && c != -1)
        printf("R: %s",process);

        /*gotoxy(1,30);
        printf("\n voulez vous continuez : \n 0-non 1-oui \n 0 ou 1 ==> ");*/
        c = getch();
        while(c != 13 )
        {
            gotoxy(70,8);
            printf("press enter to continue ");
            c = getch();
        }

    }
    while(c == 13);
    //system("pause");

    return 0;
}
