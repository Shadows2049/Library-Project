#include <string.h>

typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies; //number of copies the library has
}Book;





typedef struct list_node

{

Book data ;

struct list_node *next ;

}list_single;


char *duplicate_s(const char *n){
 int length = strlen(n);
 char *newString = calloc(length+1,sizeof(char));
 strcpy(newString,n);
 return newString;
}

list_single *create_book(unsigned int id, const char *title, const char *author, unsigned int year, unsigned int copies){     //Add book(early verison)

list_single *node = NULL ;

node = calloc(1,sizeof(list_single));


if(node == NULL){

printf("calloc fail!\n");

}

node->data.id = id;

node->data.title = duplicate_s(title) ;

node->data.authors = duplicate_s(author) ;

node->data.year = year;

node->data.copies = copies;

node->next=NULL;



return node ;


}




int main(void)
{

    int i;                                 //Info of the newly added book
    unsigned int id;
    char title[200]="Rainbow Six";
    char author[200]="Tom";
    unsigned int year;
    unsigned int copies;

    /*i = sizeof(list_single);
    printf("%d",i);*/

    id = 1;
    year=1950;
    copies=3;

    list_single *head = create_book(id,title,author,year,copies);        //Add a book

    printf("book id is %d\n",head->data.id);
    printf("book title is %s\n", head->data.title);
    printf("book author is %s\n", head->data.authors);
    printf("book year is %d\n", head->data.year);
    printf("book copies is %d\n",head->data.copies);

    free(head->data.title);
    free(head->data.authors);
    free(head);






    return 0;





}


