#ifndef _FM_LIB_H
#define _FM_LIB_H

char* device_name = "/dev/nvme0n1";
int device_fd;

int open_session();
int close_session();

#endif /* _NVME_LIB_H */
