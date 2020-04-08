#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

typedef struct opera opera;
struct opera{
int tab_operators[126];
int index_of_operators[126];
};

void order(char operato,char suite[256])
{

    int bloc = 0;
    double s=0;
    char calc[256];
    int taillo = 0,io=0,iop = 0;
    int indix_prev = 0, indix_next = 0, k=0;
    int taille = 0 ,i=0,j=0;
    char a[256] = "";
    char  b[256] = "";
    opera *op=NULL;
    op = malloc(sizeof(opera));
    char calcul[256] = "", calcul2[256] = "";
    long moins = 0;



    strcpy(calcul, suite);


    while (calcul[i] != '\0')
    {
        if (calcul[i] == '+' || calcul[i] == '-' || calcul[i] == '*' || calcul[i] == '/' || calcul[i] == '^' )
        {
            op->tab_operators[j] = calcul[i];
            op->index_of_operators[j] = i;
            j++;
        }
        i++;
    }
    taille = j;
    j= 0;
     while (j < taille )
    {
        if (op->tab_operators[j] == operato)
        {
            taillo++;

        }
         j++;
    }

    j=0;

    if (op->tab_operators[0] == '-' && op->tab_operators[1] == '^'  )
    {
        moins = 1;
    }
    for(i = 0; i < taille; i++)
    {
        if (op->tab_operators[i] == operato)
        {
            if (i+1 == taille)
            {
                io = strlen(calcul);
                k = 0;
                if (i-1 != -1 )
                    indix_prev =  op->index_of_operators[i-1]+1;

                for (j=indix_prev  ;j<op->index_of_operators[i];j++)
                {
                    a[k]= calcul[j];
                    k++;
                }
                a[k] ='\0';
                k=0;
                 for (j=op->index_of_operators[i]+1 ;j<strlen(calcul);j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] = '\0';

                if (moins == 1 && i == 1 && atoi(b) % 2 == 0 )
                {
                    calcul[0] = '+';
                }

                sprintf(calc,"%f",pow(atof(a),atof(b)));
                    if(i-1 != -1)
                {
                    for(j=indix_next; j <= indix_prev - 1;j++ )
                    {
                        calcul2[bloc] = calcul[j];
                        bloc++;
                    }
                }
                strcat(calcul2,calc);



           continue;
            }
            else

                if(i-1 == -1)
            {
                k=0;
                indix_next = op->index_of_operators[i+1];
                for (j = op->index_of_operators[i]+1 ;j<indix_next;j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';
                k=0;
                for(j = 0 ;j < op->index_of_operators[i]; j++)
                {
                    a[k] =calcul[j];
                    k++;
                }
                a[k] ='\0';
                s = pow(atof(a),atof(b));

                iop=i + 1;
                while(op->tab_operators[iop] == operato && iop < taille)
                {
                    k=0;
                    if (iop+1 == taille)
                    {    indix_next = strlen(calcul);
                         i = taille;
                    }

                    else
                        indix_next = op->index_of_operators[iop+1];

                for (j = op->index_of_operators[iop]+1 ;j<indix_next;j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';

                s = pow(s,atof(b));
                i = iop;
                 iop++;
                }

                sprintf(calc,"%lf",s);

                strcpy(calcul2,calc);

                bloc = strlen(calcul2);
            }
            else
            {
                for(io = indix_next;io <= op->index_of_operators[i-1];io++)
                {
                    calcul2[bloc] = calcul[io];
                    bloc++;

                }
                calcul2[bloc] = '\0';
                k = 0;

                indix_next =  op->index_of_operators[i+1] ;
                indix_prev =  op->index_of_operators[i-1] +1;

                j = 0;
                for(j = indix_prev; j < op->index_of_operators[i];j++)
                {
                    a[k] =calcul[j];
                    k++;
                }
                a[k] ='\0';
                k = 0;

                 for (j=op->index_of_operators[i]+1; j<indix_next; j++)
                {

                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';

                if (moins == 1 && i == 1 && atoi(b) % 2 == 0 )
                {
                        calcul[0] = '+';
                        moins = 0;
                }

                s = pow(atof(a),atof(b));
                iop=i + 1;
                while(op->tab_operators[iop] == operato && iop < taille)
                {
                    k=0;
                    if (iop+1 == taille)
                    {    indix_next = strlen(calcul);
                         i = taille;
                    }

                    else
                        indix_next = op->index_of_operators[iop+1];

                for (j = op->index_of_operators[iop]+1 ;j<indix_next;j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';
                s = pow(s,atof(b));
                i = iop;
                 iop++;
                }
                sprintf(calc,"%lf",s);
                strcat(calcul2,calc);
                bloc = strlen(calcul2);

                k =0;

            }

        }
    }
    if (io != strlen(calcul)&& j != 0 )
    {
        io = indix_next;
        while (io < strlen(calcul))
        {
            calcul2[bloc] = calcul[io];
            bloc++;
            io++;
        }

    }


    strcpy(suite,calcul2);
}

int order_multi_divise(char *suite)
{

    int bloc = 0;
    double s = 0;
    char calc[100];
    int taillo = 0,io=0,iop = 0;
    int indix_prev = 0, indix_next = 0, k=0;
    int taille = 0 ,i=0,j=0;
    char a[255] = "";
    char  b[255] = "";
    opera *op=NULL;
    op = malloc(sizeof(opera));
    char calcul[255] = "", calcul2[255] = "";


    strcpy(calcul, suite);


    while (calcul[i] != '\0')
    {
        if (calcul[i] == '+' || calcul[i] == '-' || calcul[i] == '*' || calcul[i] == '/' || calcul[i] == '^' )
        {
            op->tab_operators[j] = calcul[i];
            op->index_of_operators[j] = i;
            j++;
        }
        i++;
    }
    taille = j;
    j= 0;
     while (j < taille )
    {
        if (op->tab_operators[j] == '*' ||  op->tab_operators[j] == '/')
        {
            taillo++;

        }
         j++;
    }


    j=0;

    for(i=0;i<taille;i++)
    {
        if (op->tab_operators[i] == '*')
        {
            if (i+1 == taille)
            {
                io = strlen(calcul);
                k = 0;
                if (i-1 != -1 )
                    indix_prev =  op->index_of_operators[i-1]+1;

                for (j=indix_prev  ;j<op->index_of_operators[i];j++)
                {
                    a[k]= calcul[j];
                    k++;
                }
                a[k] ='\0';

                k=0;
                 for (j=op->index_of_operators[i]+1 ;j<strlen(calcul);j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] = '\0';
                if (op->tab_operators[i-1]  == '/')
                {
                    sprintf(a,"%f",s);
                }

                s = atof(a) * atof(b);
                sprintf(calc,"%f",s);


                if(i-1 != -1)
                {
                    for(j=indix_next; j <= indix_prev - 1;j++ )
                    {
                        calcul2[bloc] = calcul[j];
                        bloc++;
                    }
                }
                strcat(calcul2,calc);



           continue;
            }
            else

                if(i-1 == -1)
            {
                k=0;
                indix_next = op->index_of_operators[i+1];
                for (j = op->index_of_operators[i]+1 ;j<indix_next;j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';
                k=0;
                for(j = 0 ;j < op->index_of_operators[i]; j++)
                {
                    a[k] =calcul[j];
                    k++;
                }
                a[k] ='\0';

                s = atof(a) * atof(b);
                iop=i + 1;
                while(op->tab_operators[iop] == '*' && iop < taille)
                {
                    k=0;
                    if (iop+1 == taille)
                    {    indix_next = strlen(calcul);
                         i = taille;
                    }

                    else
                        indix_next = op->index_of_operators[iop+1];

                for (j = op->index_of_operators[iop]+1 ;j<indix_next;j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';
                s *= atof(b);
                i = iop;
                 iop++;
                }
                sprintf(calc,"%lf",s);

                if (op->tab_operators[i+1] != '/')
                strcpy(calcul2,calc);

                bloc = strlen(calcul2);
            }
            else
            {
                for(io = indix_next;io <= op->index_of_operators[i-1];io++)
                {
                    calcul2[bloc] = calcul[io];
                    bloc++;

                }
                calcul2[bloc] = '\0';
                k = 0;

                indix_next =  op->index_of_operators[i+1] ;
                indix_prev =  op->index_of_operators[i-1] +1;

                j = 0;
                for(j = indix_prev; j < op->index_of_operators[i];j++)
                {

                    a[k] =calcul[j];
                    k++;
                }
                a[k] ='\0';
                k = 0;

                 for (j=op->index_of_operators[i]+1; j<indix_next; j++)
                {

                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';

                if (op->tab_operators[i-1]  == '/')
                {
                    sprintf(a,"%f",s);
                }

                s = atof(a) * atof(b);

                iop=i + 1;
                while(op->tab_operators[iop] == '*' && iop < taille)
                {
                    k=0;
                    if (iop+1 == taille)
                    {    indix_next = strlen(calcul);
                         i = taille;
                    }

                    else
                        indix_next = op->index_of_operators[iop+1];

                for (j = op->index_of_operators[iop]+1 ;j<indix_next;j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';

                s *= atof(b);
                i = iop;
                 iop++;
                }

                sprintf(calc,"%lf",s);


                if (op->tab_operators[i+1] != '/')
                strcat(calcul2,calc);

                bloc = strlen(calcul2);


                k =0;

            }

        }
        else
            if(op->tab_operators[i] == '/')
            {
                if (i+1 == taille)
            {
                io = strlen(calcul);
                k = 0;
                if (i-1 != -1 )
                    indix_prev =  op->index_of_operators[i-1]+1;

                for (j=indix_prev  ;j<op->index_of_operators[i];j++)
                {
                    a[k]= calcul[j];
                    k++;
                }
                a[k] ='\0';
                k=0;
                 for (j=op->index_of_operators[i]+1 ;j<strlen(calcul);j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] = '\0';

                if (atof(b) == atof("0"))
                {
                    //gotoxy(60,7);
                    printf("cannot divide by zero ");
                    strcpy(suite,"");
                    return -1;
                }

                if (op->tab_operators[i-1]  == '*')
                {
                    sprintf(a,"%f",s);
                }
                s = atof(a) / atof(b);
                sprintf(calc,"%f",s);

                if(i-1 != -1)
                {
                    for(j=indix_next; j <= indix_prev - 1;j++ )
                    {
                        calcul2[bloc] = calcul[j];
                        bloc++;
                    }
                }
                strcat(calcul2,calc);



           continue;
            }
            else

                if(i-1 == -1)
            {
                k=0;
                indix_next = op->index_of_operators[i+1];
                for (j = op->index_of_operators[i]+1 ;j<indix_next;j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';

                if (atof(b) == atof("0"))
                {
                    printf("cannot divide by zero ");
                    strcpy(suite,"");
                    return -1;
                }

                k=0;
                for(j = 0 ;j < op->index_of_operators[i]; j++)
                {
                    a[k] =calcul[j];
                    k++;
                }
                a[k] ='\0';
                s = atof(a) / atof(b);
                iop=i + 1;

                while(op->tab_operators[iop] == '/' && iop < taille)
                {
                    k=0;
                    if (iop+1 == taille)
                    {    indix_next = strlen(calcul);
                         i = taille;
                    }

                    else
                        indix_next = op->index_of_operators[iop+1];

                for (j = op->index_of_operators[iop]+1 ;j<indix_next;j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';
                if (atof(b) == atof("0"))
                {
                    printf("cannot divide by zero ");
                    strcpy(suite,"");
                    return -1;
                }

                s =s / atof(b);
                i = iop;
                 iop++;
                }

                sprintf(calc,"%lf",s);

                if (op->tab_operators[i+1] != '*')
                strcpy(calcul2,calc);


                bloc = strlen(calcul2);
            }
            else
            {
                for(io = indix_next;io <= op->index_of_operators[i-1];io++)
                {

                    calcul2[bloc] = calcul[io];
                    bloc++;

                }
                calcul2[bloc] = '\0';
                k = 0;

                indix_next =  op->index_of_operators[i+1] ;
                indix_prev =  op->index_of_operators[i-1] +1;

                j = 0;
                for(j = indix_prev; j < op->index_of_operators[i];j++)
                {

                    a[k] =calcul[j];
                    k++;
                }
                a[k] ='\0';
                k = 0;

                 for (j=op->index_of_operators[i]+1; j<indix_next; j++)
                {

                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';
                if (atof(b) == atof("0"))
                {
                    printf("cannot divide by zero ");
                    strcpy(suite,"");
                    return -1;
                }

                if (op->tab_operators[i-1]  == '*')
                {
                    sprintf(a,"%f",s);
                }

                s = atof(a) / atof(b);

                iop=i + 1;
                while(op->tab_operators[iop] == '/' && iop < taille)
                {
                    k=0;
                    if (iop+1 == taille)
                    {    indix_next = strlen(calcul);
                         i = taille;
                    }

                    else
                        indix_next = op->index_of_operators[iop+1];

                for (j = op->index_of_operators[iop]+1 ;j<indix_next;j++)
                {
                    b[k]= calcul[j];
                    k++;
                }
                b[k] ='\0';
                if (atof(b) == atof("0"))
                {
                    printf("cannot divide by zero ");
                    strcpy(suite,"");
                    return -1;
                }

                s /= atof(b);
                i = iop;
                 iop++;
                }

                sprintf(calc,"%lf",s);

                if (op->tab_operators[i+1] != '*')
                strcat(calcul2,calc);

                bloc = strlen(calcul2);


                k =0;

            }


            }
    }
    if (io != strlen(calcul)&& j != 0 )
    {
        io = indix_next;
        while (io < strlen(calcul))
        {

            calcul2[bloc] = calcul[io];
            bloc++;
            io++;
        }

    }

    strcpy(suite,calcul2);
    return 0;
}
