#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int strlen_(const char *);
char *strcpy_(char *, const char *);
char *strcat_(char *, const char *);
int main (int argc, char * argv[])
{
   char *string1;
    int len_str1,len_str2;
    
    if ( !(argc == 3)  )
    {
        printf("USAGE %s \'STRING1\' \'STRING2\'\n", argv[0]);
        return 1;
    }
    
    len_str1=strlen_(argv[1]);
    len_str2=strlen_(argv[2]);
    string1 = (char *) malloc ( len_str1+len_str2 );
       if (!string1 )
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    } 

    strcpy_(string1,argv[1]);
    strcat_(string1,argv[2]);
  printf("\nRESULT=%s",string1);
 free(string1);
return 1; 
}    

int strlen_(const char *string1)
{
 int i=0;
while(1)
{   
   if(string1[i]=='\0') break;
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
   if(string1[i]=='\0') break;
        i++;
}       
     return &string1[0];
}
char * strcat_(char * string1, const char *string2)
{
 int i=0,j=0;
    while(string1[i]!='\0') i++;
    while(string2[j]!='\0') {string1[i]=string2[j];i++;j++;}
    string1[i]='\0';
    
      return &string1[0];
}
