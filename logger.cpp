#include "includes.h"
#include "logger.h"

void logger(enum _logger_level level, const char *msg, ...) {
	va_list args;

	switch(level) {
		case INFO:
			printf("INFO: ");
			break;
		case DEBUG:
			printf("DEBUG: ");
			break;
		default:
			printf("Unknown level: ");
			break;
	};

	va_start( args, msg );
	vprintf( msg, args );
	va_end( args );
	printf("\n");

	fflush(stdout);
}

