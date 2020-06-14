#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "test.h"
#define LEN 1234
#define N (1 << 28)
char* strstr_(const char *, const char *);
int main (int argc, char * argv[])
{
   //char *string1;
    char* res=0;
    double t;
    if ( !(argc == 3)  )
    {
        printf("USAGE %s \'STRING1\' \'STRING2\'\n", argv[0]);
        return 1;
    }
        t = clock ();
    res = test_strcpy(argv[1], argv[2], N, &strstr_);
                t = (clock() - t);
                if (res==0)  printf("\nNO SUCH SUBSTRING\n");
                else printf("\n RESULT:%s\n",res);
     printf("TIME = %2lf\n",t/CLOCKS_PER_SEC);
    
            t = clock ();
    res = test_strcpy(argv[1], argv[2], N, &strstr);
                t = (clock() - t);
    printf("\n RESULT:%s\n",res);
     printf("Std TIME = %2lf\n",t/CLOCKS_PER_SEC);
return 1; 
}

char *strstr_ (const char *string1, const char *string2)
{
    int i=0, j=0, k=0;
    while (string1[i]!='\0')
    {
        if (string1[i]==string2[j])
        {
            while ((string1[k]!='\0')&&(string1[k]==string2[j]))
            {
                k++;
                j++;
            }
        }
        if (string2[j] != '\0') i++;
        else break;
      j=0;
      k=i;
    }
    if (string1[i] == '\0') return 0;
    return (char*)(string1 + i);
}