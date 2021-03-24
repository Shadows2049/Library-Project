#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   unsigned int year;
    unsigned int copies;
    unsigned int id;
    char title[200];
    char author[200];


    FILE *fp;
    FILE *ld;
    int c;
    int j=0;


    fp = fopen("BookLibrary.txt", "r");

    int count=0;
    char line[200]={0};

    while (fgets(line,sizeof(line),fp))
    {
        count++;
        //printf("%s\n",line);
        sscanf(line, "%d/%[^/]/%[^/]/%d/%d", &id,title,author,&year,&copies);


        printf("id is %d\n",id);
        printf("title is %s\n", title);
        printf("author is %s\n", author);
        printf("year is %d\n",year);
        printf("copies is %d\n",copies);
        printf("\n");




        //fputs("awd22awdawd\n", fp);
        //fputs("2222\n", fp);
        ld = fopen("fputs.txt", "a");

        fprintf(ld, "%d/%s/%s/%d/%d\n", id, title, author,year,copies);

        fclose(ld);


    }







    fclose(fp);








return 0;


}
