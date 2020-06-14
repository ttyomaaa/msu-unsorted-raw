#include "test.h"
char* test_strcpy(const char* string1, const char *string2, int n, char*(*p)(const char *, const char *))
{
    int i;
    char* res=0;
    for (i=0;i<n;i++)
    {
        res=(*p)(string1, string2);
    }
    return res;
}
