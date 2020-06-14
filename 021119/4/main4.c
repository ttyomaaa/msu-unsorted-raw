#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
int func (double[], int, double[], int);
int main (int argc, char * argv[])
{
double *a, *b;
int n, m, res;
char * name_a = NULL, * name_b = NULL;
clock_t t;
    
  if (!((argc == 5) && sscanf(argv[1], "%d", &n) && sscanf(argv[3], "%d", &m)))
    {
     printf("USAGE %s n [file a] m [file b]\n", argv[0]);
     return 1;
    }
    
a = (double *) malloc (n * sizeof(double));
    if (!a)
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    
b = (double *) malloc (m * sizeof(double));
    if (!a)
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    name_a = argv[2];
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
            return 1;
        }
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
            return 1;
        }
}
  printf("ARRAY a[n]:\n");
  print_array(a, n);
  printf("ARRAY b[m]:\n");
  print_array(b, m);
    t = clock ();
    res = func(a, n, b, m);
       printf("UPDATE: \n");
       print_array(a, n);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    printf("ELAPSED = %lf\n", (double) t);
    free(a);
    free(b);
    return 0;
}

int func (double a[] , int n, double b[], int m)
{
double eps = 1e-7;
int i, j;
for (i=0;i<n;i++)
{ 
    for (j=0;j<m;j++)
    { 
        if (fabs(a[i]-b[j]<eps)) {a[i]=0; break;}
    }
 }
return 1;
} 