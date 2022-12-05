FLAGS = -Wall -g
CC = gcc
all: my_mat.a connections


my_mat.so: my_mat.o
	$(CC) $(FLAGS) -shared my_mat.o -o my_mat.so

my_mat.o: my_mat.c my_mat.h
	${CC} -fPIC ${FLAGS} -c my_mat.c 

my_mat.a: my_mat.o
	ar -rc my_mat.a my_mat.o

connectionssss: main.o my_mat.a
	$(CC) $(FLAGS) -o connections main.o ./my_mat.a

connections: main.o my_mat.so
	$(CC) $(FLAGS) -o connections main.o ./my_mat.so

.PHONEY: clean
clean:
	rm -f *.o *.a *.so connections