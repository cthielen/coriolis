#ifndef __H_LOGGER__
#define __H_LOGGER__

enum _logger_level {
	INFO,
	DEBUG,
	WARN,
	ERROR,
	FATAL
};

void logger(enum _logger_level level, char *msg, ...);

#endif /* __H_LOGGER_ */

