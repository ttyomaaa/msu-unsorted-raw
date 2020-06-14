#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int read_array (char *, double[], int);
void init_array (double*, int);
void print_array (double*, int);

int read_array(char *name, double *a, int n)
{
    FILE *fp;
    int i;   
    if( !(fp = fopen(name, "r")) )
        return -1;
    for(i=0; i < n; i++)
    {
        if (fscanf(fp, "%lf", a+i) != 1)
        {
            fclose(fp);
            return -2;
        }
    }
    
    fclose(fp);
    return 0;
}

void init_array (double *a, int n)
{
    srand(time(NULL));
    int i;
    for (i=0;i<n;i++) a[i]=//5 + 
            rand() 
            //%7
            ;
    //{
      //  a[i] = i;
    //}
    
}

void print_array (double *a, int n)
{
    int i;
    
    for (i=0; i < n; i++)
    {
        printf("%lf\n", a[i]);
    }
}
