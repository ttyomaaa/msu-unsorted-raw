#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int strsnp_(const char* , const char*);
int main (int argc, char * argv[])
{
    int res;
    
    if ( !(argc == 3)  )
    {
        printf("USAGE %s \'STRING1\' \'STRING2\'\n", argv[0]);
        return 1;
    }
    res=strsnp_(argv[1], argv[2]);
    printf("\nRESULT=%d\n", res);
return 1; 
}    

int strsnp_(const char *string1, const char *string2)
{
    int i=0, j=0, k=0;
    while (string1[i]!='\0')
    {
        while (string2[j]!='\0')
        {
            if (string2[j]!=string1[i]) k++;
            j++;
        }
        if (k==j) return i;
        j=0;
        k=0;
        i++;
    }
    return i;
}
