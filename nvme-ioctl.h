/*
 * Code taken from nvme-cli repository
 */

#ifndef _NVME_LIB_H
#define _NVME_LIB_H

#include <linux/types.h>
#include "linux/nvme_ioctl.h"

/* I/O commands */
enum nvme_opcode {
	nvme_cmd_flush			= 0x00,
	nvme_cmd_write			= 0x01,
	nvme_cmd_read			= 0x02,
	nvme_cmd_fs_open		= 0x03,
	nvme_cmd_write_uncor	= 0x04,
	nvme_cmd_compare		= 0x05,
	nvme_cmd_write_zeroes	= 0x08,
	nvme_cmd_dsm			= 0x09,
	nvme_cmd_verify			= 0x0c,
	nvme_cmd_resv_register	= 0x0d,
	nvme_cmd_resv_report	= 0x0e,
	nvme_cmd_resv_acquire	= 0x11,
	nvme_cmd_resv_release	= 0x15,
};

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
