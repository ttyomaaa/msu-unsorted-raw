#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
int func (double[], int, double);
int main (int argc, char * argv[])
{
double *a, x;
int n, res;
char * name = NULL;
clock_t t;
    
 if ( !( ((argc == 2) || (argc == 3)) && sscanf(argv[1], "%d", &n)) )
 {
        printf("USAGE %s n [file]\n", argv[0]);
        return 1;
 }
printf("INPUT x:");
if(scanf("%lf", &x) != 1) {printf("CAN'T READ x\n"); return 2;}

    a=(double*)malloc(n * sizeof(double));
    if (!a)
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    if (argc == 3)
    {
        name = argv[2];
    }
    
if (name)
  {
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
  }
else
 {
        init_array(a, n);
        //print_array(a, n);
 }    
    
    print_array(a, n);
    t = clock ();
    res = func(a, n, x);
       printf("UPDATE: \n");
       print_array(a, res);
    printf("DONE.\nRETURNED LENGHT: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    printf("ELAPSED = %lf\n", (double) t);
    free(a);
    return 0;
}

int func (double a[] , int n, double x)
{
int count=0, i, q=0;
for (i=0;i<n;i++)
 {
      if (fabs(a[i]<x)) count++;
      else {a[q]=a[i]; q++;}
 }
return (n-count);
} 