#Niamh C
#C00205225
#18/02/2019

CC= g++
CFLAGS= -std=c++11 -pthread

CFILES= SafeBuffer.cpp Semaphore.cpp Event.cpp Main.cpp
OBJFILES= SafeBuffer.o Semaphore.o Event.o main.o
EXEC= main

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(OBJFILES)
	$(CC) -o $(EXEC) $(OBJFILES) $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG -Wall
DEBUG: ALL

CLEAN:
	RM *.o
