#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "book management.h"





typedef struct list_node

{

Book data ;

struct list_node *next ;

}list_single;






list_single *create_list_node(Book data)

{

list_single *node = NULL ;

node = (list_single *)malloc(sizeof(list_single));

if(node == NULL){

printf("malloc fair!\n");

}

memset(node,0,sizeof(list_single));

node->data = data;

node->next = NULL ;

return node ;

}






int main(void)             //Add book test using linked list

{
int i=0;
int choose=0;
int bcount=0;
Book book[i];
char titled[1000];
char author[1000];

for(i=0; i<1000; ++i)
{
    int check = 0;
    unsigned int year;
    unsigned int copies;

    printf("Do you want to add a book? 1 for Yes, 0 for NO\n");
    scanf("%d",&check);
    if(check==1)
    {

        book[i].id = i;

        printf("Enter the title\n");
        scanf("%s",&titled);
        book[i].title = (char*)malloc(sizeof(char));
        strcpy(book[i].title,titled);


        printf("Enter the authors\n");
        scanf("%s",&author);
        book[i].authors = (char*)malloc(sizeof(char));
        strcpy(book[i].authors,author);


        /*printf("Enter the year\n");
        scanf("%d",&year);
        book[i].year=year;
        printf("Enter the copies\n");
        scanf("%d",&copies);
        book[i].copies=copies;
        bcount = bcount + 1;*/

        printf("\nid is %d\n",book[i].id);
        printf("\n the title is %s\n", book[i].title);
        printf("\nauthor is %s\n",book[i].authors);
        /*printf("\ncopies is %d\n",book[i].copies);
        printf("\nyear is %d\n",book[i].year);*/



    }
    else
       break;




}

        printf("Which book do you want to search? Enter number between 0 and %d\n", i-1);
        scanf("%d",&choose);
        Book data = book[choose];
        list_single *node_ptr = create_list_node(data); 

        printf("node_ptr->id=%d\n",node_ptr->data.id); 

        printf("node_ptr->title=%s\n",node_ptr->data.title);

        printf("node_ptr->authors=%s\n",node_ptr->data.authors);

        printf("node_ptr->year=%d\n",node_ptr->data.year);

        printf("node_ptr->copies=%d\n",node_ptr->data.copies);

        printf("node_ptr->next=%d\n",node_ptr->next);

        free(book[i].title);      
        free(book[i].authors);

        free(node_ptr);





return 0 ;

}

