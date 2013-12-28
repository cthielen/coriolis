CC=g++
CFLAGS=`sdl-config --cflags` -Wall
LIBS=`sdl-config --libs`
OBJS=main.o video.o logger.o engine.o input.o point.o screen.o

default: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o coriolis $(LIBS)

clean:
	rm -rf *.o
	rm -rf coriolis

main.o: main.cpp includes.h video.h engine.h
	$(CC) $(CFLAGS) -c main.cpp

video.o: video.cpp video.h includes.h logger.h
	$(CC) $(CFLAGS) -c video.cpp

logger.o: logger.cpp logger.h includes.h
	$(CC) $(CFLAGS) -c logger.cpp

engine.o: engine.cpp engine.h includes.h input.h video.h
	$(CC) $(CFLAGS) -c engine.cpp

input.o: input.cpp input.h includes.h
	$(CC) $(CFLAGS) -c input.cpp

point.o: point.cpp point.h
	$(CC) $(CFLAGS) -c point.cpp

screen.o: screen.cpp screen.h
	$(CC) $(CFLAGS) -c screen.cpp

