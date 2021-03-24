#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    int c;
    int j=0;
    fp = fopen("BookLibrary.txt", "r");

    int count=0;
    char line[100]={0};
    while (fgets(line,sizeof(line),fp))
    {
        count++;

    }
    printf("\n\n%d\n\n",count);
    fclose(fp);

    fp = fopen("BookLibrary.txt", "r");

while(j<count)
{
    for(int i=0; i<5; ++i)
    {
        while((c = fgetc(fp))!= '/')
    {
      printf("%c", c);}
    printf("\n");

    }

    ++j;

}


fclose(fp);

return 0;


}
