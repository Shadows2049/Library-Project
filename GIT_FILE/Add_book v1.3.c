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

list_single *create_book(unsigned int id, const char *title, const char *author, unsigned int year, unsigned int copies,const list_single *head){

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

node->next=head;



return node ;


}




int main(void)
{
    list_single *head = NULL;
    int i;
    int j;
    unsigned int id;
    char title[200];
    char author[200];
    unsigned int year;
    unsigned int copies;

    
        for(j=0; j<3; ++j)              //Create multiple books
        {
            printf("Enter id\n");
            scanf("%d",&id);
            printf("Enter title\n");
            scanf("%s",&title);
            printf("Enter author\n");
            scanf("%s",&author);
            printf("Enter year\n");
            scanf("%d",&year);
            printf("Enter copies\n");
            scanf("%d",&copies);

            head = create_book(id,title,author,year,copies,head);

        }

        

    for (list_single *cur = head; cur != NULL; cur = cur->next)              //Check
    {       printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year,cur->data.copies);
            
            free(head->data.title);
            free(head->data.authors);
    }


    free(head);






    return 0;





}
