#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
#include "sort.h"
int func(char **, int, int (*)(char *, char *));
int main(int argc, char * argv[])
{
    char **a;
    int n, res;
    const char *name = NULL;
    double t;
    
    if ( !( (argc == 3) && (sscanf(argv[1], "%d", &n)==1)) )
    {
        printf("USAGE %s n [file]\n", argv[0]);
        return 1;
    }
    
    a = (char**) malloc (n * sizeof(char*));
    
    if (!a)
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    
    name = argv[2];
    res = read_array (name, a, n);
        if (res < 0)
        {
            switch(res)
            {
                case -1 :
                    printf("CAN'T OPEN FILE %s\n", name);
                    break;
                case -2 :
                   printf("CANNOT READ FILE %s\n", name);
                    break;
                default:
                    printf("UNKNOWN ERROR %s\n", name);
                    break;
            }
            free(a);
            return 1;
        } 
       
    print_array(a, n);
    
    t = clock ();
    res = func(a, n, &f_up);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    
      printf("UPDATE UP: \n");
         print_array(a, n);  
      printf("ELAPSED = %lf\n",t);
    
    t = clock ();
    res = func(a, n, &f_down);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    
      printf("UPDATE DOWN: \n");
         print_array(a, n);   
      printf("ELAPSED = %lf\n",t);
      
    free(a);
   return 0;
}

int func(char **a, int n, int (*p)(char *x, char *y))
{
    int i=0, j=0, k;
    char *min;
    for (i=0;i<n;i++) 
     {
      min=a[i];
        for (j=i;j<n;j++) 
         {
            if ((*p)(a[j],min)<=0) {min=a[j];k=j;} 
         }   
      a[k]=a[i];
      a[i]=min;
     }
     return 1;
}