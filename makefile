CC = g++
EXE = Wave2

<<<<<<< HEAD
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
=======
all: driver.o music.o tools.o
	$(CC) driver.o music.o tools.o -o $(EXE)
	rm -f *.o

driver.o:
	$(CC) -c driver.cpp	

music.o: music.cpp music.h
	$(CC) -c music.cpp

tools.o: tools.cpp tools.h
	$(CC) -c tools.cpp
>>>>>>> 8a5a45c24575a95bd23c6906e357b7a4083de0ff

clean:
	$(info -- Whoosh! --)
	rm -f *.o 
	rm -f $(EXE)
