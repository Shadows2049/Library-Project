#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int size = 0;
int maxid = 0;
typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies; //number of copies the library has
}Book;


typedef struct _BookArray {                 //Use array to store book info for searching
	 Book* array; // pointer to array (or linked list) of struct Book.
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

typedef struct list_u          
{
int idar[3];     //One user is allowed to borrow up to 3 books, idar[3] will store the id of up to 3 books     

User data ;

struct list_u *next ;

}list_user;




char *duplicate_s(const char *n){
 int length = strlen(n);
 char *newString = calloc(length+1,200*sizeof(char));
 strcpy(newString,n);
 return newString;
}






BookArray *find_book_by_year(unsigned int year, list_single *head)   //Use BookArray
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

	        }


	    }

	     printf("%d books found\n",p->length);

         return p;


}




BookArray *find_book_by_title(const char *title, list_single *head)    //Use BookArray
{

    int firstFound = 1;
	BookArray *p = calloc(1,sizeof(BookArray));
	p->array = NULL;
	p->length = 0;

    int titlelength = 0;
    int i=0;
    int indicator = 1;

    titlelength = strlen(title);

    for (list_single *cur = head; cur != NULL; cur = cur->next)           //Early version of title matching, final version use strstr()
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





BookArray *find_book_by_author(const char *author, list_single *head)   //Use BookArray
{

    int firstFound = 1;
	BookArray *p = calloc(1,sizeof(BookArray));
	p->array = NULL;
	p->length = 0;

    int authorlength = 0;
    int i=0;
    int indicator = 1;

    authorlength = strlen(author);

    for (list_single *cur = head; cur != NULL; cur = cur->next)           //Early version of author matching, final version use strstr()
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





list_user *borrow_book(unsigned int id, const char *username, list_single *head, list_user *uhead){
int check;
int alr;
for (list_single *cur = head; cur != NULL; cur = cur->next)
    {   if (cur->data.id == id)
        {
           printf("The book you want to borrow: id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
           if(cur->data.copies == 0)
           {
               printf("No copies left, failure\n");
               break;
           }

           else
           {


                for (list_user *fur = uhead; fur != NULL; fur = fur->next)
                {
                    if (strcmp(username,fur->data.username)==0)
                    {
                                if(fur->idar[2]!=0)
                            {
                                printf("You already borrowed 3 books\n");
                                for(int g=0; g<3; ++g)
                                    printf("%d\n", fur->idar[g] );


                                return 0;

                            }




                        for(alr = 0; alr<3; ++alr)
                        {
                            if(fur->idar[alr]==id)
                            {
                                printf("The book %d you have already borrowed\n",id);
                                return 0;
                            }

                        }

                           for(check = 0; check <3; ++check)
                        {
                            if(fur->idar[check]==0)
                                break;

                        }



                        fur->idar[check] = cur->data.id;

                        printf("Borrow complete, the id of the book you borrow is %d\n\n", fur->idar[check]);

                        cur->data.copies = cur->data.copies - 1;
                        printf("%d left\n", cur->data.copies);

                        //fur->count = fur->count + 1;

                        for(int i = 0; i < check+1; ++i )
                            printf("book in array %d is %d\n\n",i,fur->idar[i] );

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
    //char ids[2000];

    unsigned int id_a;
    unsigned int id_b;
    unsigned int id_c;


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

        sscanf(line, "%[^/]/%[^/]/%d/%d/%d",username,password,&id_a,&id_b,&id_c);

        head = create_user(username,password,head);

        printf("username is %s\n",username);
        printf("password is %s\n", password);
        printf("book1 is %d, book2 is %d, book3 is %d",id_a, id_b,id_c);

        head->idar[0] = id_a;
        head->idar[1] = id_b;
        head->idar[2] = id_c;

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

        if(cur->idar[0] ==0 )
       {   fprintf(file,"0/0/0/");
           fprintf(file,"\n");}

       else if(cur->idar[1]==0 )
            {

                for(int i = 0; i<1; ++i)
                {
                    fprintf(file,"%d/",cur->idar[i]);

                }
                fprintf(file,"0/0/");
                fprintf(file,"\n");

            }

       else if(cur->idar[2]==0 )
            {

                for(int i = 0; i<2; ++i)
                {
                    fprintf(file,"%d/",cur->idar[i]);


                }
                fprintf(file,"0/");
                fprintf(file,"\n");

            }

        else if(cur->idar[2]!=0 )
            {

                for(int i = 0; i<3; ++i)
                {
                    fprintf(file,"%d/",cur->idar[i]);

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



    printf("Enter the year for searching\n\n");        //Search by year
    scanf("%d",&syear);

    BookArray *p = find_book_by_year(syear, head);         


    for(int i_y=0; i_y< p->length; ++i_y){
            printf("id is %d\n",p->array[i_y].id);
            printf("title is %s\n",p->array[i_y].title);
            printf("author is %s\n",p->array[i_y].authors);
            free(p->array[i_y].title);
            free(p->array[i_y].authors);

	     }

    free(p);




    fflush(stdin);
    printf("Enter the author for searching\n\n");           //Search by author            
    gets(sauthor);
    BookArray *b = find_book_by_author(sauthor, head);

    for(int i_t=0; i_t< b->length; ++i_t){
            printf("id is %d\n",b->array[i_t].id);
            printf("title is %s\n",b->array[i_t].title);
            printf("author is %s\n",b->array[i_t].authors);
            free(p->array[i_t].title);
            free(p->array[i_t].authors);

	     }

    free(b);




    fflush(stdin);
    printf("Enter the title for searching\n\n");            //Search by title
    gets(stitle);
    BookArray *x = find_book_by_title(stitle, head);

    for(int i_r=0; i_r< b->length; ++i_r){
            printf("id is %d\n",b->array[i_r].id);
            printf("title is %s\n",b->array[i_r].title);
            printf("author is %s\n",b->array[i_r].authors);
            free(p->array[i_r].title);
            free(p->array[i_r].authors);

	     }

    free(x);



     for (list_user *cur = uhead; cur != NULL; cur = cur->next)
    {   printf("ok");
        printf("username is %s, password is %s",cur->data.username, cur->data.password);
        printf("\n");

    }

for (list_single *cur = head; cur != NULL; cur = cur->next)
    {
        printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);


    }


      printf("Which book do you want to borrow?\n");
    scanf("%d",&bid);
    printf("Your username is?\n");
    fflush(stdin);
    gets(busername);
    printf("busername is %s\n",busername);

    borrow_book(bid, busername, head, uhead);

      printf("Which book do you want to borrow?\n");
    scanf("%d",&bid);
    printf("Your username is?\n");
    fflush(stdin);
    gets(busername);
    printf("busername is %s\n",busername);

    borrow_book(bid, busername, head, uhead);


    printf("Which book do you want to borrow?\n");
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
