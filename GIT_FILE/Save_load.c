#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book management.h"

list_user *load_users(const char *filename)            //Load user info to memory
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

        sscanf(line, "%[^/]/%[^/]/%d/%d/%d",username,password,&id_a,&id_b,&id_c);

        head = create_user(username,password,head);

        //printf("username is %s\n",username);
        //printf("password is %s\n", password);
        //printf("book1 is %d, book2 is %d, book3 is %d\n",id_a, id_b,id_c);

        head->idar[0] = id_a;
        head->idar[1] = id_b;
        head->idar[2] = id_c;




    }
    printf("\nUser info load complete\n");
    fclose(file);
    return head;

}


int store_users(const char *filename, list_user *head)     //Store user info to local file
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


int store_books(const char *filename, list_single *head)         //Store book info to local file
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


list_single *load_books(const char *filename)               //Load book info to memory
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



