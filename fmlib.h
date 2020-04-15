#ifndef _FM_LIB_H
#define _FM_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/types.h>
#include <stdint.h>

#include "nvme-ioctl.h"

char* fm_device_name;
int fm_device_fd;

int open_session();
int close_session();

int fm_open(char *fm_file_name);
int fm_write(int fm_fd, const void *buf, size_t count);
int fm_read(int fm_fd, void *buf, size_t count);
int submit_nvme_command(uint8_t opcode, uint64_t slba, void *data);

#endif /* _NVME_LIB_H */
