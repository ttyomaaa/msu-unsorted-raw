#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int strlen_(const char *);
int main (int argc, char * argv[])
{
   // char *string;
    //int len_str,i;
    
    if ( !(argc == 2)  )
    {
        printf("USAGE %s \'STRING\'\n", argv[0]);
        return 1;
    } 
    //len_str=strlen_(argv[1]);
  /*  str1 = (char *) malloc ( len_str * sizeof(char) );
       if (!str1 )
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    } */
 /*free(str1);*/
  printf("COUNT RESULT=%d",strlen_(argv[1]));
return 1; 
}    

int strlen_(const char *string)
{
 int i=0;
while(1)
{   
   if(string[i]=='\0') break;
        i++;
}       
     return i;
}
