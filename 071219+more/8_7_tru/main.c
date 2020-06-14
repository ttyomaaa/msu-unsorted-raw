#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "test.h"
#define LEN 1234
#define N (1 << 28)
char *strchr_(const char *, int);
int main (int argc, char * argv[])
{
   //char *string1;
    char* res=0;
    double t;
    int ch=0;
    if ( !(argc == 3)  )
    {
        printf("USAGE %s \'STRING1\' \'STRING2\'\n", argv[0]);
        return 1;
    }
        ch=*argv[2];
        t = clock ();
    res = test_strcpy(argv[1], ch, N, &strchr_);
                t = (clock() - t);
                if (res==0)  printf("\nNO SUCH SUBSTRING\n");
                else printf("\n RESULT:%s\n",res)
    printf("\n RESULT:%s\n",res);
    printf("TIME = %2lf\n",t/CLOCKS_PER_SEC);
    
            t = clock ();
    res = test_strcpy(argv[1], ch, N, &strchr);
                t = (clock() - t);
    printf("\n RESULT:%s\n",res);
     printf("Std TIME = %2lf\n",t/CLOCKS_PER_SEC);
return 1; 
}

char *strchr_(const char *string, int ch)
{
  while(*string) {string++;}
    if (ch==0) return (char*)string;
      string--;
      while(*string)
       {
         if(*string == ch) return (char*)string;
         string--;
       }
   return 0;
}