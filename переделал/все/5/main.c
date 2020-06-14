#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char func (const char a);
int strcmp_(const char *, const char *);
int main (int argc, char * argv[])
{
   //char *string1;
    int res;
    
    if ( !(argc == 3)  )
    {
        printf("USAGE %s \'STRING1\' \'STRING2\'\n", argv[0]);
        return 1;
    }
    res=strcmp_(argv[1], argv[2]);
  printf("\nRESULT=%d\n",res);
return 1; 
}

int strcmp_(const char *string1, const char *string2)
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

