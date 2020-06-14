#include <stdio.h>
#include <stdlib.h>
#define LEN 1234
int read_array(const char *, char **, int);
void print_array(char **, int);
void free_array(char **, int);

int read_array(const char *name, char **a, int n)
{
    FILE *fp;
    int i, j, k;
    char buf[LEN];
    if(!(fp = fopen(name, "r")))
        return -1;
    for(i=0; i<n; i++)
    {
        if (!fgets(buf,LEN,fp))
        {
            fclose(fp);
            return -2;
        }
       	for(j=0; buf[j]; j++)
	{
	    if(buf[j]=='\n')
		{
		    buf[j]='\0';
                    break;
		}
	}
        
        a[i]=(char*)malloc(j+1);
        
        if (!a[i])
        {
            fclose(fp);
            return -3;
        }
         for (k=0;k<=j;k++)
             a[i][k]=buf[k];
    }
    fclose(fp);
    return 0;
}

void print_array(char **a, int n)
{
    int i;
    
 //   if(n>20) n=20;
    for (i=0; i<n; i++)
    {
        printf("%s\n", a[i]);
    }
}

void free_array(char **a, int n)
{
    int i;

    for(i=0; i<n; i++) free(a[i]);

    free(a);
}