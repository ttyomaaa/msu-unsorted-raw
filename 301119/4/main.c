#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
  printf("\nRESULT=%d",res);
return 1; 
}    
int strcmp_(const char *string1, const char *string2)
{
    int i;
    for(i=0;*string1==*string2;i++)
    {
        string1++;
        string2++;
    }
    return (string1[i]-string2[i]);
}