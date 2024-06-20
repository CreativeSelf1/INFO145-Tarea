CC=g++
CFLAGS=-Wall -std=c++17 -O3
BINS= arreglo_explicito 
all: clean arreglo_explicito

arreglo_explicito:
	$(CC) $(CFLAGS) -o arreglo_explicito BinarySearch/binarySearch.cpp arreglo_explicito.cpp  

 
clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
