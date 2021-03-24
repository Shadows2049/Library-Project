#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char title1[100];
		//char *authors; //comma separated list of authors
		//unsigned int year; // year of publication
		//unsigned int copies; //number of copies the library has
}Book;

char *duplicate_s(const char *n){              //allocate memory for char title & author
 int length = strlen(n);
 char *newString = calloc(length+1,sizeof(char));
 strcpy(newString,n);
 return newString;
}

int main(void)

{

int size = sizeof(Book);
printf("%d\n",size);

Book book[100];
size = sizeof(book);
printf("%d\n",size);

char *copy = duplicate_s("Rainbow six");    //test duplicate_s
printf("%s\n", copy);
book[0].title = copy;


free(copy);
printf("%s\n", book[0].title);


return 0 ;

}

