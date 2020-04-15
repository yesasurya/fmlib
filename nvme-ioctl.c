/*
 * Code taken from nvme-cli repository
 */

#include <assert.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <errno.h>

#include <getopt.h>
#include <fcntl.h>
#include <inttypes.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include "nvme-ioctl.h"

int nvme_io(int fd, __u8 opcode, __u64 slba, __u16 nblocks, __u16 control,
	    __u32 dsmgmt, __u32 reftag, __u16 apptag, __u16 appmask, void *data,
	    void *metadata)
{
	struct nvme_user_io io = {
		.opcode		= opcode,
		.flags		= 0,
		.control	= control,
		.nblocks	= nblocks,
		.rsvd		= 0,
		.metadata	= (__u64)(uintptr_t) metadata,
		.addr		= (__u64)(uintptr_t) data,
		.slba		= slba,
		.dsmgmt		= dsmgmt,
		.reftag		= reftag,
		.appmask	= appmask,
		.apptag		= apptag,
	};
	return ioctl(fd, NVME_IOCTL_SUBMIT_IO, &io);
}

int nvme_read(int fd, __u64 slba, __u16 nblocks, __u16 control, __u32 dsmgmt,
	      __u32 reftag, __u16 apptag, __u16 appmask, void *data,
	      void *metadata)
{
	return nvme_io(fd, nvme_cmd_read, slba, nblocks, control, dsmgmt,
		       reftag, apptag, appmask, data, metadata);
}

int nvme_write(int fd, __u64 slba, __u16 nblocks, __u16 control, __u32 dsmgmt,
	       __u32 reftag, __u16 apptag, __u16 appmask, void *data,
	       void *metadata)
{
	return nvme_io(fd, nvme_cmd_write, slba, nblocks, control, dsmgmt,
		       reftag, apptag, appmask, data, metadata);
}

int nvme_compare(int fd, __u64 slba, __u16 nblocks, __u16 control, __u32 dsmgmt,
		 __u32 reftag, __u16 apptag, __u16 appmask, void *data,
		 void *metadata)
{
	return nvme_io(fd, nvme_cmd_compare, slba, nblocks, control, dsmgmt,
		       reftag, apptag, appmask, data, metadata);
}
