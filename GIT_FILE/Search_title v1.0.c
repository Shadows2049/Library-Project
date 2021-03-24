#include <stdio.h>
#include <string.h>
int main(){

    char stitle[200];
    char title[200] = "i am batman";
    int titlelength = 0;
    int i=0;
    int indicator = 1;

    gets(stitle);

    titlelength = strlen(stitle);
    printf("\nlength of title is %d\n\n", titlelength);     //Search for book early version 


    for(i=0;i<titlelength;++i)
    {
        printf("%c\n",stitle[i]);
        if (stitle[i] == title[i])
            continue;
        else
            indicator = 0;
            break;

    }

    if(indicator==1)
        printf("found books\n");
    else
        printf("no found\n");



    /*char *p = strchr(str, c);
    if (p) {
        puts("Found");
    } else {
        puts("Not found");
    }*/
    return 0;
}
