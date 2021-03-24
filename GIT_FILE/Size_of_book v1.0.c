#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies; //number of copies the library has
}Book;

int main(void)      //check the size of struct Book(and each element in Book)

{

int size = sizeof(Book);
printf("%d\n",size);

Book book1;
book1.id = 1000000;
size = sizeof(book1);
printf("%d\n",size);


Book book[100];
size = sizeof(book);
printf("%d\n",size);

return 0 ;

}

