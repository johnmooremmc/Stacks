#include <stdio.h>
#include <stdlib.h>

int main()
{

    char str[64];
    char plch[64];
    char str_holder[64];
    char stack[256][256];

    int len;
    int i, j, k;
    int fac = 1;

    printf("Enter A String: ");
    scanf("%s", &str);
    len = strlen(str);


    for(i=0; i<len; i++) {
        str_holder[i] = str[i];
        plch[i] = str[i];
            }

    for(i=1; i<len; i++)
    {
        fac *= i+1;
    }

    printf("\n");
    printf("%s Has %d Arrangements\n", str, fac);
    printf("\n");


    for(j=0; j<=len-1; j++)
    {
        printf("\n------------\n");

        for(i=0; i<len; i++)
        {
            //printf("\n%d, %d, %d\n", i, j, len);
            if (i+j == len-1)
            {
                plch[0] = str[0];
                str[0] = str[i+j];
                str[i+j] = plch[0];


            }
            else if (i+j < len-1)
            {
                plch[i+j] = str[i+j+1];
                str[i+j+1] = str[i+j];
                str[i+j] = plch[i+j];
            } else
            {

                for (k=0; k<j; k++)
                {
                    plch[k] = str[k+1];
                    str[k+1] = str[k];
                    str[k] = plch[k];
                }

            }

                printf("%d : %s\n", i, str);

        }
        // str = str_holder
        strcpy(str, str_holder);
        strcpy(plch, str_holder);

    }




    return 0;
}
