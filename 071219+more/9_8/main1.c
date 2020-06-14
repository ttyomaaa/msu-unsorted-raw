#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
#include "sort.h"
int func(char**, char**, int, int (*)(char*, char*));
int two (char**, char**, int, int, int, int (*)(char*, char*));
int main (int argc, char * argv[])
{
    char **a, **b;
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
   b = (char**) malloc (n * sizeof(char*));
    if (!b)
    {
        printf("NOT ENOUGH MEMORY\n");
        free(a);
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
            free(b);
            return 1;
        }      
    print_array(a, n);
    
    t = clock ();
    res = func(a, b, n, &f_up);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    
      printf("UPDATE UP: \n");
         print_array(a, n);  
      printf("ELAPSED = %lf\n",t);
    
    t = clock ();
    res = func(a, b, n, &f_down);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    
      printf("UPDATE DOWN: \n");
         print_array(a, n);   
      printf("ELAPSED = %lf\n",t);
      
    free(a);
    free(b);
}

int two(char **a, char **b, int left, int mid, int right, int (*p)(char *x, char *y))
{
int i=0,j=0,k=0;
  
    while (( (left+j)<mid)&&((mid+k)<right) )
    {
        if( (*p)(a[left+j],a[mid+k])<0 )
        {
            b[j+k]=a[left+j];
            j++;
        }    
        else
        {   b[j+k]=a[mid+k];
            k++;
        }        
    }
    while(left+j<mid) {b[j+k]=a[left+j];j++;}
    while (mid+k<right) {b[j+k]=a[mid+k];k++;}
    for(i=0;i<(j+k);i++) 
        a[left+i]=b[i];
return 0;
}            
int func(char **a,char **b, int n, int (*p)(char *x, char *y))
{
 int i,j,k;

    for (i=1;i<n;i*=2)
    {
        for (j=0;j<n-i;j=j+2*i)
        {
            if (j+2*i<n) k=j+2*i;
            else k=n;
            two(a,b,j,j+i,k,p);
        }
    }
 return 1;
}