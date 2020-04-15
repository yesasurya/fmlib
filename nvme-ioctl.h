/*
 * Code taken from nvme-cli repository
 */

#ifndef _NVME_LIB_H
#define _NVME_LIB_H

#include <linux/types.h>
#include "linux/nvme_ioctl.h"
#include "linux/nvme.h"

int nvme_io(int fd, __u8 opcode, __u64 slba, __u16 nblocks, __u16 control,
	      __u32 dsmgmt, __u32 reftag, __u16 apptag,
	      __u16 appmask, void *data, void *metadata);

int nvme_read(int fd, __u64 slba, __u16 nblocks, __u16 control,
	      __u32 dsmgmt, __u32 reftag, __u16 apptag,
	      __u16 appmask, void *data, void *metadata);

int nvme_write(int fd, __u64 slba, __u16 nblocks, __u16 control,
	       __u32 dsmgmt, __u32 reftag, __u16 apptag,
	       __u16 appmask, void *data, void *metadata);

int nvme_compare(int fd, __u64 slba, __u16 nblocks, __u16 control,
		 __u32 dsmgmt, __u32 reftag, __u16 apptag,
		 __u16 appmask, void *data, void *metadata);

#endif /* _NVME_LIB_H */
