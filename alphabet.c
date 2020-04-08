#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alphabet(char suite[],int taille){
    int i;
    char j;
 for(i=0;i<taille;++i)
        {
            if(suite[0]=='+' || suite[0]=='*' || suite[0]=='/' || suite[0]=='^' || suite[taille -1] == '-' || suite[taille -1]=='+' || suite[taille -1]=='*' || suite[taille -1]=='/' || suite[taille -1]=='^')//gerer operateur au debut
                {

                    printf("syntax error operator \a");
                    return -1;
                }
            for(j=' ';j<='~';++j)
                {
                    if(j=='+' || j=='-' || j=='*' || j=='(' || j==')' || j=='/' || j=='^')
                    {
                        if (suite[i]==j )
                        {
                            // pour gerer les operateurs qui ceux suivent
                            if(suite[i+1]=='+' || suite[i+1]=='-' || suite[i+1]=='/' || suite[i+1]=='*' || suite[i+1]=='^')
                            {

                                printf("syntax error \' operators \'");
                                return -1;
                            }
                        }
                        continue;
                    }
                    //       pour gerer l'intrusion des chaines de caracteres
                    if(j=='0' || j=='1' || j=='2' || j=='3' || j=='4' || j=='5' || j=='6' || j=='7' || j=='8' || j=='9')
                        continue;
                    else if(suite[i]==j)
                    {
                        printf("error \' caracters not allow \'\a");
                        return -1;

                    }

            }

    }
    return 0;

}

