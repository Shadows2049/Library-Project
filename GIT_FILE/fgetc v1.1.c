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


typedef struct list_node {
	Book data ;
	struct list_node *next ;
}list_single;


char *duplicate_s(const char *n){
 int length = strlen(n);
 char *newString = calloc(length+1,sizeof(char));
 strcpy(newString,n);
 return newString;
}

list_single *create_book(unsigned int id, const char *title, const char *author, unsigned int year, unsigned int copies, list_single *head){
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
    int i2, j2;
    char s1[200];
    char s2[200];
    int i;
    unsigned int id;
    char title[200];
    char author[200];

    unsigned int year;
    unsigned int copies;

    i = sizeof(list_single);
    printf("struct size is %d\n",i);

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
    printf("\n\ncount is %d\n\n",count);
    fclose(fp);


    fp = fopen("BookLibrary.txt", "r");

    while(j<2)
    {
        for(int i=0; i<5; ++i)
        {   char transfer[200]={0};
            char holster[200]={0};

            while((c = fgetc(fp))!= '/')
        {
                 for(i = 0; s1[i2] != '\0'; ++i2);

                for(j = 0; c!= '\0'; ++j2, ++i2)
                    {
                        s1[i2] = c;
                    }
                s1[i2] = '\0';
                printf("%s", s1);

        }

        printf("\n");

        }

        ++j;

    }

    fclose(fp);


    list_single *head = NULL;
    /*head = create_book(1,"rainbow six","tom",1975,24,head);
    head = create_book(2,"harry","jk",1999,12,head);
    head = create_book(3,"jackryan","tom",1980,45,head);
    head = create_book(4,"callofduty","iw",2019,11,head);
    head = create_book(5,"battlefield v","dice",2018,15,head);
    head = create_book(6,"the division","tom",2016,34,head);*/


    /*for (list_single *cur = head; cur != NULL; cur = cur->next) {
    	printf("id is %d, title is %s, author is %s, year is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
    	free(cur->data.title);
		free(cur->data.authors);
    	free(cur);
	}*/




return 0;

}


