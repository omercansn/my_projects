gcc -c data.c -o data.o
gcc -c main.c -o main.o
gcc main.o data.o -o main
rm *.o

