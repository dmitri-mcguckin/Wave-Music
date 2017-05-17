CC = g++
EXE = Wave2

all: driver.o music.o tools.o
	$(CC) driver.o music.o tools.o -o $(EXE)
	rm -f *.o

driver.o:
	$(CC) -c driver.cpp	

music.o: music.cpp music.h
	$(CC) -c music.cpp

tools.o: tools.cpp tools.h
	$(CC) -c tools.cpp

clean:
	$(info -- Whoosh! --)
	rm -f *.o 
	rm -f $(EXE)
