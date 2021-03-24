#include <stdio.h>

#include <stdlib.h>

#include <string.h>




typedef struct list_node

{

int data ;

struct list_node *next ;

}list_single;              //Linked list "list_single"





list_single *create_list_node(int data)       //Creat new node

{

list_single *node = NULL ;

node = (list_single *)malloc(sizeof(list_single));   //Allocate memory

if(node == NULL){

printf("malloc fair!\n");

}

memset(node,0,sizeof(list_single));        //Reset memory

node->data = data;

node->next = NULL ;

return node ;

}




int main(void)              //Test run

{

int data = 100 ;

list_single *node_ptr = create_list_node(data);

printf("node_ptr->data=%d\n",node_ptr->data);

printf("node_ptr->next=%d\n",node_ptr->next);

free(node_ptr);         //Free memory

return 0 ;

}

