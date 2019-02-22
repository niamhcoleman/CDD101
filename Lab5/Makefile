#Niamh C
#C00205225
#18/02/2019

CC= g++
CFLAGS= -std=c++11 -pthread

FILES= main.o Semaphore.o Barrier.o
EXEC= main

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(FILES)
	$(CC) -o $(EXEC) $(FILES) $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

CLEAN:
	RM *.o
