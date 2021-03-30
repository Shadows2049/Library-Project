#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

list_user *borrow_book(unsigned int id, const char *username, list_single *head, list_user *uhead){
int check;
int alr;
for (list_single *cur = head; cur != NULL; cur = cur->next)
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


                for (list_user *fur = uhead; fur != NULL; fur = fur->next)
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

printf("No such book\n");
return 0;

}

list_user *return_book(unsigned int id, const char *username, list_single *head, list_user *uhead){
int alr;
int i;
int choice;
int k = 0;

for (list_single *cur = head; cur != NULL; cur = cur->next){
        if(cur->data.id==id){
            printf("The book you want to return: id is %d, title is %s, author is %s, year is %d, copies is %d\n",cur->data.id, cur->data.title, cur->data.authors, cur->data.year, cur->data.copies);

                for (list_user *fur = uhead; fur != NULL; fur = fur->next){

                        if(strcmp(fur->data.username, username)==0){

                                if(fur->idar[0]==0)
                                {
                                    printf("You haven't borrowed any book\n");
                                    return 0;

                                }


                                else
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

printf("No such book\n");
return 0;

}


list_user *show_userinfo(const char *username, list_single *head, list_user *uhead){
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
