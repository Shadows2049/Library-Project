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

int main()
{   int count=0;
    char line[200]={0};
    FILE *fp;
    FILE *ld;
    int c;
    int j=0;

    unsigned int year;
    unsigned int copies;
    unsigned int id;
    char title[200];
    char author[200];
    char tt[200];

    list_single *head = NULL;

    fp = fopen("tt.txt", "r");

    while (fgets(line,sizeof(line),fp))
    {
        count++;
        sscanf(line, "%d/%[^/]/%[^/]/%d/%d", &id,title,author,&year,&copies);   //Use sscanf, scan file by lines and create information in memory

        head = create_book(id,title,author,year,copies,head);

        printf("id is %d\n",id);
        printf("title is %s\n", title);
        printf("author is %s\n", author);
        printf("year is %d\n",year);
        printf("copies is %d\n",copies);
        printf("\n");


    }


    printf("ADD a book\n");

    printf("Enter book title: ");
    gets(title);
    printf("\n");

    printf("Enter book author: ");
    gets(author);
    printf("\n");

    printf("Enter book id: ");
    scanf("%d",&id);

    printf("Enter book year: ");
    scanf("%d",&year);
    printf("\n");

    printf("Enter book copies: ");
    scanf("%d",&copies);
    printf("\n");

    head = create_book(id,title,author,year,copies,head);







     for (list_single *cur = head; cur != NULL; cur = cur->next)
        {       printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);

                ld = fopen("linklistsavetest.txt","a");
                fprintf(ld, "%d/%s/%s/%d/%d\n", cur->data.id, cur->data.title, cur->data.authors,cur->data.year,cur->data.copies);
                fclose(ld);

            free(cur->data.title);
            free(cur->data.authors);
            free(cur);

        }




    fclose(fp);








return 0;


}
