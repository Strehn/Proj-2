#Simple makefile for compiling the programs  
#type make all on the command line
.KEEP_STATE

main.o: main.c 
    gcc -O2 main.c pq-linklist.c pq-miniheap.c -o main

clean: 
	rm main.o 
