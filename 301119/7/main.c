#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char *strchr_(const char *string, int ch);
int main (int argc, char * argv[])
{
    int ch;
     if ( !(argc == 3)  )
    {
        printf("USAGE %s \'STRING\' SYMBOL \n", argv[0]);
        return 1;
    }
    ch=*argv[2];
    strchr_(argv[1], ch);
    printf("\n RESULT:%s",strchr_(argv[1], ch));
return 1; 
}    

char *strchr_(const char *string, int ch)
{
  while(*string) {string++;}
    string--;
      while(*string)
       {
         if(*string == ch) return (char*)string;
         string--;
       }
   return "0";
}
