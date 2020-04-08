#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bracket_managment(char suite[],int size){
int openBracket=0, closeBracket=0,i;

for(i=0;i<size;++i)
        {

    //*       pour gerer les parentheses ouvertes et fermentes
             if(suite[i]=='(')
                {
                    openBracket++;
                    if(suite[0]=='(')
                        {
                            if(suite[i+1]=='+' || suite[i+1]=='*' || suite[i+1]=='/' || suite[i+1]=='^')
                                {
                                    gotoxy(60,7);
                                    printf("Error  operator after bracket \' ( \' \a");
                                    return -1;
                                }
                            else
                                continue;
                        }
                    else
                        if(suite[i-1]!='+' && suite[i-1]!='-' && suite[i-1]!='*' && suite[i-1]!='/' && suite[i-1]!='^' )
                            {
                                 gotoxy(60,7);
                                printf("Error  no operator behind bracket \' ( \'  \a");
                                return -1;
                            }
                        else
                            if(suite[i+1]=='+' || suite[i+1]=='*' || suite[i+1]=='/' || suite[i+1]=='^')
                                {
                                     gotoxy(60,7);
                                    printf("Error  operator after bracket \' ( \' \a");
                                    return -1;
                                }
                }
            else if (suite[i]==')')
    {
            closeBracket++;
            if(suite[0]==')')
            {
                 gotoxy(60,7);
                printf("error");
                return -1;
        }
            else if(suite[i-1]!='+' || suite[i+1]!='-' || suite[i+1]!='*' || suite[i+1]!='/' || suite[i+1]!='^' || suite[i+1]!='('  )
        {
                     gotoxy(60,7);
                    printf("Error nor operator nor (   behind bracket  \' ) \' ");
                    return -1;
        }
            else if(suite[i+1]=='(' || suite[i+1]!='+' || suite[i+1]!='-' || suite[i+1]!='*' || suite[i+1]!='/' || suite[i+1]=='^')
        {
                         gotoxy(60,7);
                        printf("Error  bracket \' ( \' or no opeator ");
                        return -1;
        }
    }
}
if(openBracket!=closeBracket)
            {
                 gotoxy(60,7);
                printf("Syntax error \' ( \' ");
                return -1;
            }
     return 0;
}
