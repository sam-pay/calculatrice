#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double number_computation(char chaine[],int size)
{
    int i,k=0;
    char *op;
    double top;
    double calcul=0;

    for(i=0;i<size;i++)
    {
        if( chaine[i] == '+' || chaine[i] == '-'  )
        {
           k++;
        }

    }

    top = strtod(chaine,&op);
    calcul = top;

    for(i=0;i<=k;i++)
    {
        switch ( *op )
        {
            case '+':
            case '-':

                 top = strtod(op,&op);
                 calcul+=top;
            break;

        }

    }
    return calcul;
}
