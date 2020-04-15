#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fmlib.h"

extern char *device_name;
extern int device_fd;

int open_session() {
	device_fd = open(device_name, O_RDWR, S_IRWXU);
	if (device_fd == -1) {
		printf("Cannot device file: %s\n", strerror(errno));
		abort();
	}
	return device_fd;
}

int close_session() {
	int ret = close(device_fd);
	if (ret == -1) {
		printf("Cannot close device file: %s\n", strerror(errno));
	}
	return ret;
}
