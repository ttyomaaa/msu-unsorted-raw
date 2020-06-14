#include "test.h"
int test_strcpy(const char* string1, const char *string2, int n,  unsigned int (*p)(const char *, const char *))
{
    int i;
    int res=0;
    for (i=0;i<n;i++)
    {
        res=(*p)(string1, string2);
    }
    return res;
}
