all: main

main: analyse_de_trame.h main.c analyse_de_trame.o
	gcc analyse_de_trame.h analyse_de_trame.o main.c -o main
	
clean: main
	rm -i main
	rm -i *.o
