#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fmlib.h"

int open_session() {
	fm_device_fd = open(fm_device_name, O_RDWR, S_IRWXU);
	if (fm_device_fd == -1) {
		printf("Cannot device file: %s\n", strerror(errno));
		abort();
	}
	return fm_device_fd;
}

int close_session() {
	int ret = close(fm_device_fd);
	if (ret == -1) {
		printf("Cannot close device file: %s\n", strerror(errno));
	}
	return ret;
}
