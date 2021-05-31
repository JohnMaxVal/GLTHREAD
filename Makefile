exe:main.c libglthread.a
	gcc -g main.c -o exe -L. libglthread.a
libglthread.a: glthread.o
	ar rs libglthread.a glthread.o
glthread.o: glthread.c
	gcc -c glthread.c -o glthread.o
main.o: main.c
	gcc -c main.c -o main.o
clean:
	rm *.o
