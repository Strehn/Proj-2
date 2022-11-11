# Simple makefile for compiling a the programs  

.KEEP_STATE

functions: main.o pq.o 
         cc -O -o functions main.o pq.o 
main.o: main.c 
        	cc -O -c main.c 
pq.o: pq.c 
         cc -O -c pq-null.c pq-linkedlist.c pq-miniheap.c
clean: 
        	rm functions main.o pq.o