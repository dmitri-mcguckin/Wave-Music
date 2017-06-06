CC = g++
EXE = Wave2

all: driver.o song.o songList.o tools.o
	$(CC) driver.o song.o songList.o tools.o -g -o $(EXE)
	rm -f *.o

driver.o:
	$(CC) -g -c driver.cpp	

song.o: song.cpp song.h
	$(CC) -g -c song.cpp

songList.o: songList.cpp songList.h
	$(CC) -g -c songList.cpp

tools.o: tools.cpp tools.h
	$(CC) -g -c tools.cpp
    
clean:
	$(info ---------- Whoosh! ----------)
	rm -f *.o 
	rm -f $(EXE)
    