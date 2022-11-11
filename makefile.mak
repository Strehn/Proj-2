# Simple makefile for compiling the programs  

.KEEP_STATE

functions: main.o pq.o pq-link.o pq-heap.o
         cc -O -o functions main.o pq.o pq-link.o pq-heap.o
main.o: main.c 
         cc -O -c main.c 
pq.o: pq.c 
         cc -O -c pq-null.c 
pq-link.o: pqlink.c
         cc -O -c pq-linkedlist.c 	    
pq-heap.o: pqheap.c
         cc -O -c pq-miniheap.c 
clean: 
        	rm functions main.o pq.o pq-link.o pq-heap.o