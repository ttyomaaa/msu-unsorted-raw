#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
#include "sort.h"
int func(double [], double [], int, int (*)(double, double));
int two (double[], double[], int, int, int, int (*)(double, double));
void swap(double **a, double **b);
int main (int argc, char * argv[])
{
    double *a, *b;
    int n, res;
    char * name = NULL;
    double t;
    
    if ( !( ((argc == 2) || (argc == 3)) && sscanf(argv[1], "%d", &n)) )
    {
        printf("USAGE %s n [file]\n", argv[0]);
        return 1;
    }
    
    a = (double *) malloc (n * sizeof(double));
    b = (double *) malloc (n * sizeof(double));
    if (!a)
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    if (!b)
    {
        printf("NOT ENOUGH MEMORY\n");
        free(a);
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
            free(b);
            return 1;
        }
    }
    else
    {
        init_array(a, n);
       // print_array(a, n);
    }    
    
       if (n<=20)
       print_array(a, n);
       else
       print_array(a, 20);
    t = clock ();
    res = func(a, b, n, &f_up);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    
       printf("UPDATE UP: \n");
       if (n<=20)
       print_array(a, n);
       else
       print_array(a, 20);
    printf("ELAPSED = %lf\n", (double) t);
     t = clock ();
    res = func(a, b, n, &f_down);
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

int two(double a[], double b[], int left, int mid, int right, int (*p)(double x, double y))
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

return 0;
}            
int func(double a[], double b[], int n, int (*p)(double x,double y))
{
 int i,j,k;
 double *c;

    for (i=1;i<n;i*=2)
    {
        for (j=0;j<n-i;j=j+2*i)
        {
            if (j+2*i<n) k=j+2*i;
            else k=n;
            two(a,b,j,j+i,k,p);
        }
                    swap(&a, &b);
    }
 return 1;
}
void swap(double **a, double **b)
{
	double *buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}