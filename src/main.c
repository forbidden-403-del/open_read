#include "include/mstd.h"

int stringlen(char *str) {
	int i = 0;
	while(str[i])
		i++;
	return i;
}

void print(char *str) {
	int len = stringlen(str);
	sysWrite(1, str, len);
}

void _start() {
	char    buf[BUF_SZ];
	int		fd;
	fd = sysOpen("data.txt", 0);
	if (fd != -1) {
		ssize_t num_read = sysRead(fd, buf, BUF_SZ - 1);
		while (num_read > 0) {
			buf[num_read] = '\0';
			print(buf);
			num_read = sysRead(fd, buf, BUF_SZ - 1);
		}
	} else {
		print("Error opening file");
		sysExit(-1);
	}
	sysClose(fd);
	sysExit(0);
}
