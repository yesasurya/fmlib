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
	fm_device_name = "/dev/nvme0n1";
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

int fm_open(char *fm_file_name) {
	submit_nvme_command(nvme_cmd_write, 0x0, fm_file_name);
}

int fm_write(int fm_fd, const void *buf, size_t count) {

}

int fm_read(int fm_fd, void *buf, size_t count) {

}

int submit_nvme_command(__u8 opcode, __u64 slba, void *data) {
	struct nvme_user_io io = {
		.opcode		= opcode,
		.flags		= 0,
		.control	= 0,
		.nblocks	= 0,
		.rsvd		= 0,
		.metadata	= 0,
		.addr		= data,
		.slba		= slba,
		.dsmgmt		= 0,
		.reftag		= 0,
		.appmask	= 0,
		.apptag		= 0,
	};
	int ret = ioctl(fm_device_fd, NVME_IOCTL_SUBMIT_IO, &io);
	if (ret != 0) {
		printf("Cannot submit NVME command: %s\n", strerror(errno));
		abort();
	}
	return ret;
}
