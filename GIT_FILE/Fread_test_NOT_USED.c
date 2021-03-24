#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{  int size = 0;
   FILE *fp;
   char *ar;
   //char c[] = "This is runoob";
   //char buffer[200];


   fp = fopen("BookLibrary.txt", "r");

   //fwrite(c, strlen(c) + 1, 1, fp);


    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
	rewind(fp);
	ar = (char*)malloc(sizeof(char)*size);



    fread(ar, 1, size, fp);

    printf("%s",ar);
	fclose(fp);
	free(ar);

   return(0);
}
