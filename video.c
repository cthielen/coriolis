#include "includes.h"
#include "logger.h"
#include "video.h"

SDL_Surface *screen = NULL;
Uint32 video_color_black = 0;

bool video_init(void) {
	logger( DEBUG, "Initializing video ..." );

	if( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
		logger( FATAL, "Could not initialize video: %s", SDL_GetError() );
		return(false);
	}

	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 16, 0 );
	if( screen == NULL ) {
		logger( FATAL, "Could not set video mode: %s", SDL_GetError() );
		return(false);
	}

	/* Set up colors */
	video_color_black = SDL_MapRGB( screen->format, 0, 0, 0 );

	return(true);
}

void video_close(void) {
	logger( DEBUG, "Closing video ..." );

	assert(screen);

	SDL_FreeSurface(screen);
	screen = NULL;
}

void video_sync(void) {
	SDL_Flip(screen);
}

void video_blank_screen(void) {
	static SDL_Rect fullscreen_rect;

	fullscreen_rect.w = SCREEN_WIDTH;
	fullscreen_rect.h = SCREEN_HEIGHT;

	SDL_FillRect(screen, &fullscreen_rect, video_color_black);
}

