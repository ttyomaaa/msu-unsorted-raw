#include <string.h>
int f_up(char *, char *);
int f_down(char *, char *);

int f_up(char *x, char *y)
{
 if (strcmp(x,y)>0) return 1;
 if (strcmp(x,y)<0) return -1;
 return 0;
}

int f_down(char *x, char *y)
{
 if (strcmp(x,y)<0) return 1;
 if (strcmp(x,y)>0) return -1;
 return 0;
}