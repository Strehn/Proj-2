# Simple makefile for compiling the programs  

.KEEP_STATE

functions: main.o pq.o pqlink.o pqheap.o
         cc -O -o functions main.o pq.o pqlink.o pqheap.o
main.o: main.c 
        	cc -O -c main.c 
pq.o: pq.c 
         cc -O -c pq-miniheap.c 
clean: 
        	rm functions main.o pq.o