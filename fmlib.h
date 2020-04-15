#ifndef _FM_LIB_H
#define _FM_LIB_H

char* fm_device_name = "/dev/nvme0n1";
int fm_device_fd;

int open_session();
int close_session();

#endif /* _NVME_LIB_H */
