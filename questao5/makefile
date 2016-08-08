main:	main.o	questao5.o
	gcc main.o questao5.o -o main

main.o: main.c
	gcc -c main.c

questao5.o:	questao5.c	questao5.h
	gcc -c ordenacao.c

clean:
	rm *.o
