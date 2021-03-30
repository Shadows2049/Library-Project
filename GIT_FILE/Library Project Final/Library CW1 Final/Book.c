#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

char *duplicate_s(const char *n){
 int length = strlen(n);
 char *newString = calloc(length+1,200*sizeof(char));
 strcpy(newString,n);
 return newString;
}


BookArray *find_book_by_year(unsigned int year, list_single *head)
{


	int firstFound = 1;
	BookArray *p = calloc(1,sizeof(BookArray));
	p->array = NULL;
	p->length = 0;


	for (list_single *cur = head; cur != NULL; cur = cur->next)
	    {   if (cur->data.year == year)
	        {

				if (firstFound == 1) {
		            p->array = (Book*)malloc(sizeof(Book));
		            //printf("ok");
		            p->length = 1;

		            firstFound = 0;
				}
				else {
					p->array = (Book*)realloc(p->array,(p->length+1)*sizeof(Book));
					p->length = p->length + 1;
				}

				p->array[p->length-1].id = cur->data.id;

				p->array[p->length-1].title = duplicate_s(cur->data.title) ;
				p->array[p->length-1].authors = duplicate_s(cur->data.authors);
				p->array[p->length-1].year = cur->data.year;
				p->array[p->length-1].copies = cur->data.copies;

				printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);

	        }


	    }

	     printf("%d books found\n",p->length);

         return p;


}


BookArray *find_book_by_title(const char *title, list_single *head)
{

    int firstFound = 1;
	BookArray *p = calloc(1,sizeof(BookArray));
	p->array = NULL;
	p->length = 0;

    int titlelength = 0;
    int i=0;
    int indicator = 1;

    titlelength = strlen(title);

    for (list_single *cur = head; cur != NULL; cur = cur->next)
    {
        indicator = 1;

       /*     for(i=0;i<titlelength;++i)
        {
            if (title[i] == cur->data.title[i])
            {
                continue;
            }

            else
            {
                indicator = 0;
                break;
            }


        } */

            if(strstr(cur->data.title,title)!=NULL)
       {
            if (firstFound == 1) {
		            p->array = (Book*)malloc(sizeof(Book));
		            //printf("ok");
		            p->length = 1;

		            firstFound = 0;
				}

            else {

					p->array = (Book*)realloc(p->array,(p->length+1)*sizeof(Book));
					p->length = p->length + 1;
				}

            p->array[p->length-1].id = cur->data.id;
				//printf("id is %d\n",cur->data.id);
            p->array[p->length-1].title = duplicate_s(cur->data.title) ;
            p->array[p->length-1].authors = duplicate_s(cur->data.authors);
            p->array[p->length-1].year = cur->data.year;
            p->array[p->length-1].copies = cur->data.copies;


            printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
       }


    }

        printf("%d books found\n",p->length);
        return p;


}


BookArray *find_book_by_author(const char *author, list_single *head)
{

    int firstFound = 1;
	BookArray *p = calloc(1,sizeof(BookArray));
	p->array = NULL;
	p->length = 0;

    int authorlength = 0;
    int i=0;
    int indicator = 1;

    authorlength = strlen(author);

    for (list_single *cur = head; cur != NULL; cur = cur->next)
    {
        indicator = 1;

        /*    for(i=0;i<authorlength;++i)
        {
            if (author[i] == cur->data.authors[i])
            {
                continue;
            }

            else
            {
                indicator = 0;
                break;
            }


        } */

            if(strstr(cur->data.authors,author)!=NULL)
       {
            if (firstFound == 1) {
		            p->array = (Book*)malloc(sizeof(Book));
		            //printf("ok");
		            p->length = 1;

		            firstFound = 0;
				}

            else {

					p->array = (Book*)realloc(p->array,(p->length+1)*sizeof(Book));
					p->length = p->length + 1;
				}

            p->array[p->length-1].id = cur->data.id;
				//printf("id is %d\n",cur->data.id);
            p->array[p->length-1].title = duplicate_s(cur->data.title) ;
            p->array[p->length-1].authors = duplicate_s(cur->data.authors);
            p->array[p->length-1].year = cur->data.year;
            p->array[p->length-1].copies = cur->data.copies;


            printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
       }


    }

        printf("%d books found\n",p->length);
        return p;


}



list_single *add_book(unsigned int id, const char *title, const char *author, unsigned int year, unsigned int copies, list_single *head){

    int titlelength = 0;
    int i=0;
    int indicator = 1;
    addbook_indicator = 0;

    titlelength = strlen(title);

    for (list_single *cur = head; cur != NULL; cur = cur->next)
    {       //printf("Comparing\n\n");


            if (strcmp(title,cur->data.title)==0)
            {    //printf("title is the same\n");
                if(strcmp(author,cur->data.authors)==0)
                {
                    if(year == cur->data.year)
                    {
                        cur->data.copies = cur->data.copies + copies;
                        //printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
                        indicator = 1;
                        printf("The book already exisited, %d copies added\n\n",copies);
                        addbook_indicator = 1;
                        return head;
                        break;
                    }
                }
            }

            else
            {
                indicator = 0;

            }

    }


    //printf("Creating new book\n");

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
	node->next = head;

    addbook_indicator = 1;
	//printf("Creation Complete\n\n");
	return node ;

}


list_single *remove_book(unsigned int id, list_single *head){


int action_check = 0;
list_single *fur;
for (list_single *cur = head; cur != NULL; fur = cur, cur = cur->next)
    {   if (cur->data.id == id)
        {           //printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
                    if(cur==head)
                    {
                        head = cur->next;
                        action_check = 1;
                        //printf("Action complete\n");

                    }


                    else
                    {
                        fur -> next = cur -> next;
                        action_check = 1;
                        //printf("Action complete\n");

                    }

                    break;


        }
    }

if(action_check==1)
    printf("Action complete\n");
else
    printf("Action failure\n");

return head;
}
