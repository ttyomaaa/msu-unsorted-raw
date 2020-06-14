#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
int func (double, double[], int);
int main (int argc, char * argv[])
{
    double *a;
    double x;
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
    a = (double *) malloc (n * sizeof(double));
    
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
        print_array(a, n);
    }    
    
    print_array(a, n);
    t = clock ();
    res = func(x, a, n);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
          printf("UPDATE: \n");
       print_array(a, n);
    printf("ELAPSED = %lf\n", (double) t);
    free(a);
    return 0;
}

int func (double x, double a[] , int n)
{
    int i=0, j=0;
    double eps=1e-7, m;
    for (i=0;i<n;i++)
    {
        if ((a[i]>x)||(fabs(a[i]-x)<eps)) {break;}
    }
    for (j=n-1;j>0;j--)
    {
        if (a[j]<x) {break;}
    }
    while (i<=j) {m=a[i]; a[i]=a[j]; a[j]=m; i++;j--;}

    printf("\n %d %d \n", i, j);
    i++;
     return i;
}