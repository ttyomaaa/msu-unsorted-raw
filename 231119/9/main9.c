#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
#include "sort.h"
int func (double[], int, int,int (*)(double,double));
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
        //print_array(a, n);
    }    
    
       if (n<=20)
       print_array(a, n);
       else
       print_array(a, 20); 
    t = clock ();
    res = func(a, 0, n, &f_up);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    
    printf("UPDATE UP: \n");
       if (n<=20)
       print_array(a, n);
       else
       print_array(a, 20);   
    printf("ELAPSED = %lf\n", (double) t);
    
     /*  t = clock ();
    res = func(a, 0, n, &f_down);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    
    printf("UPDATE DOWN: \n");
       if (n<=20)
       print_array(a, n);
       else
       print_array(a, 20);   
    printf("ELAPSED = %lf\n", (double) t); */
    
    free(a);
    return 0;
}

int func (double a[] , int first, int last, int (*p)(double x, double y))
{
int i, j;
double tmp, x;
while(first<last)
    
{
	i=first; j=last-1;
	x=a[(int)((first+last)/2)]; 
      while (i<=j)
      { 
        while (  (*p)(a[i],x)<0) i++;
        while ( (*p)(a[j],x)>0) j--; 
        if (i<=j) {tmp = a[i]; a[i] = a[j]; a[j] = tmp;i++;j--;}
             
      } 
      if(last-first<=2)   
          break;
     if ( (i-first)<(last-i) ) 
	{
	if (first<i ) 
	  func(a, first,i, p);
        first=i;
	}
     else
	{
	if (i<last-1 ) 
	  func(a, i,last, p);  
        last=i; 
        }
	};
	
     return 0;
}
