#include "engine.h"
#include "includes.h"
#include "input.h"
#include "video.h"

/* Runs the main loop */
void engine_run(void) {
	bool running = true;

	while(running) {
		/* Process input */
		running = input_process();

		/* Update logic */


		/* Erase and draw */
		video_blank_screen();
		video_sync();
	}
}

