#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxid = 0;
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



list_single *find_book_by_year(unsigned int year, list_single *head)
{


for (list_single *cur = head; cur != NULL; cur = cur->next)
    {   if (cur->data.year == year)
        {
           printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
        }
    }


}





list_single *find_book_by_title(const char *title, list_single *head)
{
    int titlelength = 0;
    int i=0;
    int indicator = 1;

    titlelength = strlen(title);

    for (list_single *cur = head; cur != NULL; cur = cur->next)
    {
        indicator = 1;

            for(i=0;i<titlelength;++i)
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


        }

            if(indicator==1)
       {
            printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
       }


    }

}



list_single *find_book_by_author(const char *author, list_single *head)
{
    int authorlength = 0;
    int i=0;
    int indicator = 1;

    authorlength = strlen(author);

    for (list_single *cur = head; cur != NULL; cur = cur->next)
    {
        indicator = 1;

            for(i=0;i<authorlength;++i)
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


        }

            if(indicator==1)
       {
            printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
       }


    }



}




list_single *create_book(unsigned int id, const char *title, const char *author, unsigned int year, unsigned int copies, list_single *head){

    int titlelength = 0;
    int i=0;
    int indicator = 1;

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


    printf("Creating brand new books\n");

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
	return node ;





}


list_single *remove_book(unsigned int id, list_single *head){            //Remove a book



for (list_single *cur = head; cur != NULL; cur = cur->next)
    {   if (cur->next->data.id == id)
        {           //printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
                    if(cur->next->next==NULL)
                    {
                        //printf("Next is null\n");
                        cur->next=NULL;
                        printf("Action complete\n");

                    }


                    else
                    {
                        cur->next->data.id = cur->next->next->data.id;
                        cur->next->data.title = cur->next->next->data.title;
                        cur->next->data.authors = cur->next->next->data.authors;
                        cur->next->data.year = cur->next->next->data.year;
                        cur->next->data.copies = cur->next->next->data.copies;
                        cur->next->next = cur->next->next->next;

                        printf("Action complete\n");

                    }

                    break;


        }
    }


}










int store_books(const char *filename, list_single *head)
{

	FILE *file;
    if((file = fopen(filename,"a"))==NULL)
    {
        printf("Save error\n\n");
            exit(-99);
    }

    for (list_single *cur = head; cur != NULL; cur = cur->next)
    {
        printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
        fprintf(file,"%d/%s/%s/%d/%d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
        free(cur->data.title);
        free(cur->data.authors);
        free(cur);
    }

    fclose(file);

    return 0;
}


list_single *load_books(const char *filename)
{

    char line[200]={0};
    unsigned int year;
    unsigned int copies;
    unsigned int id;
    char title[200];
    char author[200];
    FILE *file;

    list_single *head = NULL;
    if((file = fopen(filename, "r"))==NULL)
        {
            printf("Error, no such file\n\n");
            exit(-99);
        }

    while (fgets(line,sizeof(line),file))
    {

        sscanf(line, "%d/%[^/]/%[^/]/%d/%d", &id,title,author,&year,&copies);

        head = create_book(id,title,author,year,copies,head);

        if(maxid<id)
            maxid = id;

        printf("id is %d\n",id);
        printf("title is %s\n", title);
        printf("author is %s\n", author);
        printf("year is %d\n",year);
        printf("copies is %d\n",copies);
        printf("\n");

    }

    fclose(file);
    return head;

}

int main()
{

    int count=0;
    //char line[200]={0};
    FILE *fp;
    int c;
    int j=0;
    char loadfilename[100];
    char savefilename[100];

    char stitle[200];
    unsigned int syear;
    char sauthor[200];

    unsigned int year;
    unsigned int copies;
    unsigned int id;

    unsigned int rid;
    char title[200];
    char author[200];

    fflush(stdin);
    printf("enter loadfile name(default is loadtest.txt)\n");
    gets(loadfilename);

    list_single *head = load_books(loadfilename);

    printf("max id is %d\n",maxid);

    printf("Enter the year for searching\n\n");
    scanf("%d",&syear);
    find_book_by_year(syear, head);



    fflush(stdin);
    printf("Enter the title for searching\n\n");
    gets(stitle);
    find_book_by_title(stitle, head);


    fflush(stdin);
    printf("Enter the authors for searching\n\n");
    gets(sauthor);
    find_book_by_author(sauthor, head);



    printf("\nRemove a book\n");         //Test remove book
    scanf("%d",&rid);
    remove_book(rid, head);



    printf("ADD a book\n");

    //printf("Enter book id: ");
    //scanf("%d",&id);



    fflush(stdin);
    printf("Enter book title: ");
    gets(title);
    printf("\n");

    printf("Enter book author: ");
    gets(author);
    printf("\n");

    printf("Enter book year: ");
    scanf("%d",&year);
    printf("\n");

    printf("Enter book copies: ");
    scanf("%d",&copies);
    printf("\n");

    head = create_book(id,title,author,year,copies,head);

    fflush(stdin);
    printf("enter savefile name\n");
    gets(savefilename);
	store_books(savefilename,head);


	return 0;
}
