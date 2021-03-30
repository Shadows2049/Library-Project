Main: Main.o Book.o User.o Save_load.o Interface.o
	gcc -o Main Main.o Book.o User.o Save_load.o Interface.o

Main.o: Main.c book_management.h
	gcc -c Main.c

Book.o:	Book.c	book_management.h
	gcc -c Book.c

User.o: User.c book_management.h
	gcc -c User.c

Save_load.o: Save_load.c book_management.h
	gcc -c Save_load.c

Interface.o: Interface.c book_management.h
	gcc -c Interface.c