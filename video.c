#include "includes.h"
#include "logger.h"
#include "video.h"

SDL_Surface *screen = NULL;

bool video_init(void) {
	logger( DEBUG, "Initializing video ..." );

	if( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
		logger( FATAL, "Could not initialize video: %s", SDL_GetError() );
		return(false);
	}

	screen = SDL_SetVideoMode(640, 480, 16, 0);
	if( screen == NULL ) {
		logger( FATAL, "Could not set video mode: %s", SDL_GetError() );
		return(false);
	}

	return(true);
}

void video_close(void) {
	logger( DEBUG, "Closing video ..." );

	assert(screen);

	SDL_FreeSurface(screen);
	screen = NULL;
}

