all:
	make conduct
	make main1
	make main2
	make main3

conduct: conduct.h conduct.c
	gcc -Wall -c conduct.h conduct.c -c

main1: main1.c conduct.o
	gcc -Wall main1.c conduct.o -o main1 -pthread

main2: main2.c conduct.o
	gcc -Wall main2.c conduct.o -o main2 -pthread

main3: main3.c conduct.o
	gcc -Wall main3.c conduct.o -o main3 -pthread

clean:
	rm *.o
	rm *.gch
	find . -maxdepth 1 -type f  ! -name "*.c" ! -name "*.h" ! -name "Makefile" -delete
