#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arr.h"
int func (double[], int, char*);
int main (int argc, char * argv[])
{
    double * a;
    int n, res;
    char * name = NULL, * name_x = NULL;
    clock_t t;
    
    if ( !((argc == 4) && sscanf(argv[1], "%d", &n)) )
    {
        printf("USAGE %s n [file] [file x]\n", argv[0]);
        return 1;
    }
    
    a = (double *) malloc (n * sizeof(double));
    
    if (!a)
    {
        printf("NOT ENOUGH MEMORY\n");
        return 1;
    }
    name = argv[2];
    name_x = argv[3];  
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
    res = func(a, n, name_x);
        if(res < 0)
    {
        switch(res)
        {
                case -1:
                    printf("CAN'T OPEN FILE %s\n", name_x);
                    break;
                case -2:
                    printf("CANNOT READ FILE %s\n", name_x);
                    break;
                case -4:
                    printf("FILE %s IS EMPTY\n", name_x);
                    break;
                default:
                    printf("UNKNOWN ERROR %s\n", name_x);
                    break;
        }
        free(a);
        return 1;
    }
    printf("DONE.\nRETURNED CODE: %d\n", res);
    t = (clock() - t)/CLOCKS_PER_SEC;
    printf("ELAPSED = %lf\n", (double) t);
    free(a);
    return 0;
}

int func (double a[] , int n, char *name_x)
{
    FILE*fp;
    if(!(fp = fopen(name_x, "r")))
    {
        return -1;
    }
double x,eps = 1e-7;
int count=0, i=0, ind=1;
while (fscanf(fp, "%lf", &x)==1)
{ 
  ind=0;
  if(fabs(a[i]-x)<eps)
    {i++;
      if(i==n) {i=0;count++;}
    }
   else { i=0;
      if (fabs(a[i]-x)<eps) i++;}  
}  
if (!feof(fp))
    {
        fclose(fp);
        return -2;
    }
fclose(fp);
if (ind==1) return -4;
return count;
}