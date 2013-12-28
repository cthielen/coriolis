CC=gcc
CFLAGS=`sdl-config --cflags` -Wall
LIBS=`sdl-config --libs`
OBJS=main.o video.o logger.o

default: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o coriolis $(LIBS)

main.o: main.c includes.h video.h
	$(CC) $(CFLAGS) -c main.c

video.o: video.c video.h includes.h
	$(CC) $(CFLAGS) -c video.c

logger.o: logger.c logger.h includes.h
	$(CC) $(CFLAGS) -c logger.c

