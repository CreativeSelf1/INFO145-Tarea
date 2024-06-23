CC=g++
CFLAGS=-Wall -std=c++17 -O3
BINS= INFO145-tarea 
all: clean INFO145-tarea

INFO145-tarea:
	$(CC) $(CFLAGS) -o INFO145-tarea BinarySearch/binarySearch.cpp INFO145-tarea.cpp  

 
clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
