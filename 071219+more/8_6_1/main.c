
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *strchr_(const char *string, int ch);

char *strchr_(const char *string, int ch){
    int i = 0;
    while(*string){
        if(*string == ch){
            
            return (char*) string;
        }
        string++;
    }
    return "0";
}

 int main(int argc, char *argv[]){
    clock_t t;
    int ch;
    char* res;
    
    if(!(argc == 3)){
        printf("Usage: %s n file\n", argv[0]);
        return 1;
    }
    ch = *argv[2];
    t = clock();
    res = strchr_(argv[1], ch);
    printf("%s\n", res);
    t = clock() - t;
   
    return 0;
}