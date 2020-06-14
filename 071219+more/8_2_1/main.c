#include <stdio.h>
#include <stdlib.h>
#define LEN_STR_ 1000
int strlen_(const char *);
char *strcpy_(char *, const char *);
int main (int argc, char * argv[])
{
    int len_str;
    char *str1, *str2;
    str1 = (char *) malloc ( LEN_STR_  );
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
len_str=strlen_(str1);
if (len_str<=0){printf("\nEmpty string!");free(str1); return 1;}
    str2 = (char *) malloc ( len_str );
       if (!str2 )
    {
        printf("NOT ENOUGH MEMORY\n");
        free(str1);
        return 1;
    }
    strcpy_(str2, str1);
    printf("\n Copy string:%s",str2);
    free(str2);
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
// Копирование строки
char * strcpy_(char * str2, const char *str1)
{
 int i=0;
while(1)
{   
  str2[i]=str1[i];  
   if(str1[i]==(char)0)break;
        i++;
}       
     return &str2[0];
}
