#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookmanagement.h"



int main()
{   
    size = 0;
    maxid = 0;
    char username[200];
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
    printf("enter loadfile name(default is loadtest.txt)\n");
    gets(loadfilename);

    //list_single *head = load_books(loadfilename);

    fflush(stdin);
    printf("enter userloadfile name(default is user.txt)\n");
    gets(load_userfilename);

    //list_user *uhead = load_users(load_userfilename);

   while(status!=1)
   {
       user_indicator = 0;
       list_single *head = load_books(loadfilename);
       list_user *uhead = load_users(load_userfilename);
       printf("\n\n");


       prechoice:
       pre_menu(); //Pre Menu


       fflush(stdin);
       scanf("%d",&pre_choice);  //QUIT
       if(!(pre_choice>=1 && pre_choice<=3))
       {
           printf("Wrong command\n");
           goto prechoice;
       }

       if(pre_choice==3)
        exit(0);


       else if(pre_choice==1){

         printf("\n\n");
         fflush(stdin);
         printf("Registry User name\n");  //Registry
         gets(username);
         printf("Enter Password\n");
         gets(password);
         printf("\n\nCreating new User\n");
         uhead = create_user(username, password, uhead);

         if(creat_indicator==1)
            printf("New user created successfully\n");

         store_users(load_userfilename, uhead); //save user info

       }

       else if(pre_choice==2){

         printf("\n\n");
         fflush(stdin);
         printf("Enter username\n");   //Login
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
