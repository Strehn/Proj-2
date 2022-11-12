#Simple makefile for compiling the programs  
#type make all on the command line
.KEEP_STATE

all: main.c pq-linkedlist.c pq-minheap.c

main.o: main.c 
	gcc -O2 -o main main.c

pq-link.o: pq-linkedlist.c 
	gcc -O2 -o main pq-linkedlist.c 	    

pq-heap.o: pq-minheap.c 
	gcc -O2 -o main pq-minheap.c

clean: 
	rm main.o pq-link.o pq-heap.o
