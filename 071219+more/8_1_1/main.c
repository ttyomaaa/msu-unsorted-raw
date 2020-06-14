#include <stdio.h>
#include <stdlib.h>
#define LEN_STR_ 1000
int strlen_(const char *);
int main (int argc, char * argv[])
{
    char *str1;
    str1 = (char *) malloc ( LEN_STR_ * sizeof(char) );
    
       if (!str1 )
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
 
    printf("\n Get string:");
    if (gets(str1)==0)
    {
     printf("NOT ENOUGH MEMORY\n");
     free(str1);
     return 1;
}
 printf("\n%d\n",('Б'-'б'));   
  printf("Count of symbol=%d",strlen_(str1));
 free(str1);
return 1; 
}    
// вычисление длину
int strlen_(const char *str1)
{
 int i=0;
while(1)
{   
   if(str1[i]==(char)0)break;
        i++;
}       
     return i;
}
