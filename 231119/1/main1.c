#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
#include "sort.h"

int func (double, double[], int, int (*)(double, double));
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
    res = func(x, a, n, &f_up);
    if (res>=0) printf("DONE.\nRETURNED CODE: %d\n", res);
    if (res==-4) printf("NO LOWER ELEMENT FOR X\nRETURNED CODE: %d\n", res);
    if (res==-5) printf("NO UPPER ELEMENT FOR X\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    printf("ELAPSED = %lf\n", (double) t);
    free(a);
    return 0;
}

int func (double x, double a[] , int n, int (*p)(double x, double y))
{
    int s=0, count1=2, up=n, down=0;
    double s0;
    if ((*p)(x,a[0])<0) return -4;
    if ((*p)(x,a[n-1])>0) return -5;
    while (up!=down)
    {
        count1++;
    s0=(up+down)/2;
    s=(int)s0;
    if( (*p)(x,a[s])>0 )  down=s+1;
    else up=s;
    }      
     return up;
}