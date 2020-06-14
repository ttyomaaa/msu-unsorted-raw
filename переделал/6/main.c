#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "test.h"
#define LEN 1234
#define N (1 << 28)
char *strchr_(const char *string, int ch);
int main (int argc, char * argv[])
{
    int ch;
    double t;
    char* res;
     if ( !(argc == 3)  )
    {
        printf("USAGE %s \'STRING\' SYMBOL \n", argv[0]);
        return 1;
    }
   ch=*argv[2];
        t = clock ();
    res = test_6(argv[1], ch, N, &strchr_);
                t = (clock() - t);
    printf("\n RESULT:%s\n",res);
     printf("TIME = %2lf\n",t/CLOCKS_PER_SEC);
    
            t = clock ();
    res = test_6(argv[1],ch, N, &strchr);
                t = (clock() - t);
    printf("\n RESULT:%s\n",res);
     printf("Std TIME = %2lf\n",t/CLOCKS_PER_SEC);
return 1; 
}    

char *strchr_(const char *string, int ch)
{
    while(*string!='\0')
    {
        if(*string == ch) return (char*) string;
        string++;
    }
  return (char*) string;
}
