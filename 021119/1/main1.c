#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
int func (double[], int);
int main (int argc, char * argv[])
{
    double * a;
    int n, res;
    char * name = NULL;
    clock_t t;
    
    if ( !( ((argc == 2) || (argc == 3)) && sscanf(argv[1], "%d", &n)) )
    {
        printf("USAGE %s n [file]\n", argv[0]);
        return 1;
    }
    
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
    res = func(a, n);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    printf("ELAPSED = %lf\n", (double) t);
    free(a);
    return 0;
}

int func (double a[] , int n)
{
    double eps = 1e-7;
    int i;
    for (i=0;i<n/2; i++)
    {
        if (fabs(a[i] - a[n-1 - i])>eps)
        {
            return 0;
        }
    }
    
    return 1;
}