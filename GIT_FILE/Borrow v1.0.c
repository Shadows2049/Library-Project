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


typedef struct _BookArray {
	 Book* array[100]; // pointer to array (or linked list) of struct Book.
	 unsigned int length; // number of elements in the (Book*) array
}BookArray;


typedef struct _U{
    char *username;
    char *password;
}User;


typedef struct list_node
{

Book data ;

struct list_node *next ;

}list_single;

typedef struct list_u           //Early version of list_user, wrong implication of BookArray
{

BookArray bdata;
User data ;

struct list_u *next ;

}list_user;




char *duplicate_s(const char *n){
 int length = strlen(n);
 char *newString = calloc(length+1,200*sizeof(char));
 strcpy(newString,n);
 return newString;
}



list_single *find_book_by_year(unsigned int year, list_single *head)         //Early version of year matching, final version use Book Array
{


for (list_single *cur = head; cur != NULL; cur = cur->next)
    {   if (cur->data.year == year)
        {
           printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
        }
    }


}



list_single *find_book_by_title(const char *title, list_single *head)           //Early version of title matching, final version use Book Array and strstr()
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



list_single *find_book_by_author(const char *author, list_single *head)           //Early version of author matching, final version use Book Array and strstr()
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





list_user *borrow_book(unsigned int id, const char *username, list_single *head, list_user *uhead){                   //Borrow book by book id and username

for (list_single *cur = head; cur != NULL; cur = cur->next)
    {   if (cur->data.id == id)
        {
           printf("The borrowed book: id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
           if(cur->data.copies == 0)
           {
               printf("No copies left, failure\n");
               break;
           }

           else
           {
                cur->data.copies = cur->data.copies - 1;
                printf("%d left\n", cur->data.copies);

                for (list_user *fur = uhead; fur != NULL; fur = fur->next)
                {   printf("ok, user is %s\n",fur->data.username);
                    unsigned int length = fur->bdata.length;
                    printf("present length is %d\n",length);
                    if (strcmp(username,fur->data.username)==0)
                    {   printf("ok2\n");
                        fur->bdata.array[length] = cur->data.id;
                        printf("Borrow complete, the id of the book you borrow is %d\n\n", fur->bdata.array[fur->bdata.length]);
                        fur->bdata.length = length + 1;
                        printf("Now new length is %d\n",fur->bdata.length);


                        for(int i = 0; i < fur->bdata.length; ++i )
                            printf("book in array %d is %d\n\n",i,fur->bdata.array[i] );

                        return 0;
                    }


                }


                break;

           }


        }
    }





return 0;

}












list_user *create_user(const char *username, const char *password, list_user *head){

    int titlelength = 0;
    int i=0;
    int indicator = 1;


    printf("ok1");

    for (list_user *cur = head; cur != NULL; cur = cur->next)
    {
            printf("ok2");
            if (strcmp(username,cur->data.username)==0)
            {    printf("Existed User, creation failure\n");
                 //return head;
                 indicator = 0;
                 return head;
                 break;
            }



    }





    if(indicator==1)
    {
    printf("Creating brand new Users\n");

    list_user *node = NULL ;
	node = calloc(1,sizeof(list_user));

	if(node == NULL){
	printf("calloc fail!\n");
	}

	node->data.username = duplicate_s(username);

	node->data.password = duplicate_s(password) ;

	node->next = head;

    printf("Creation Complete\n");

	return node ;

    }


}


list_user *load_users(const char *filename)
{

    char line[200]={0};
    char ids[2000];
    char username[200];
    char password[200];
    //unsigned int ids;
    //char ids[100];
    FILE *file;

    list_user *head = NULL;
    if((file = fopen(filename, "r"))==NULL)
        {
            printf("Error, no such file\n\n");
            exit(-99);
        }

    while (fgets(line,sizeof(line),file))
    {

        sscanf(line, "%[^/]/%[^/]/%s",username,password);
        fscanf(,"%[^\n]", c);
        head = create_user(username,password,head);

        printf("username is %s\n",username);
        printf("password is %s\n", password);

        printf("\n");



    }

    fclose(file);
    return head;

}



int store_users(const char *filename, list_user *head)
{

	FILE *file;
    if((file = fopen(filename,"a"))==NULL)
    {
        printf("Save error\n\n");
            exit(-99);
    }




    for (list_user *cur = head; cur != NULL; cur = cur->next)
    {
        //printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
        fprintf(file,"%s/%s/",cur->data.username, cur->data.password);

        if(cur->bdata.length ==0 )
       {   fprintf(file,"-1/");
           fprintf(file,"\n");}

       if(cur->bdata.length >0 )
            {

                for(int i = 0; i<cur->bdata.length; ++i)
                {
                    fprintf(file,"%d/",cur->bdata.array[i]);


                }

                fprintf(file,"\n");

            }

        free(cur->data.username);
        free(cur->data.password);
        free(cur);
    }

    fclose(file);

    return 0;
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

list_single *remove_book(unsigned int id, list_single *head){



list_single *fur;
for (list_single *cur = head; cur != NULL; fur = cur, cur = cur->next)
    {   if (cur->data.id == id)
        {           //printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
                    if(cur==head)
                    {
                        head = cur->next;
                        printf("Action complete\n");

                    }


                    else
                    {
                        fur -> next = cur -> next;

                        //printf("Action complete\n");

                    }

                    break;


        }
    }

return head;
}


list_user *remove_user(const char *username, list_user *head){

list_user *fur;
for (list_user *cur = head; cur != NULL; fur = cur, cur = cur->next)
    {       printf("ok2\n");
            printf("the user now is %s\n\n",cur->data.username);


        if (strcmp(cur->data.username,username)==0 )
        {          // printf("match ok\n");

                    if(cur == head)
                    {
                        head = cur->next;

                        //printf("Action complete 2\n");

                    }


                    else
                    {
                        fur -> next = cur -> next;

                    }

                    break;


        }
    }
return head;

}






int main()
{   char username[200];
    char password[200];

    int count=0;
    //char line[200]={0};
    FILE *fp;
    int c;
    int j=0;
    char loadfilename[200];
    char savefilename[200];
    char load_userfilename[200];
    char save_userfilename[200];
    unsigned int rid;
    char rus[200];
    char busername[200];
    unsigned int bid;


    char stitle[200];
    unsigned int syear;
    char sauthor[200];

    unsigned int year;
    unsigned int copies;
    unsigned int id;
    char title[200];
    char author[200];

    fflush(stdin);
    printf("enter loadfile name(default is loadtest.txt)\n");
    gets(loadfilename);

    list_single *head = load_books(loadfilename);


    fflush(stdin);
    printf("enter userloadfile name(default is user.txt)\n");
    gets(load_userfilename);

    list_user *uhead = load_users(load_userfilename);

    //printf("max id is %d\n",maxid);

 /*   fflush(stdin);
    printf("Registry User name\n");
    gets(username);
    printf("Enter Password\n");
    gets(password);
    uhead = create_user(username, password, uhead);

    /*fflush(stdin);
    printf("\nRemove a user\n");
    gets(rus);
    uhead = remove_user(rus, uhead);

   /* printf("Enter the year for searching\n\n");
    scanf("%d",&syear);
    find_book_by_year(syear, head);


/*

    fflush(stdin);
    printf("Enter the title for searching\n\n");
    gets(stitle);
    find_book_by_title(stitle, head);

/*
    fflush(stdin);
    printf("Enter the authors for searching\n\n");
    gets(sauthor);
    find_book_by_author(sauthor, head); */



 /*   printf("\nRemove a book\n");
    scanf("%d",&rid);
    head = remove_book(rid, head);   //remove books


/*

    printf("ADD a book\n");   //add books

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
*/

     for (list_user *cur = uhead; cur != NULL; cur = cur->next)
    {   printf("ok");
        printf("username is %s, password is %s",cur->data.username, cur->data.password);
        printf("\n");

    }

for (list_single *cur = head; cur != NULL; cur = cur->next)
    {
        printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);


    }






    printf("Which book do you want to borrow?\n");              //Test borrow book
    scanf("%d",&bid);
    printf("Your username is?\n");
    fflush(stdin);
    gets(busername);
    printf("busername is %s\n",busername);

    borrow_book(bid, busername, head, uhead);


    printf("Which book do you want to borrow?\n");              //Test borrow book
    scanf("%d",&bid);
    printf("Your username is?\n");
    fflush(stdin);
    gets(busername);
    printf("busername is %s\n",busername);

    borrow_book(bid, busername, head, uhead);


    printf("Which book do you want to borrow?\n");              //Test borrow book
    scanf("%d",&bid);
    printf("Your username is?\n");
    fflush(stdin);
    gets(busername);
    printf("busername is %s\n",busername);

    borrow_book(bid, busername, head, uhead);

    fflush(stdin);
    printf("enter user savefile name\n");
    gets(save_userfilename);
    store_users(save_userfilename, uhead); //save user info

    fflush(stdin);
    printf("enter book savefile name\n");
    gets(savefilename);
	store_books(savefilename,head); //save book info


	return 0;
}
