#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int strlen_(const char *);
char *strcpy_(char *, const char *);
int main (int argc, char * argv[])
{
    int len_str;
    char *string1;
     if ( !(argc == 2)  )
    {
        printf("USAGE %s \'STRING\'\n", argv[0]);
        return 1;
    } 

    len_str = strlen_(argv[1]);
    string1 = (char*) malloc ((len_str + 1)* sizeof(char));

    strcpy_(string1, argv[1]);
    printf("\n RESULT:%s",strcpy_(string1, argv[1]));
    free(string1);
return 1; 
}    

int strlen_(const char *string1)
{
 int i=0;
while(1)
{   
   if(string1[i]=='\0')break;
        i++;
}       
     return i;
}

char * strcpy_(char * string1, const char *string2)
{
 int i=0;
while(1)
{   
  string1[i]=string2[i];  
   if(string2[i]=='\0') break;
        i++;
}       
     return &string1[0];
}
