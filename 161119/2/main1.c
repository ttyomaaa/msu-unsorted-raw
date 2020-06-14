#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
int func (double[], int, double[], int, double[]);
int main (int argc, char * argv[])
{
double *a, *b, *c;
int n, m, res;
char * name_a = NULL, * name_b = NULL;
clock_t t;
    
  if (!( ((argc == 5)||(argc==3)) && sscanf(argv[1], "%d", &n) && sscanf(argv[2], "%d", &m)))
    {
     printf("USAGE %s n m [file a] [file b]\n", argv[0]);
     return 1;
    }
    
a = (double *) malloc (n * sizeof(double));
    if (!a)
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    
b = (double *) malloc (m * sizeof(double));
    if (!b)
    {
        printf("NOT ENOUGH MEMORY\n");
        free(a);
        return 1;
    }

c = (double *) malloc ((m+n) * sizeof(double));
    if (!c)
    {
        printf("NOT ENOUGH MEMORY\n");
        free(a);
        free(b);
        return 1;
    }
    name_a = argv[3];
    name_b = argv[4]; 


if (name_a)
{
    res = read_array (name_a, a, n);
    if (res < 0)
        {
            switch(res)
            {
                case -1 :
                    printf("CAN'T OPEN FILE %s\n", name_a);
                    break;
                case -2 :
                    printf("CANNOT READ FILE %s\n", name_a);
                    break;
                default:
                    printf("UNKNOWN ERROR %s\n", name_a);
                    break;
            }
            free(a);
            free(b);
            free(c);
            return 1;
        }
}
else
 {
     init_array(a, n);
 }
if (name_b)
{
    res = read_array (name_b, b, m);
    if (res < 0)
        {
            switch(res)
            {
                case -1 :
                    printf("CAN'T OPEN FILE %s\n", name_b);
                    break;
                case -2 :
                    printf("CANNOT READ FILE %s\n", name_b);
                    break;
                default:
                    printf("UNKNOWN ERROR %s\n", name_b);
                    break;
            }
            free(a);
            free(b);
            free(c);
            return 1;
        }
}
else
 {
     init_array(b, m);
 }
  printf("ARRAY a[n]:\n");
  print_array(a, n);
  printf("ARRAY b[m]:\n");
  print_array(b, m);
    t = clock ();
    res = func(a, n, b, m, c);
       printf("ARRAY C: \n");
       print_array(c, (n+m));
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    printf("ELAPSED = %lf\n", (double) t);
    free(a);
    free(b);
    return 0;
}

int func (double a[] , int n, double b[], int m, double c[])
{
//double eps = 1e-7;
int i=0, j=0, k=0;
while((i<n) && (j<m))
    {
      if (a[i]<b[j]) 
       { c[k]=a[i] ; i++ ; k++ ; }
      else 
       { c[k]=b[j]; j++ ; k++ ; }
    }    
while(i < n)
    { c[k]=a[i] ; i++ ;k++ ; }
while(j < m)
    { c[k]=b[j] ; j++ ; k++ ; }
    return 1;
} 