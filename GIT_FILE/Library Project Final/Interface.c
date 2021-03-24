#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookmanagement.h"


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

