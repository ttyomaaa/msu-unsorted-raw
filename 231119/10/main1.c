#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
#include "sort.h"
int heap (double[], int , int,  int (*)(double, double));
int func (double[], int,  int (*p)(double, double));
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
    //    print_array(a, n);
    }    
    
       if (n<=20)
       print_array(a, n);
       else
       print_array(a, 20);
    t = clock ();
    res = func(a, n, &f_up);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
       printf("UPDATE UP: \n");
       if (n<=20)
       print_array(a, n);
       else
       print_array(a, 20);
    printf("ELAPSED = %lf\n", (double) t);
        t = clock ();
    res = func(a, n, &f_down);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
       printf("UPDATE DOWN: \n");
       if (n<=20)
       print_array(a, n);
       else
       print_array(a, 20);
    printf("ELAPSED = %lf\n", (double) t);
    
    free(a);
    return 0;
}

int heap (double a[], int n, int i, int (*p)(double x, double y))
{ 
    int  parent=i, ch1=2*i+1, ch2=2*i+2;
    double tmp;
    if ( (ch1<n)&&((*p)(a[ch1],a[parent])>0) ) parent=ch1;
    if ( (ch2<n)&&((*p)(a[ch2],a[parent])>0) ) parent=ch2;
    if (parent!=i)
      {
        tmp=a[i]; a[i]=a[parent]; a[parent]=tmp;
        heap (a,n,parent,p);
      }
return 1;
}

int func (double a[] , int n, int (*p)(double x, double y))
{
    int i=0;
    double m;
    for (i=n/2-1;i>=0;i--)
     {
       heap (a,n,i,p);
     }
    for (i=n-1;i>=0;i--)
     {
       m=a[0]; a[0]=a[i]; a[i]=m;
       heap (a,i,0,p);
     }
return 1;
}