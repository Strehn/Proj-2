# Simple makefile for compiling the programs  
#type make all on the command line
.KEEP_STATE

all: main.c pq-null.c pq-linkedlist.c pq-miniheap.c

main.o: main.c 
         gcc -o main main.c 

pq-link.o: pqlink.c
         gcc -o pq-list pq-linkedlist.c 	    

pq-heap.o: pqheap.c
         gcc -o pq-heap pq-miniheap.c 

clean: 
        	rm main.o pq.o pq-link.o pq-heap.o