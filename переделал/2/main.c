#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define LEN 1234
#define N (1 << 28)
int strlen_(const char *);
char* strcpy_(char *, const char *);
char* test_strcpy(char*, const char *, int, char* (*p)(char*, const char*));
int main (int argc, char * argv[])
{
    int len_str;
    char *string1;
    char *res=0;
       double t;
     if ( !(argc == 2)  )
    {
        printf("USAGE %s \'STRING\'\n", argv[0]);
        return 1;
    } 

    len_str = strlen_(argv[1]);

    string1 = (char*) malloc ((len_str + 1)* sizeof(char));
        t = clock ();
    res = test_strcpy(string1, argv[1], N, &strcpy_);
                t = (clock() - t);
    printf("\n RESULT:%s\n",res);
     printf("TIME = %2lf\n",t/CLOCKS_PER_SEC);
    
            t = clock ();
    res = test_strcpy(string1, argv[1], N, &strcpy);
                t = (clock() - t);
    printf("\n RESULT:%s\n",res);
     printf("Std TIME = %2lf\n",t/CLOCKS_PER_SEC);
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

char * strcpy_(char* string1, const char *string2)
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


char *test_strcpy(char* string1, const char *string2, int n, char* (*p)(char*, const char*))
{
    int i;
    char *res=0;
    for (i=0;i<n;i++)
    {
        res=(*p)(string1, string2);
    }
    return res;
}
