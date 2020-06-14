#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
int func (double[], int, double[]);
int main (int argc, char * argv[])
{
    double *a, *b;
    int n, res;
    char * name = NULL;
    clock_t t;
    
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
        print_array(a, n);
    }    
    
    print_array(a, n);
    t = clock ();
    res = func(a, n, b);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    
       printf("UPDATE: \n");
       print_array(a, n);
    printf("ELAPSED = %lf\n", (double) t);
    free(a);
    return 0;
}

int func (double a[] , int n, double b[])
{
  int i, j, k, t, s, Fin1, Fin2;
  k = 1;
  while (k < n){
    t = 0;
    s = 0;
    while (t+k < n)
    {
      Fin1 = t+k;
      if(t+2*k < n )
        Fin2 = t+2*k;
      else
        Fin2=n;
      i = t; 
      j = Fin1;
      while ( i < Fin1 && j < Fin2 )
      {
           if (a[i] < a[j]) {
                b[s] = a[i];
                i++;
            }
        else
         {
          b[s] = a[j];
          j++;
         }
        s++;
      }
      while (i < Fin1)
       {
        b[s] = a[i];
        i++; s++;
       }

      while ( j < Fin2)
       {
        b[s] = a[j];    j++; s++;
        }
      t = Fin2;
    }
    k *= 2;
    for (s = 0; s < t; s++)
      a[s] = b[s];
  }
 return 1; 
} 