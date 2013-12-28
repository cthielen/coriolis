#include "includes.h"
#include "video.h"

int main(int argc, char **argv) {

	printf("Coriolis\nVersion 0.01\n\nWritten by Christopher Thielen\n\n");

	if( video_init() != true ) return(-1);

	

	video_close();

	return(0);
}

