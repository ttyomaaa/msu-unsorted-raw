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
    
       printf("UPDATE: \n");
       print_array(a, n);
    printf("ELAPSED = %lf\n", (double) t);
    free(a);
    return 0;
}

int func(double a[],int n)
{
    int i,j,k,p,first=0,last=n-1;
    double tmp,x;
    p=(first+last)/2;x=a[p];
    i=first;j=last;
    do{
        while(a[i]<x)i++;
        while(a[j]>x)j--;
        if(i<=j)
         {  
           // if(a[i]>a[j])
                {tmp=a[i];a[i]=a[j];a[j]=tmp;}
            i++;j--;
         }
    }while(i<=j);
  //  from3task(x,a,n);
}