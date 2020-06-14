#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
int func (double[], int, int);
int main (int argc, char * argv[])
{
double * a;
int n, k, res;
char * name = NULL;
clock_t t;
    
 if ( !( ((argc == 2) || (argc == 3)) && sscanf(argv[1], "%d", &n)) )
 {
        printf("USAGE %s n [file]\n", argv[0]);
        return 1;
 }
printf("INPUT k:\n");
if(scanf("%d", &k) != 1) {printf("CAN'T READ k\n"); return 2;}
    
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
    
    print_array(a, n);
    t = clock ();
    res = func(a, n, k);
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
       printf("UPDATE: \n");
       print_array(a, n);
    printf("ELAPSED = %lf\n", (double) t);
    free(a);
    return 0;
}

int func (double a[] , int n, int k)
{
  int i=0, m;
  double prev;
  k=k%n;
  m=n%k;
  while (m!=0)
  {
   if ((k<=0)&&(m!=0)) 
   {k=-k;
   printf("left=%d,%d\n",k,m);
    //двигаем влево, но вправо
   for (i=n-1;i>=m;i--)
     {prev=a[i];
      a[i]=a[i-m];
      a[i-m]=prev;}
   m=n%m;
    }
    if ((k>=0)&&(m!=0)) 
    {
    //двигаем вправо, но влево
   for (i=0;i<m;i++)
     {prev=a[i];
      a[i]=a[i+m];
      a[i+m]=prev;}
    }
      k=-k;
   m=n%m;
  }
  k=fabs(k);
  if ((k>=0)&&(m==0)) 
  {
    //двигаем вправо, все ок
   for (i=n-1;i>=k;i--)
     {prev=a[i];
      a[i]=a[i-k];
      a[i-k]=prev;}
  }
    if ((k>=0)&&(m!=0)) 
    {
    //двигаем влево, все ок
   for (i=0;i<k;i++)
     {prev=a[i];
      a[i]=a[i+k];
      a[i+k]=prev;}
    }
  return 1;
}