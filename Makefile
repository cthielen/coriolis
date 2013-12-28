CC=gcc
CFLAGS=`sdl-config --cflags` -Wall
LIBS=`sdl-config --libs`
OBJS=main.o video.o logger.o engine.o input.o

default: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o coriolis $(LIBS)

main.o: main.c includes.h video.h engine.h
	$(CC) $(CFLAGS) -c main.c

video.o: video.c video.h includes.h logger.h
	$(CC) $(CFLAGS) -c video.c

logger.o: logger.c logger.h includes.h
	$(CC) $(CFLAGS) -c logger.c

engine.o: engine.c engine.h includes.h input.h video.h
	$(CC) $(CFLAGS) -c engine.c

input.o: input.c input.h includes.h
	$(CC) $(CFLAGS) -c input.c

