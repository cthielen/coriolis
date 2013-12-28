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

	/* Purposefully use software surfaces as we'll be emulating DOS-style drawing with lots *
         * of pixel access. */
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 16, SDL_SWSURFACE );
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

/* Borrowed from http://sdl.beuc.net/sdl.wiki/Pixel_Access */
void video_put_pixel(int x, int y, Uint32 color) {
	int bpp = screen->format->BytesPerPixel;

	SDL_LockSurface(screen);

	Uint8 *p = (Uint8 *)screen->pixels + y * screen->pitch + x * bpp;

	switch(bpp) {
		case 1:
			*p = color;
			break;
		case 2:
			*(Uint16 *)p = color;
			break;
		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				p[0] = (color >> 16) & 0xff;
				p[1] = (color >> 8) & 0xff;
				p[2] = color & 0xff;
			} else {
				p[0] = color & 0xff;
				p[1] = (color >> 8) & 0xff;
				p[2] = (color >> 16) & 0xff;
			}
			break;
		case 4:
			*(Uint32 *)p = color;
			break;
	}

	SDL_UnlockSurface(screen);
}

/* Borrowed from http://sdl.beuc.net/sdl.wiki/Pixel_Access */
Uint32 video_get_pixel(int x, int y) {
	int bpp = screen->format->BytesPerPixel;

	SDL_LockSurface(screen);

	Uint8 *p = (Uint8 *)screen->pixels + y * screen->pitch + x * bpp;
	Uint32 pixel;

	switch(bpp) {
		case 1:
			pixel = *p;
			break;
		case 2:
			pixel = *(Uint16 *)p;
			break;
		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				pixel = p[0] << 16 | p[1] << 8 | p[2];
			else
				pixel = p[0] | p[1] << 8 | p[2] << 16;
			break;
		case 4:
			pixel = *(Uint32 *)p;
			break;
		default:
			pixel = 0;
			break;
	}

	return pixel;
}

