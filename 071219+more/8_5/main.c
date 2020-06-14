#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "test.h"
#define LEN 1234
#define N (1 << 28)
char func (const char a);
int strcasecmp_(const char *, const char *);
int main (int argc, char * argv[])
{
   //char *string1;
    int res=0;
    double t;
    if ( !(argc == 3)  )
    {
        printf("USAGE %s \'STRING1\' \'STRING2\'\n", argv[0]);
        return 1;
    }
        t = clock ();
    res = test_strcpy(argv[1], argv[2], N, &strcasecmp_);
                t = (clock() - t);
    printf("\n RESULT:%d\n",res);
     printf("TIME = %2lf\n",t/CLOCKS_PER_SEC);
    
            t = clock ();
    res = test_strcpy(argv[1], argv[2], N, &strcasecmp);
                t = (clock() - t);
    printf("\n RESULT:%d\n",res);
     printf("Std TIME = %2lf\n",t/CLOCKS_PER_SEC);
return 1; 
}

int strcasecmp_(const char *string1, const char *string2)
{   
 int i=0;
    while ((string1[i] != '\0') && (func(string1[i])==func(string2[i]))) i++;
    return (string1[i]-string2[i]);
}

char func (const char a)
{
    if((a>=65)&&(a<=90)) return (a+32);
    return a;
}

