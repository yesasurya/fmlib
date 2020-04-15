#ifndef _FM_LIB_H
#define _FM_LIB_H

char* fm_device_name;
int fm_device_fd;

int open_session();
int close_session();

int fm_open(char *fm_file_name);
int fm_write(int fm_fd, const void *buf, size_t count);
int fm_read(int fm_fd, void *buf, size_t count);

#endif /* _NVME_LIB_H */
