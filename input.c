#include "includes.h"
#include "input.h"

bool input_process_keyboard(SDL_Event *event);

bool input_process(void) {
	SDL_Event event;
	bool return_value = true;

	while( SDL_PollEvent(&event) ) {
		switch(event.type) {
			case SDL_KEYDOWN:
				/* Do not set return_value to true if it has been set to false! */
				/* We may run input_process_keyboard() numerous times before returning ... */
				if( input_process_keyboard(&event) == false )
					return_value = false;
				break;
			default:
				break;
		}
	}

	return(return_value);
}

bool input_process_keyboard(SDL_Event *event) {
	switch(event->key.keysym.sym) {
		case SDLK_ESCAPE:
			return(false);
			break;
		default:
			break;
	}

	return(true);
}

