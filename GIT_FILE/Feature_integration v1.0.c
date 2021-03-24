#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int size = 0;
int maxid = 0;
int user_indicator; //check whether user is Librarian
int creat_indicator; //check whether user creation is success or not
int addbook_indicator;  //check whether book creation is success or not

typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies; //number of copies the library has
}Book;


typedef struct _BookArray {
	 Book* array; // pointer to array (or linked list) of struct Book.
	 unsigned int length; // number of elements in the (Book*) array
}BookArray;


typedef struct _U{      //linked list containing all users
    char *username;     //username
    char *password;     //password
}User;


typedef struct list_node     //linked list containing all books
{

Book data ;                  //book info

struct list_node *next ;      //pointer to next list

}list_single;

typedef struct list_u        //linked list containing User and Borrowed books
{
int idar[3];                 //a user can borrow up to 3 books, idar[3] stores id of up to 3 books

User data ;                 //user info

struct list_u *next ;       //pointer to next list

}list_user;



char *duplicate_s(const char *n){          
 int length = strlen(n);        //length of char
 char *newString = calloc(length+1,200*sizeof(char));  //allocate memory for char
 strcpy(newString,n);            
 return newString;                   //return a string
}


BookArray *find_book_by_year(unsigned int year, list_single *head)   
{


	int firstFound = 1;
	BookArray *p = calloc(1,sizeof(BookArray));                 
	p->array = NULL;
	p->length = 0;


	for (list_single *cur = head; cur != NULL; cur = cur->next)       //traverse 
	    {   if (cur->data.year == year)
	        {

				if (firstFound == 1) {
		            p->array = (Book*)malloc(sizeof(Book));            //first found, allocate memory space
		            //printf("ok");
		            p->length = 1;

		            firstFound = 0;
				}
				else {
					p->array = (Book*)realloc(p->array,(p->length+1)*sizeof(Book));            //found again, need reallocate
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


BookArray *find_book_by_title(const char *title, list_single *head)    //Not final version
{

    int firstFound = 1;
	BookArray *p = calloc(1,sizeof(BookArray));
	p->array = NULL;
	p->length = 0;

    int titlelength = 0;
    int i=0;
    int indicator = 1;

    titlelength = strlen(title);

    for (list_single *cur = head; cur != NULL; cur = cur->next)             //traverse
    {
        indicator = 1;

            for(i=0;i<titlelength;++i)
        {
            if (title[i] == cur->data.title[i])                             //match title
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
		            p->array = (Book*)malloc(sizeof(Book));                 //first found, allocate memory space
		            //printf("ok");
		            p->length = 1;

		            firstFound = 0;
				}

            else {

					p->array = (Book*)realloc(p->array,(p->length+1)*sizeof(Book));             //found again, need reallocate
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


BookArray *find_book_by_author(const char *author, list_single *head)       //Not final version
{

    int firstFound = 1;
	BookArray *p = calloc(1,sizeof(BookArray));
	p->array = NULL;
	p->length = 0;

    int authorlength = 0;
    int i=0;
    int indicator = 1;

    authorlength = strlen(author);

    for (list_single *cur = head; cur != NULL; cur = cur->next)             //traverse
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
		            p->array = (Book*)malloc(sizeof(Book));                 //first found, allocate memory space
		            //printf("ok");
		            p->length = 1;

		            firstFound = 0;
				}

            else {

					p->array = (Book*)realloc(p->array,(p->length+1)*sizeof(Book));      //found again, need reallocate
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

    for (list_single *cur = head; cur != NULL; cur = cur->next)             //check whether exisited
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
                        printf("The book already exisited, %d copies added\n\n",copies);                //existed, add copies
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


    //printf("Creating new book\n");            //create new book

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



list_user *borrow_book(unsigned int id, const char *username, list_single *head, list_user *uhead){
int check;
int alr;
for (list_single *cur = head; cur != NULL; cur = cur->next)            //match the book
    {   if (cur->data.id == id)
        {
           printf("\nThe book you want to borrow: id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
           if(cur->data.copies == 0)
           {
               printf("No copies left, failure\n");
               break;
           }

           else
           {


                for (list_user *fur = uhead; fur != NULL; fur = fur->next)             //check if user already borrowed 3 books(max is 3)
                {
                    if (strcmp(username,fur->data.username)==0)
                    {
                                if(fur->idar[2]!=0) 
                            {
                                printf("You already borrowed 3 books\n");
                                //for(int g=0; g<3; ++g)
                                    //printf("%d\n", fur->idar[g] );


                                return 0;

                            }




                        for(alr = 0; alr<3; ++alr)                                     //check if user already borrowed this book
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



                        fur->idar[check] = cur->data.id;                               //book id stored into idar

                        printf("Borrow complete, the id of the book you borrow is %d\n\n", fur->idar[check]);

                        cur->data.copies = cur->data.copies - 1;
                        printf("%d copies left\n\n", cur->data.copies);

                        //fur->count = fur->count + 1;

                        //for(int i = 0; i < check+1; ++i )
                            //printf("book in array %d is %d\n\n",i,fur->idar[i] );

                        return 0;
                    }


                }


                break;

           }


        }
    }

printf("No such book\n");               //book not found
return 0;

}


list_user *return_book(unsigned int id, const char *username, list_single *head, list_user *uhead){
int alr;
int i;
int choice;
int k = 0;

for (list_single *cur = head; cur != NULL; cur = cur->next){            //check if user has borrowed any book
        if(cur->data.id==id){
            printf("The book you want to return: id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);

                for (list_user *fur = uhead; fur != NULL; fur = fur->next){

                        if(strcmp(fur->data.username, username)==0){

                                if(fur->idar[0]==0)
                                {
                                    printf("You haven't borrowed any book\n");
                                    return 0;

                                }


                                else                                                    //return book and reorder idar
                                {
                                    for(i=0;i<3;++i){
                                        if(fur->idar[i]==id)
                                        {
                                            if(i==0){
                                                fur->idar[0] = fur->idar[1];
                                                fur->idar[1] = fur->idar[2];
                                                fur->idar[2] = 0;
                                                printf("Return complete\n");
                                                cur->data.copies = cur->data.copies+1;
                                                return 0;

                                            }

                                            if(i==1){
                                                fur->idar[1] = fur->idar[2];
                                                fur->idar[2] = 0;
                                                printf("Return complete\n");
                                                cur->data.copies = cur->data.copies+1;
                                                return 0;

                                            }


                                            if(i==2){
                                                fur->idar[2] = 0;
                                                printf("Return complete\n");
                                                cur->data.copies = cur->data.copies+1;
                                                return 0;

                                            }




                                        }

                                    }
                                    printf("You did not borrow this book\n");
                                    return 0;

                                }


                        }


                }

        }


}

printf("No such book\n");          //book not found
return 0;

}



list_user *show_userinfo(const char *username, list_single *head, list_user *uhead){        //show username and books they've borrow
int alr;
int i;
int choice;
int k = 0;
    for (list_user *fur = uhead; fur != NULL; fur = fur->next){

            if(strcmp(fur->data.username, username)==0){

                    if(fur->idar[0]==0)
                    {   printf("\n\nUser is %s\n",username);
                        printf("You haven't borrowed any book\n");
                        return 0;

                    }

                    else
                    {   printf("\n\nUser is %s\n",username);
                        for(i=0; i<3; ++i){
                            if(fur->idar[i]!=0){
                                printf("The %d book you've borrowed is id: %d\n",i+1,fur->idar[i]);
                                k = k+ 1;

                            }

                        }

                        printf("you have borrowed %d books\n",k);


                    }


            }


    }


return 0;

}



list_user *create_user(const char *username, const char *password, list_user *head){

    int titlelength = 0;
    int i=0;
    int indicator = 1;
    creat_indicator = 0;

    //printf("ok1");

    for (list_user *cur = head; cur != NULL; cur = cur->next)
    {
            //printf("ok2");
            if (strcmp(username,cur->data.username)==0)
            {    printf("Existed User, creation failure\n\n");
                 //return head;
                 indicator = 0;
                 return head;
                 break;
            }

    }


    if(indicator==1)
    {
    //printf("Creating new User\n");

    list_user *node = NULL ;
	node = calloc(1,sizeof(list_user));

	if(node == NULL){
	printf("calloc fail!\n");
	}

	node->data.username = duplicate_s(username);

	node->data.password = duplicate_s(password) ;

	node->next = head;

    //printf("Creation Complete\n\n");
    creat_indicator = 1;

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
            printf("\nError, no such file\n\n");
            exit(-99);
        }

    while (fgets(line,sizeof(line),file))
    {

        sscanf(line, "%[^/]/%[^/]/%d/%d/%d",username,password,&id_a,&id_b,&id_c);   //load user info from file, seperate by /

        head = create_user(username,password,head);             //create link list

        //printf("username is %s\n",username);
        //printf("password is %s\n", password);
        //printf("book1 is %d, book2 is %d, book3 is %d\n",id_a, id_b,id_c);

        head->idar[0] = id_a;                 //create borrow info
        head->idar[1] = id_b;
        head->idar[2] = id_c;




    }
    printf("\nUser info load complete\n");
    fclose(file);
    return head;

}



int store_users(const char *filename, list_user *head)
{

	FILE *file;
    if((file = fopen(filename,"a"))==NULL)
    {

        printf("\nSave error\n\n");
            exit(-99);
    }
    fclose(file);
    file = fopen(filename,"w+");

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
    printf("\nUser info save complete\n");
    return 0;
}



int store_books(const char *filename, list_single *head)
{

	FILE *file;
    if((file = fopen(filename,"a"))==NULL)
    {
        printf("\nSave error\n\n");
            exit(-99);
    }
    fclose(file);
    file = fopen(filename,"w+");
    for (list_single *cur = head; cur != NULL; cur = cur->next)
    {
        //printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
        fprintf(file,"%d/%s/%s/%d/%d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
        free(cur->data.title);
        free(cur->data.authors);
        free(cur);
    }

    fclose(file);
    printf("\nBook info save complete\n");

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
            printf("\nError, no such file\n\n");
            exit(-99);
        }

    while (fgets(line,sizeof(line),file))
    {

        sscanf(line, "%d/%[^/]/%[^/]/%d/%d", &id,title,author,&year,&copies);

        head = add_book(id,title,author,year,copies,head);

        if(maxid<id)
            maxid = id;

        //printf("id is %d\n",id);
        //printf("title is %s\n", title);
        //printf("author is %s\n", author);
        //printf("year is %d\n",year);
        //printf("copies is %d\n",copies);
        //printf("\n");

    }

    fclose(file);
    printf("\nBook info load complete\n");
    return head;

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


list_user *remove_user(const char *username, list_user *head){

int action_check = 0;
list_user *fur;
for (list_user *cur = head; cur != NULL; fur = cur, cur = cur->next)
    {       //printf("ok2\n");
            //printf("the user now is %s\n\n",cur->data.username);


        if (strcmp(cur->data.username,username)==0 )
        {          // printf("match ok\n");

                    if(cur == head)
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

if(action_check ==1)
    printf("Action complete\n");
else
    printf("Action failure\n");


return head;

}


list_user *login(const char *username, const char *password, list_user *head){

if(strcmp(username,"librarian")==0)
{
    if(strcmp(password,"librarian")==0)
    {
        //printf("Login as librarian\n");
        user_indicator = 1;
        return 0;

    }
}


    for(list_user *cur = head; cur != NULL; cur = cur->next){

             if (strcmp(cur->data.username,username)==0 )
             {
                if (strcmp(cur->data.password,password)==0 ){
                    //printf("Login Complete, now you are as %s\n", username);
                    user_indicator = 2;
                    return 0;
                }

                else{
                    printf("Password wrong, login fail\n");
                    return 0;
                }

             }


    }

  printf("User not found, login fail\n");
  return 0;

}


int pre_menu(){
printf("1) Register an account\n");
printf("2) Login\n");
printf("3) Quit\n");

return 0;
}

int main_menu_user(){
printf("1) Show user info\n");
printf("2) Display all books\n");
printf("3) Search for books\n");
printf("4) Borrow a book\n");
printf("5) Return a book\n");
printf("6) Log out\n");

return 0;
}

int main_menu_librarian(){
printf("1) Display all books\n");
printf("2) Search for books\n");
printf("3) Add a book\n");
printf("4) Remove a book\n");
printf("5) Display all users\n");
printf("6) Remove a user\n");
printf("7) Log out\n");


return 0;
}

int sec_menu_search(){
printf("\n\n");
printf("1) Search by year\n");
printf("2) Search by title\n");
printf("3) Search by author\n");

return 0;
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
    unsigned int reid;
    char lusername[200];
    char lpassword[200];

    char stitle[200];
    unsigned int syear;
    char sauthor[200];

    unsigned int year;
    unsigned int copies;
    unsigned int id;
    char title[200];
    char author[200];

    int status = 0;
    int pre_choice;
    int main_choice;
    int sec_choice;









    fflush(stdin);
    printf("enter loadfile name(default is loadtest.txt)\n");         //book file
    gets(loadfilename);

    //list_single *head = load_books(loadfilename);

    fflush(stdin);
    printf("enter userloadfile name(default is user.txt)\n");         //user file
    gets(load_userfilename);

    //list_user *uhead = load_users(load_userfilename);

   while(status!=1)
   {
       user_indicator = 0;
       list_single *head = load_books(loadfilename);                //load files, create link lists
       list_user *uhead = load_users(load_userfilename);
       printf("\n\n");


       prechoice:
       pre_menu(); //Pre Menu


       fflush(stdin);
       scanf("%d",&pre_choice);  
       if(!(pre_choice>=1 && pre_choice<=3))
       {
           printf("Wrong command\n");
           goto prechoice;
       }

       if(pre_choice==3)          //quit
        exit(0);


       else if(pre_choice==1){      //Registry

         printf("\n\n");
         fflush(stdin);
         printf("Registry User name\n");
         gets(username);
         printf("Enter Password\n");
         gets(password);
         printf("\n\nCreating new User\n");
         uhead = create_user(username, password, uhead);

         if(creat_indicator==1)
            printf("New user created successfully\n");

         store_users(load_userfilename, uhead); //save user info

       }

       else if(pre_choice==2){      //Login

         printf("\n\n");
         fflush(stdin);
         printf("Enter username\n");  
         gets(lusername);
         printf("Enter password\n");
         gets(lpassword);
         login(lusername,lpassword,uhead);



         if(user_indicator==1){        //Login as Librarian

                while(status!=1){

                     mainchoice:
                     printf("\n\nLogin as Librarian\n");
                     main_menu_librarian();


                     fflush(stdin);
                     scanf("%d",&main_choice);

                      if(!(main_choice>=1 && main_choice<=7))
                       {
                           printf("Wrong command\n");
                           goto mainchoice;
                       }

                     if(main_choice==1){          //Display all books
                        for (list_single *cur = head; cur != NULL; cur = cur->next)
                        {
                                printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
                                printf("\n");

                        }

                     }

                     else if(main_choice==2){        //Search for books

                            secchoice:
                            sec_menu_search();

                            fflush(stdin);
                            scanf("%d",&sec_choice);

                            if(!(sec_choice>=1 && sec_choice<=3))
                               {
                                   printf("Wrong command\n");
                                   goto secchoice;
                               }



                             if(sec_choice==1){   //by year

                                    printf("Enter the year for searching\n\n");
                                    scanf("%d",&syear);
                                    BookArray *p = find_book_by_year(syear, head);

                                    for(int i_y=0; i_y< p->length; ++i_y){
                                        //printf("id is %d\n",p->array[i_y].id);
                                        //printf("title is %s\n",p->array[i_y].title);
                                        //printf("author is %s\n",p->array[i_y].authors);
                                        free(p->array[i_y].title);
                                        free(p->array[i_y].authors);

	                                 }

                                    free(p);

                            }


                            if(sec_choice==2){    //by title

                                        fflush(stdin);
                                        printf("Enter the title for searching\n\n");
                                        gets(stitle);
                                        BookArray *x = find_book_by_title(stitle, head);

                                        for(int i_r=0; i_r< x->length; ++i_r){
                                                //printf("id is %d\n",x->array[i_r].id);
                                                //printf("title is %s\n",x->array[i_r].title);
                                                //printf("author is %s\n",x->array[i_r].authors);
                                                free(x->array[i_r].title);
                                                free(x->array[i_r].authors);

                                             }

                                        free(x);

                            }


                            if(sec_choice==3){     //by author

                                        fflush(stdin);
                                        printf("Enter the author for searching\n\n");
                                        gets(sauthor);
                                        BookArray *b = find_book_by_author(sauthor, head);

                                        for(int i_t=0; i_t< b->length; ++i_t){
                                                //printf("id is %d\n",b->array[i_t].id);
                                                //printf("title is %s\n",b->array[i_t].title);
                                                //printf("author is %s\n",b->array[i_t].authors);
                                                free(b->array[i_t].title);
                                                free(b->array[i_t].authors);

                                             }

                                        free(b);

                            }



                         }

                         else if(main_choice==3){            //add a book

                                        printf("ADD a book\n");   //add books

                                        //printf("Enter book id: ");
                                        //scanf("%d",&id);
                                        maxid = maxid + 1;
                                        id = maxid;

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

                                        head = add_book(id,title,author,year,copies,head);
                                        if(addbook_indicator==1)
                                            printf("Book added\n");

                        }


                        else if(main_choice==4){                //remove a book

                                        printf("\nRemove a book(enter id)\n");
                                        scanf("%d",&rid);
                                        head = remove_book(rid, head);

                        }


                        else if(main_choice==5){                //Display all users
                                         for (list_user *cur = uhead; cur != NULL; cur = cur->next)
                                        {   //printf("ok");
                                            printf("username is %s, password is %s,  borrowed books are(0 stands for null): %d, %d, %d ",cur->data.username, cur->data.password, cur->idar[0], cur->idar[1], cur->idar[2]);
                                            printf("\n");

                                        }


                        }

                        else if(main_choice==6){                //Remove a user

                                        fflush(stdin);
                                        printf("\nRemove a user\n");
                                        gets(rus);
                                        uhead = remove_user(rus, uhead);


                        }

                        else if(main_choice==7){                //Log out

                                    //fflush(stdin);
                                    //printf("enter user savefile name\n");
                                    //gets(save_userfilename);
                                    store_users(load_userfilename, uhead); //save user info

                                    //fflush(stdin);
                                    //printf("enter book savefile name\n");
                                    //gets(savefilename);
                                    store_books(loadfilename,head); //save book info


                                    break;


                        }


                }


         }



         if(user_indicator==2){        //Login as User

                while(status!=1){

                     smainchoice:
                     printf("\n\nLogin as %s\n", lusername);
                     main_menu_user();

                     fflush(stdin);
                     scanf("%d",&main_choice);

                        if(!(main_choice>=1 && main_choice<=6))
                       {
                           printf("Wrong command\n");
                           goto smainchoice;
                       }



                      if(main_choice==1){      //Show user info
                            show_userinfo(lusername, head, uhead);


                      }

                      else if(main_choice==2){          //Display all books
                        for (list_single *cur = head; cur != NULL; cur = cur->next)
                        {
                                printf("id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);
                                printf("\n");

                        }

                     }


                      else if(main_choice==3){        //Search for books
                            ssecchoice:
                            sec_menu_search();

                            fflush(stdin);
                            scanf("%d",&sec_choice);

                            if(!(sec_choice>=1 && sec_choice<=3))
                               {
                                   printf("Wrong command\n");
                                   goto ssecchoice;
                               }


                             if(sec_choice==1){   //by year

                                    printf("Enter the year for searching\n\n");
                                    scanf("%d",&syear);
                                    BookArray *p = find_book_by_year(syear, head);

                                    for(int i_y=0; i_y< p->length; ++i_y){
                                        //printf("id is %d\n",p->array[i_y].id);
                                        //printf("title is %s\n",p->array[i_y].title);
                                        //printf("author is %s\n",p->array[i_y].authors);
                                        free(p->array[i_y].title);
                                        free(p->array[i_y].authors);

	                                 }

                                    free(p);

                            }


                            if(sec_choice==2){    //by title

                                        fflush(stdin);
                                        printf("Enter the title for searching\n\n");
                                        gets(stitle);
                                        BookArray *x = find_book_by_title(stitle, head);

                                        for(int i_r=0; i_r< x->length; ++i_r){
                                                //printf("id is %d\n",x->array[i_r].id);
                                                //printf("title is %s\n",x->array[i_r].title);
                                                //printf("author is %s\n",x->array[i_r].authors);
                                                free(x->array[i_r].title);
                                                free(x->array[i_r].authors);

                                             }

                                        free(x);

                            }


                            if(sec_choice==3){         //by author

                                        fflush(stdin);
                                        printf("Enter the author for searching\n\n");
                                        gets(sauthor);
                                        BookArray *b = find_book_by_author(sauthor, head);

                                        for(int i_t=0; i_t< b->length; ++i_t){
                                                //printf("id is %d\n",b->array[i_t].id);
                                                //printf("title is %s\n",b->array[i_t].title);
                                                //printf("author is %s\n",b->array[i_t].authors);
                                                free(b->array[i_t].title);
                                                free(b->array[i_t].authors);

                                             }

                                        free(b);

                            }



                         }


                        else if(main_choice==4){              //Borrow a book

                                        printf("\n\nWhich book do you want to borrow?\n");
                                        scanf("%d",&bid);

                                        borrow_book(bid, lusername, head, uhead);


                        }

                        else if(main_choice==5){               //Return a book

                                        printf("\n\nWhich book do you want to return?\n");
                                        scanf("%d",&reid);

                                        return_book(reid, lusername, head, uhead);


                        }

                        else if(main_choice==6){                //Log out

                                        //fflush(stdin);
                                        //printf("enter user savefile name\n");
                                        //gets(save_userfilename);
                                        store_users(load_userfilename, uhead); //save user info

                                        //fflush(stdin);
                                        //printf("enter book savefile name\n");
                                        //gets(savefilename);
                                        store_books(loadfilename,head); //save book info


                                        break;


                        }


                }



         }



       }


       else{
        printf("\nWrong command");
       }
   }



	return 0;
}

