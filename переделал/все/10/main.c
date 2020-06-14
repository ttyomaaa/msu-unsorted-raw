#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char *strstr_(const char *string1, const char *string2);
int main (int argc, char * argv[])
{
    char *res;
    
    if ( !(argc == 3)  )
    {
        printf("USAGE %s \'STRING1\' \'STRING2\'\n", argv[0]);
        return 1;
    }
    res=strstr_(argv[1], argv[2]);
    printf("\nRESULT=%s\n", res);
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
