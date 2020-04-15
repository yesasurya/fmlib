#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "nvme-ioctl.h"

int main() {
	char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int str_len = 512;
	int slba = 0x20;

	struct nvme_user_io io = {
		.opcode		= nvme_cmd_write,
		.flags		= 0,
		.control	= 0,
		.nblocks	= 0,
		.rsvd		= 0,
		.metadata	= 0,
		.addr		= str,
		.slba		= slba,
		.dsmgmt		= 0,
		.reftag		= 0,
		.appmask	= 0,
		.apptag		= 0,
	};
	if (ioctl(3, NVME_IOCTL_SUBMIT_IO, &io) != 0) {
		printf("Error. %s\n", strerror(errno));
	} else {
		printf("Success\n");	
	}

	return 0;
}
