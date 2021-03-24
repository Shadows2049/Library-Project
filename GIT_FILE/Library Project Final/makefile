Main: Main.o Book.o User.o Save_load.o Interface.o
	gcc -o Main Main.o Book.o User.o Save_load.o Interface.o

Main.o: Main.c bookmanagement.h
	gcc -c Main.c

Book.o:	Book.c	bookmanagement.h
	gcc -c Book.c

User.o: User.c bookmanagement.h
	gcc -c User.c

Save_load.o: Save_load.c bookmanagement.h
	gcc -c Save_load.c

Interface.o: Interface.c bookmanagement.h
	gcc -c Interface.c