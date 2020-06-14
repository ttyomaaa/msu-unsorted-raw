#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
#include "sort.h"
int func(char **, char **, int, int (*) (char *, char *));
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
         
int func(char **a, char **b, int n, int (*p) (char *x, char *y))
{
 int i, j=0, k, m, step=1, left=0, mid, right;
 char **x=a, **tmp;
    while (step<n)
    {
      mid=left+step;
      right=left+step*2;
        while (left<n)
        {
           if (mid>n) mid=n-1;
           if (right>n) right=n-1;
           k=left;
           m=mid;
             for (j=0;(k<mid)&&(m<right);j++)
             {
                 if ((*p)(a[k],a[m])<0) {b[j]=a[k];k++;}
                 else {b[j]=a[m];m++;}
             }
             while (k<mid)
             {
                 b[j]=a[k];
                 j++;
                 k++;
             }
             while (m<right)
             {
                 b[j]=a[m];
                 j++;
                 m++;
             }
           left = left+step*2;
           mid = mid+step*2;
           right = right+step*2;
        }
      tmp=a;
      a=b;
      b=tmp;
      step = step*2;
   }
  if (x!=a)
  for (i=0; i<n; i++) a[i]=b[i];

return 1;
}